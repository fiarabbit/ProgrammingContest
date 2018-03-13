#include <iostream>
#include <vector>
#include <boost/range/irange.hpp>
#include <deque>
#include <utility>
#include <limits>

using namespace std;
using namespace boost;
using uint = unsigned int;
using ll = long long int;
using ull = unsigned long long int;

struct Node{
    uint counter{numeric_limits<uint>::max()};
    bool enabled{true};
    uint x;
    uint y;
    explicit Node(uint _x, uint _y): x(_x), y(_y){}
};

int main() {

    uint H, W;
    cin >> H >> W;

    vector<vector<Node>> map(H, vector<Node>(W, Node(0, 0)));
    uint whites{0};
    for (auto &&i: irange((unsigned int) 0, H)){
        for (auto &&j: irange((unsigned int) 0, W)){
            map.at(i).at(j).x = j;
            map.at(i).at(j).y = i;
            char s;
            cin >> s;
            if (s == *"#"){
                map.at(i).at(j).enabled = false;
            }else{
                whites++;
            }
        }
    }

    deque<Node> d{};

    map.at(0).at(0).counter = 0;
    d.push_back(map.at(0).at(0));

    while(!d.empty()){
        Node to_be_visited = d.front();
        uint x = to_be_visited.x;
        uint y = to_be_visited.y;
        d.pop_front();
//        cout << "x:" << x << " y:" << y << endl;
//        up
        if (y != 0 && map.at(y-1).at(x).enabled && map.at(y-1).at(x).counter==numeric_limits<uint>::max()){
            map.at(y-1).at(x).counter = to_be_visited.counter + 1;
            d.push_back(map.at(y-1).at(x));
        }
//        down
        if (y != H-1 && map.at(y+1).at(x).enabled && map.at(y+1).at(x).counter==numeric_limits<uint>::max()){
            map.at(y+1).at(x).counter = to_be_visited.counter + 1;
            d.push_back(map.at(y+1).at(x));
        }
//        left
        if (x != 0 && map.at(y).at(x-1).enabled && map.at(y).at(x-1).counter==numeric_limits<uint>::max()){
            map.at(y).at(x-1).counter = to_be_visited.counter + 1;
            d.push_back(map.at(y).at(x-1));
        }
//        right
        if (x != W-1 && map.at(y).at(x+1).enabled && map.at(y).at(x+1).counter==numeric_limits<uint>::max()){
            map.at(y).at(x+1).counter = to_be_visited.counter + 1;
            d.push_back(map.at(y).at(x+1));
        }
    }

//
//    for (auto &&i: irange((unsigned int) 0, H)){
//        for (auto &&j: irange((unsigned int) 0, W)){
//            if(!map.at(i).at(j).enabled){
//                cout << "#";
//            } else {
//                cout << map.at(i).at(j).counter;
//            }
//        }
//        cout << endl;
//    }


    if (map.at(H-1).at(W-1).counter!=numeric_limits<uint>::max()){
        cout << (whites-map.at(H-1).at(W-1).counter-1) << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}