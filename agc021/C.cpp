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


enum Symbol {
    uncovered, horz_left, horz_right, vert_up, vert_down
};

void printer(const ull N, const ull M, const vector<vector<Symbol>> &map) {
    for (auto &&vert: irange(0ULL, N)) {
        for (auto &&horz: irange(0ULL, M)) {
            char c{};
            switch (map.at(vert).at(horz)) {
                case uncovered:
                    c = '.';
                    break;
                case horz_left:
                    c = '<';
                    break;
                case horz_right:
                    c = '>';
                    break;
                case vert_up:
                    c = '^';
                    break;
                case vert_down:
                    c = 'v';
                    break;
            }
            cout << c;
        }
        cout << endl;
    }
}

bool checker(const ull &N, const ull &M, const ull &A, const ull &B, const vector<vector<Symbol>> &map) {
    // quantitative check
    uint hl{0U}, hr{0U}, vu{0U}, vd{0U};
    for (auto &&vert: irange(0ULL, N)) {
        for (auto &&horz: irange(0ULL, M)) {
            switch (map.at(vert).at(horz)) {
                case uncovered:
                    break;
                case horz_left:
                    hl++;
                    break;
                case horz_right:
                    hr++;
                    break;
                case vert_up:
                    vu++;
                    break;
                case vert_down:
                    vd++;
                    break;
            }
        }
    }
    if (!(hl == A && hr == A && vu == B && vd == B)) { return false; }
    // consistency check
    for (auto &&vert: irange(0ULL, N)) {
        for (auto &&horz: irange(0ULL, M)) {
            switch (map.at(vert).at(horz)) {
                case uncovered:
                    break;
                case horz_left:
                    if (horz + 1 >= M || map.at(vert).at(horz + 1) != horz_right) { return false; };
                    break;
                case horz_right:
                    if (horz - 1 < 0 || map.at(vert).at(horz - 1) != horz_left) { return false; };
                    break;
                case vert_up:
                    if (vert + 1 >= N || map.at(vert + 1).at(horz) != vert_down) { return false; };
                    break;
                case vert_down:
                    if (vert + 1 < 0 || map.at(vert - 1).at(horz) != vert_up) { return false; };
                    break;
            }
        }
    }
    return true;
}

int main() {
    for (auto N: irange(2ULL, 100ULL)) {
        for (auto M: irange(2ULL, 100ULL)) {
            for (auto A: irange(0ULL, 30ULL)) {
                for (auto B: irange(0ULL, 30ULL)) {

                    ull square_vert = N / 2; // number of tiles / 2
                    ull square_horz = M / 2; // number of tiles / 2
                    ull squares_map =
                            ((ull) square_vert) * ((ull) square_horz); // number of panel consumed in square manner
                    auto is_remaining_horz = (bool) (N % 2);
                    auto is_remaining_vert = (bool) (M % 2);
                    ull remaining_horz = is_remaining_horz ? (M / 2) : 0;
                    ull remaining_vert = is_remaining_vert ? (N / 2) : 0;
                    if (remaining_horz > A) {
                        remaining_horz = A;
                    }
                    if (remaining_vert > B) {
                        remaining_vert = B;
                    }
                    ull horz_for_square = A - remaining_horz;
                    ull vert_for_square = B - remaining_vert;
                    ull horz_square = (horz_for_square + 1) / 2;
                    ull vert_square = (vert_for_square + 1) / 2;
                    ull squares_panel = horz_square + vert_square;
                    if (squares_panel > squares_map && N*M > 2*(A+B)) {
                        cout << " 横: " << M  << "縦: " << N << " 横長: " << A << " 縦長: " << B << " 空き: " << (int)(N*M)-(int)(2*(A+B)) << " NO" << endl;
//                    } else {
////                        cout << "YES" << endl;
//                        vector<vector<Symbol>> map(N, vector<Symbol>(M, uncovered));
//                        ull horz_pos{0};
//                        ull vert_pos{0};
//                        for (auto &&i: irange(0ULL, squares_panel)) {
//                            if (horz_pos + 2 > M) {
//                                horz_pos = 0;
//                                vert_pos += 2;
//                            }
//                            if (horz_square) {
//                                if (horz_for_square >= 2) {
//                                    map.at(vert_pos).at(horz_pos) = horz_left;
//                                    map.at(vert_pos).at(horz_pos + 1) = horz_right;
//                                    map.at(vert_pos + 1).at(horz_pos) = horz_left;
//                                    map.at(vert_pos + 1).at(horz_pos + 1) = horz_right;
//                                    horz_square--;
//                                    horz_for_square -= 2;
//                                } else {
//                                    map.at(vert_pos).at(horz_pos) = horz_left;
//                                    map.at(vert_pos).at(horz_pos + 1) = horz_right;
//                                    horz_square--;
//                                    horz_for_square -= 1;
//                                }
//                            } else {
//                                if (vert_for_square >= 2) {
//                                    map.at(vert_pos).at(horz_pos) = vert_up;
//                                    map.at(vert_pos + 1).at(horz_pos) = vert_down;
//                                    map.at(vert_pos).at(horz_pos + 1) = vert_up;
//                                    map.at(vert_pos + 1).at(horz_pos + 1) = vert_down;
//                                    vert_square--;
//                                    vert_for_square -= 2;
//                                } else {
//                                    map.at(vert_pos).at(horz_pos) = vert_up;
//                                    map.at(vert_pos + 1).at(horz_pos) = vert_down;
//                                    vert_square--;
//                                    vert_for_square -= 1;
//                                }
//                            }
//                            horz_pos += 2;
//                        }
//                        for (auto &&i: irange(0ULL, remaining_horz)) {
//                            map.at(N - 1).at(i * 2) = horz_left;
//                            map.at(N - 1).at(i * 2 + 1) = horz_right;
//                        }
//                        for (auto &&i: irange(0ULL, remaining_vert)) {
//                            map.at(i * 2).at(M - 1) = vert_up;
//                            map.at(i * 2 + 1).at(M - 1) = vert_down;
//                        }
//                        if (!checker(N, M, A, B, map)){
//                            cout << "N: " << N << " M: " << M << " A: " << A << " B: " << B << " check: "
//                                 << checker(N, M, A, B, map) << endl;
//                        }
                    }
                }
            }
        }
    }
    return 0;
}