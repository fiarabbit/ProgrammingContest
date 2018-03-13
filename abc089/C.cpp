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
    ull N;
    cin >> N;
    vector<ull> count(5U, 0);
    for (auto &&i: irange(0U, (uint)N)) {
        string s;
        cin >> s;
        char c;
        c = s.at(0);
        switch (c){
            case 'M':
                count.at(0)++;
                break;
            case 'A':
                count.at(1)++;
                break;
            case 'R':
                count.at(2)++;
                break;
            case 'C':
                count.at(3)++;
                break;
            case 'H':
                count.at(4)++;
                break;
            default:
                break;
        }
    }
    ull c0 = count.at(0);
    ull c1 = count.at(1);
    ull c2 = count.at(2);
    ull c3 = count.at(3);
    ull c4 = count.at(4);
    cout << c0 * c1 * c2 + c0 * c1 * c3 + c0 * c1 * c4 + c0 * c2 * c3 + c0 * c2 * c4 + c0 * c3 * c4 + c1*  c2 * c3 + c1* c2 * c4 + c1* c3* c4 + c2* c3 * c4;


    return 0;
}