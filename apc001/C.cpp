#include <iostream>
#include <vector>
#include <boost/range/irange.hpp>


using namespace std;
using namespace boost;
using uint = unsigned int;
using ll = long long int;
using ull = unsigned long long int;

enum ChairCondition {
    vacant, male, female
};

struct Range {
    uint start_index;
    uint end_index;
    ChairCondition start_condition;
    ChairCondition end_condition; // conditions[end_index]
    Range(uint _start_index, uint _end_index, ChairCondition _start_condition, ChairCondition _end_condition) :
            start_index(_start_index),
            end_index(_end_index),
            start_condition(_start_condition),
            end_condition(_end_condition) {}
};

ChairCondition cnv(const string &s);

ChairCondition cnv(const string &s) {
    if (s == "Vacant") {
        return ChairCondition::vacant;
    } else if (s == "Male") {
        return ChairCondition::male;
    } else {
        return ChairCondition::female;
    }
}

void split_range(Range &r) {
    uint query_index = (r.start_index + r.end_index) / 2;
    cout << query_index << endl;
    string s;
    cin >> s;
    ChairCondition c;
    if (s == "Vacant") {
        exit(0);
    } else if (s == "Male") {
        c = ChairCondition::male;
    } else {
        c = ChairCondition::female;
    }
    uint left_length{query_index - r.start_index + 1};
    if ((left_length % 2 == 0) != (r.start_condition == c)) {
        r.start_index = query_index;
        r.start_condition = c;
    } else {
        r.end_index = query_index;
        r.end_condition = c;
    }
}

int main() {
    uint N;
    cin >> N;
    cout << 0 << endl;
    string s;
    cin >> s;
    ChairCondition c;
    if (s == "Vacant") {
        exit(0);
    } else if (s == "Male") {
        c = ChairCondition::male;
    } else {
        c = ChairCondition::female;
    }
    Range r(0, N, c, c);
    for (auto i: irange((uint) 0, (uint) 20)) {
        split_range(r);
    }
    cout << "invalid finish" << endl;
    return 1;
}