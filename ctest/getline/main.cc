/*************************************************************************
    > File Name: main.cc
    > Author: zml
    > Mail: zhangmaolin1@jd.com 
    > Created Time: 2018年04月06日 星期五 23时02分57秒
 ************************************************************************/

#include <iostream>
#include <sstream>
#include <memory>
#include <string>


int main(int argc, char** argv) {
    std::string name;
    std::cout << "Please, enter your full name";
    std::getline(std::cin, name);
    std::cout << "Hello, " << name << "!\n";

    return 0;
}
