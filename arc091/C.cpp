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
    ull N, M;
    cin >> N >> M;
    ull ura;
    if (N>=2 && M>=2){
        ura  = (N-2) * (M-2);
    } else if (N == 1 && M >= 2){
        ura = M-2;
    } else if (M==1 && N>= 2){
        ura = N-2;
    } else{
        ura = 1;
    }
    cout << ura << endl;
    return 0;
}