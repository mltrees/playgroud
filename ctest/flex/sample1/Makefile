TARGET=a.out
CFLAGS=-g -O0 -std=c++11
#CFLAGS=-g -O0
LIB_NAME=-lfl
LIB_DIR=-L.
INC_DIR=-I.
CXX=g++
#SRC=Serv.cpp student_types.cpp student_constants.cpp Serv_server.skeleton.cpp
SRC=lex.yy.c

all:$(TARGET)

$(TARGET): $(SRC)

	$(CXX) $(CFLAGS) $^ $(INC_DIR) $(LIB_DIR) $(LIB_NAME) -o $@

clean:
	$(RM) *.o  *.o $(TARGET)

