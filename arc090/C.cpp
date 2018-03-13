#include <iostream>
#include <vector>
#include <limits>
#include <boost/range/irange.hpp>
#include <boost/range/adaptor/reversed.hpp>
#include <typeinfo>
#include <cxxabi.h>

using namespace std;
using namespace boost;
using namespace boost::adaptors;
using uint = unsigned int;
using ll = long long int;
using ull = unsigned long long int;

// メモリリークするので要改良
char* demangle(const char *demangled)
{
    int status;
    return abi::__cxa_demangle(demangled, 0, 0, &status);
}


int main() {
    auto func = [](uint a, uint b){return a + b;};
    auto func2 = [](uint a, uint b){return a - b;};
    struct {
        uint operator () (uint a, uint b){
            return a * b;
        }
    } func3;
    cout << demangle(typeid(func).name()) << endl;
    cout << demangle(typeid(func2).name()) << endl;
    cout << demangle(typeid(func3).name()) << endl;
    return 0;
}