#include <iostream>
#include <vector>
#include <limits>
#include <boost/range/irange.hpp>
#include <boost/range/adaptors.hpp>
#include <bitset>

using namespace std;
using namespace boost;
using uint = unsigned int;
using ll = long long int;
using ull = unsigned long long int;

void comb(int N, int K)
{
    std::string bitmask(K, 1); // K leading 1's
    bitmask.resize(N, 0); // N-K trailing 0's

    // print integers and permute bitmask
    do {
        for (int i = 0; i < N; ++i) // [0..N-1] integers
        {
            if (bitmask[i]){std::cout << " " << 1;}
            else {cout << " " << 0;}
        }
        std::cout << std::endl;
    } while (std::prev_permutation(bitmask.begin(), bitmask.end()));
}

void comb(){
    vector<bool> bitmask(5, false);
    for (auto &&i: irange(0U, 3U)){
        bitmask.at(i) = true;
    }
    do {
        for (auto &&j: irange(0U, 5U)) // [0..N-1] integers
        {
            cout << bitmask.at(j) << " ";
        }
        cout << endl;
    } while (std::prev_permutation(bitmask.begin(), bitmask.end()));
}

int main()
{
    comb();
    return 0;
}
