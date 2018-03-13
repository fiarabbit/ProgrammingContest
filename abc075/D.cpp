#include <iostream>
#include <vector>
#include <boost/range/irange.hpp>
#include <algorithm>
#include <boost/heap/binomial_heap.hpp>
#include <limits>

using namespace std;
using namespace boost;
using uint = unsigned int;
using ll = long long int;
using ull = unsigned long long int;

struct Point{
    ll x;
    ll y;
    uint id;
    Point(ll _x, ll _y, uint _id):x(_x), y(_y), id(_id){
    }
};

int main() {
    uint N, K;
    cin >> N >> K;
    vector<Point> xsort{};
    vector<Point> ysort{};
    for (auto &&i: irange((unsigned int) 0, N)){
        ll x, y;
        cin >> x >> y;
        Point px{x, y, i}, py{x, y, i};
        xsort.push_back(px);
        ysort.push_back(py);
    }
    sort(xsort.begin(), xsort.end(), [](Point p1, Point p2){return p1.x < p2.x;});
    sort(ysort.begin(), ysort.end(), [](Point p1, Point p2){return p1.y < p2.y;});
    heap::binomial_heap<ull> menseki_heap;
    for (auto &&i: irange((unsigned int) 0, N-K+1)){
        ll x_min{xsort.at(i).x}, x_max{xsort.at(i+K-1).x}, y_min{numeric_limits<ll>::max()}, y_max{numeric_limits<ll>::min()};
        for (auto &&j: irange(i, i+K)){
            y_min = min(y_min, xsort.at(j).y);
            y_max = max(y_max, xsort.at(j).y);
        }
        menseki_heap.push((ull)((x_max - x_min) * (y_max - y_min)));
    }
    for (auto &&i: irange((unsigned int) 0, N-K+1)){
        ll y_min{ysort.at(i).y}, y_max{ysort.at(i+K-1).y}, x_min{numeric_limits<ll>::max()}, x_max{numeric_limits<ll>::min()};
        for (auto &&j: irange(i, i+K)){
            x_min = min(x_min, ysort.at(j).x);
            x_max = max(x_max, ysort.at(j).x);
        }
        menseki_heap.push((ull)((y_max - y_min) * (x_max - x_min)));
    }
    cout << menseki_heap.top() << endl;

    return 0;
}