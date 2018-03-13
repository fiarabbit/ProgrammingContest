#include <iostream>
#include <vector>
#include <boost/range/irange.hpp>

using  namespace std;
using namespace boost;

int main() {
    using uint = unsigned int;
    uint N;
    cin >> N;
    vector<uint> as(N, 0), bs(N, 0);
    for(auto i: irange((uint)0, N)){
        cin >> as.at(i);
    }
    for(auto i: irange((uint)0, N)){
        cin >> bs.at(i);
    }
    long long int sum{0};
    for(auto i: irange((uint)0, N)){
        if(as.at(i) > bs.at(i)){
            sum -= (as.at(i)-bs.at(i));
        } else {
            sum += (bs.at(i) - as.at(i))/2;
        }
    }
    if (sum >= 0){
        cout << "Yes";
    } else {
        cout << "No";
    }
    return 0;
}