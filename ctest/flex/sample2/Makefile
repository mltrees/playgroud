TARGET=a.out
CFLAGS=-g -O0 -std=c++11
#CFLAGS=-g -O0
LIB_NAME=-lfl
LIB_DIR=-L.
INC_DIR=-I.
CXX=g++
#SRC=Serv.cpp student_types.cpp student_constants.cpp Serv_server.skeleton.cpp
SRC=fb1-5.l fb1-5.y

all:$(TARGET)

$(TARGET): $(SRC)
	bison -d fb1-5.y
	flex fb1-5.l
	cc -g -O0 -o $@ fb1-5.tab.c lex.yy.c -lfl

#	$(CXX) $(CFLAGS) $^ $(INC_DIR) $(LIB_DIR) $(LIB_NAME) -o $@

clean:
	$(RM) *.o  *.o $(TARGET) fb1-5.tab.c lex.yy.c fb1-5.tab.h

