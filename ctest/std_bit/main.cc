// ifstream constructor.
#include <iostream>     // std::cout
#include <sstream>
#include <bitset>


int main () {
    std::bitset<100> f;
    f.set(0);
    f.set(1);
    f.set(2);
    f.set(65);
    f.set(66);
    f.test(0);


    return 0;
}
