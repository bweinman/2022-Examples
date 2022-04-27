//  narrowing.cpp
//  as of 2022-04-20 bw [bw.org]

#include <print>
#include <typeinfo>

using std::print;

int main() {
    unsigned i = -47;   // narrowing conversion
    print("i is {}\n", i);
    print("typeid: {}\n", typeid(i).name());
}
