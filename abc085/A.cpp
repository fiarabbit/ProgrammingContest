#include <iostream>
#include <vector>
#include <boost/range/irange.hpp>
#include <string>
using  namespace std;
using namespace boost;

int main() {
    string s;
    cin >> s;
    s[3] = *"8";
    cout << s;
    return 0;
}