#include <iostream>
#include <vector>
#include <limits>
#include <boost/range/irange.hpp>
#include <boost/range/adaptors.hpp>
#include <string>

using namespace std;
using namespace boost;
using uint = unsigned int;
using ll = long long int;
using ull = unsigned long long int;

int main() {
    string s;
    cin >> s;
    if (s.substr(0, 3)=="yah" && s[3]==s[4]){
        cout << "YES";
    }else{
        cout << "NO";
    }
    return 0;
}