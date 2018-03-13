#include <iostream>
#include <vector>
#include <boost/range/irange.hpp>
#include <string>
#include <array>

using namespace std;
using namespace boost;
using uint = unsigned int;
using ll = long long int;
using ull = unsigned long long int;

int main() {
    char c0, c1, c2, c3;
        cin >> c0 >> c1 >> c2 >> c3;
        if (c1 == c2){
            if ((c0 == c1)||(c2 == c3)){
                cout << "Yes" << endl;
                return 0;
            }else{
                cout << "No" << endl;
            }
        } else {
            cout << "No" << endl;
            return 0;
        }
}