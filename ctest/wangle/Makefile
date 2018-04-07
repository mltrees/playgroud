SERVER_TARGET=server.out
CLIENT_TARGET=client.out
CFLAGS=-g -O0 -std=c++14
LIB_NAME=-lwangle -lfolly -lglog -lgflags -levent_openssl -lssl -lcrypto -lpthread
LIB_DIR=-L. -L/home/zhangmaolin/opensrc/proxygen-debug/proxygen/wangle/wangle/build/lib
INC_DIR=-I. -I/home/zhangmaolin/usr/local/include
CXX=g++
SERVER_SRC=server.cc
CLIENT_SRC=client.cc

.PHONY: all server client clean

all:$(SERVER_TARGET) $(CLIENT_TARGET)

server:$(SERVER_TARGET)

client:$(CLIENT_TARGET)

$(SERVER_TARGET):$(SERVER_SRC)
	$(CXX) $(CFLAGS) $^ $(INC_DIR) $(LIB_DIR) $(LIB_NAME) -o $@

$(CLIENT_TARGET):$(CLIENT_SRC)
	$(CXX) $(CFLAGS) $^ $(INC_DIR) $(LIB_DIR) $(LIB_NAME) -o $@

clean:
	$(RM) *.o *.O $(SERVER_TARGET) $(CLIENT_TARGET)
