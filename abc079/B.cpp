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
    array<ull, 87> answer{};
    for (auto i: irange((unsigned int) 0, (uint)87)){
        if (i == 0){
            answer.at(i) = 2;
        } else if (i == 1){
            answer.at(i) = 1;
        } else {
            answer.at(i) = answer.at(i-1) + answer.at(i-2);
        }
    }

    uint N;
    cin >> N;
    cout << answer.at(N);
    return 0;

}