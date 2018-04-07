/*************************************************************************
    > File Name: main.cc
    > Author: zml
    > Mail: zhangmaolin1@jd.com 
    > Created Time: 2018年04月06日 星期五 23时02分57秒
 ************************************************************************/

#include <gflags/gflags.h>
#include <wangle/bootstrap/ServerBootstrap.h>
#include <wangle/channel/AsyncSocketHandler.h>
#include <wangle/codec/LineBasedFrameDecoder.h>
#include <wangle/codec/StringCodec.h>
#include <iostream>
#include <sstream>
#include <memory>

using namespace folly;
using namespace wangle;


using namespace std;

DEFINE_int32(port, 8080, "echo server port");

typedef Pipeline<IOBufQueue&, std::string> EchoPipeline;

class EchoHandler : public HandlerAdapter<std::string> {
public:
    virtual void read(Context* ctx, std::string msg) override {
        std::cout << "handling " << msg << std::endl;
        write(ctx, msg + "reply \r\n");
    }
};

// where we define the chain handlers for each message received
class EchoPipelineFactory : public PipelineFactory<EchoPipeline> {
public:
    EchoPipeline::Ptr newPipeline(std::shared_ptr<AsyncTransportWrapper> sock) {
        auto pipeline = EchoPipeline::create();
        pipeline->addBack(AsyncSocketHandler(sock));
        pipeline->addBack(LineBasedFrameDecoder(8192));
        pipeline->addBack(StringCodec());
        pipeline->addBack(EchoHandler());
        pipeline->finalize();
        return pipeline;
    }
};



int main(int argc, char** argv) {
    gflags::ParseCommandLineFlags(&argc, &argv, true);

    ServerBootstrap<EchoPipeline> server;
    server.childPipeline(std::make_shared<EchoPipelineFactory>());
    server.bind(FLAGS_port);
    server.waitForStop();

    return 0;
}
