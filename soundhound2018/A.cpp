#include <iostream>
#include <vector>
#include <boost/range/irange.hpp>
#include <string>

using namespace std;
using namespace boost;
using uint = unsigned int;
using ll = long long int;
using ull = unsigned long long int;

int main() {
    string X, Y;
    cin >> X >> Y;
    if (X.at(0) ==  (* "S") && Y.at(0) == (*"H")) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}