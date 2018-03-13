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
    ull N;
    cin >> N;
    ull counter{0}, k{1};
    while (true){
        if (N < k*10){
            break;
        } else {
            k *= 10;
            counter += 1;
        }
    }
    ull maximum = (N / k)*k;
    ull remmax = k - 1;

    if (N-maximum == remmax){
        cout << N/k+counter*9 << endl;
    } else {
        cout << N/k+counter*9 - 1 << endl;
    }

    return 0;
}