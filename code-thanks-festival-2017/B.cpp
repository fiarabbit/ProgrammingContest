#include <iostream>
#include <vector>
#include <limits>
#include <boost/range/irange.hpp>
#include <boost/range/adaptors.hpp>
#include <string>
#include <algorithm>
#include <deque>

using namespace std;
using namespace boost;
using uint = unsigned int;
using ll = long long int;
using ull = unsigned long long int;

int main() {
    string s;
    cin >> s;
    uint l = s.size();
    // 文字上で折り返す場合
    // c_iで折り返す
    // 左側にi文字，右側にl-i-1文字になる
    // 右側にしか連結させてはいけないので，i >= l-i-1
    uint shortest_mojijo{numeric_limits<uint>::max()};
    for (auto &&i: irange((l-1)/2, l)){
        bool flag{true};
        for (auto &&j: irange(0U, l-i-1)){
            if (!s.at(i-j) == s.at(i+j)){
                flag=false;
                break;
            }
        }
        if (flag){
            shortest_mojijo = 2*i- l + 1;
            break;
        }
    }
    // 文字間で折り返す場合
    // c_iとc_i+1の間で折り返す
    // 左側にi+1文字，右側にl-i-1文字残る
    //右側にしか連結させてはいけない
    uint shortest_mojikan{numeric_limits<uint>::max()};
    for (auto &&i: irange((l-2)/2, l)){
        bool flag{true};
        for (auto &&j: irange(1U, l-i)){
            if(!s.at(i-j+1) == s.at(i+j)){
                flag=false;
                break;
            }
        }
        if (flag){
            shortest_mojikan = 2*i - l + 2;
            break;
        }
    }
    cout << min(shortest_mojijo, shortest_mojikan) << endl;
    return 0;
}