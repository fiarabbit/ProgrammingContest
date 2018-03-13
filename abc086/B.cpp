#include <iostream>
#include <cmath>
#include <boost/range/irange.hpp>

using namespace std;
using namespace boost;

int main() {
    string a, b;
    cin >> a >> b;
    string c{a + b};
    int d{stoi(c)};
    for (auto i: irange(0, 317)) {
        if (d == pow(i, 2)) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}