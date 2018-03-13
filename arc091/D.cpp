#include <iostream>
#include <vector>
#include <limits>
#include <boost/range/irange.hpp>
#include <boost/range/adaptors.hpp>

using namespace std;
using namespace boost;
using uint = unsigned int;
using ll = long long int;
using ull = unsigned long long int;

int main() {
    ll N, K;
    cin >> N >> K;
    ll count{0};
    ll c{0};
    for (auto &&b: irange(max(K, 1LL), N+1)){
        count += (b-K) * (N/b) + max(0LL, N % b - K + 1);
    }
    if (K==0LL){
        count = count - N;
    }
    cout << count << endl;
    return 0;
}