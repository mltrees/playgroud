TARGET=a.out
CFLAGS=-g -O0 -std=c++14
LIB_NAME=-lfolly -lglog -lpthread
LIB_DIR=-L. -L/home/zhangmaolin/usr/local/lib
INC_DIR=-I. -I/home/zhangmaolin/usr/local/include
CXX=g++
SRC=main.cc

all:$(TARGET)

$(TARGET):$(SRC)
	$(CXX) $(CFLAGS) $^ $(INC_DIR) $(LIB_DIR) $(LIB_NAME) -o $@

clean:
	$(RM) *.o *.O $(TARGET)
