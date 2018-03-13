#include <iostream>
#include <vector>
#include <limits>
#include <boost/range/irange.hpp>
#include <boost/range/adaptors.hpp>
#include <algorithm>

using namespace std;
using namespace boost;
using uint = unsigned int;
using ll = long long int;
using ull = unsigned long long int;

constexpr uint N_max = 18;

int main() {
    uint N;
    cin >> N;
    vector<ull> xs(N, 0), cs(N, 0), vs(N, 0);
    for (auto &&i: irange(0U, N)) {
        cin >> xs.at(i);
    }
//    for (auto &&i: irange(0U, N)) {
//        cout << xs.at(i) << endl;
//    }
    for (auto &&i: irange(0U, N)) {
        cin >> cs.at(i);
    }
    for (auto &&i: irange(0U, N)) {
        cin >> vs.at(i);
    }
    vector<ull> moneys(N + 1, 0);
    for (auto &&i: irange(1U, N + 1)) {
        moneys.at(i) = moneys.at(i - 1) + xs.at(i - 1);
    }
//    for (auto &&i: irange(0U, N+1)){
//        cout << "turn: " << i << " money: " << moneys.at(i) << endl;
//    }
    uint num_states{1};
    for (auto &&i: irange(0U, N)) {
        num_states *= 2; // 2^N
    }
    // 各moneyに対して，stateで購入できる最大価値を計算していく
    vector<vector<ull>> values_money_state(N + 1, vector<ull>(num_states, numeric_limits<ull>::max()));
    for (auto &&i: irange(0U, N + 1)) {
        ull money = moneys.at(i);
        for (auto &&j: irange(0U, num_states)) {
            bitset<N_max> state{j};
            ull cost_all{0};
            ull value_all{0};
            for (auto &&k: irange(0U, N)) {
                if (state[k]) {
                    cost_all += cs.at(k);
                    value_all += vs.at(k);
                }
            }
//            cout << "money: " << money << " cost_all: " << cost_all << endl;
            if (cost_all <= money) {
                values_money_state.at(i).at(j) = value_all;
            } else {
                ull max_value_substate{0};
                for (auto &&k: irange(0U, N)){
                    if (state[k]){
                        bitset<N_max> substate{state};
                        substate.reset(k);
                        max_value_substate = max(max_value_substate, values_money_state.at(i).at(substate.to_ulong()));
                    }
                }
                values_money_state.at(i).at(j) = max_value_substate;
            }
        }
    }
//    for (auto &&i: irange(0U, N+1)){
//        for (auto &&j: irange(0U, num_states)){
//            bitset<N_max> state{j};
//            cout << "money: " << moneys.at(i) << " state: " << state << " available: " << values_money_state.at(i).at(j) << endl;
//        }
//    }

    vector<ull> maximum_value_earnable(num_states, numeric_limits<ull>::min());
    for (auto &&i: irange(0U, num_states)){
        bitset<N_max> state{i};
        if (i==0){
            maximum_value_earnable.at(i) = 0;
        } else {
            ull min_value_substate{numeric_limits<ull>::max()};
            for (auto &&j: irange(0U, N)){
                if (state[j]){
                    bitset<N_max> substate = state;
                    substate.reset(j);
                    min_value_substate = min(min_value_substate, maximum_value_earnable.at(substate.to_ulong()));
                }
            }
            uint turn{N-state.count()};
//            cout << "state: " << state <<  " turn: " << turn << " afford: " << values_money_state.at(turn).at(state.to_ulong()) << " min_substate: " << min_value_substate << endl;
            maximum_value_earnable.at(i) = max(values_money_state.at(turn).at(state.to_ulong()), min_value_substate);
        }
    }
    cout << maximum_value_earnable.at(num_states-1);
    return 0;
}