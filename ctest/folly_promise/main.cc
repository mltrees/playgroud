/*************************************************************************
    > File Name: main.cc
    > Author: zml
    > Mail: zhangmaolin1@jd.com 
    > Created Time: 2018年04月06日 星期五 23时02分57秒
 ************************************************************************/

#include <chrono>
#include <exception>
#include <iostream>
#include <sstream>
#include <memory>
#include <folly/futures/Future.h>
#include <folly/futures/ThreadWheelTimekeeper.h>
#include <folly/Singleton.h>
#include <folly/init/Init.h>

using folly::Promise;
using folly::Future;
using folly::Try;
using namespace std;

class A {
public:
    A() {
        std::cout << "construct A" << std::endl;
    }
    A (const A& c) {
        std::cout << "copy construct A" << std::endl;
    }
    A (const A&& c) {
        std::cout << "move construct A" << std::endl;
    }
    A& operator=(const A& other) {
        std::cout << "assign construct A" << std::endl;
    }
    ~A() {
        std::cout << "deconstruct A" << std::endl;
    }
};
std::thread gt;


void run() {
    std::cout << "making Promise" << std::endl;
    std::shared_ptr<Promise<A>> p = std::make_shared<Promise<A>>();
    std::cout << "after make shared A" << std::endl;
    Future<A> f = p->getFuture();
    std::cout << "after get future A" << std::endl;
    f.within(std::chrono::milliseconds(200)).then([](Try<A> t) {
            if (t.hasException()) {
                std::cout << "catch exception" << std::endl;
                return;
            }

            std::cout << "run into lambda callback" << std::endl;
            });
    cout << "Future chain make" << endl;
    auto p1 = p.get();

    std::thread t([p]{
            //sleep(1);
            cout << "fufilling Promise" << endl;
            A a;
            p->setValue(std::move(a));
            // p->setException(std::runtime_error("zml set exception"));
            cout << "Promise fulfilled" << endl;
            });
    gt = std::move(t);

}


int main(int argc, char** argv) {
    folly::init(&argc, &argv);
    // folly::Singleton<folly::ThreadWheelTimekeeper> timekeeperSingleton_;
    run();

     gt.join();

    return 0;
}
