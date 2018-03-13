#include <iostream>
#include <vector>
#include <boost/range/irange.hpp>
#include <boost/heap/pairing_heap.hpp>

using namespace std;
using namespace boost;
using namespace heap;
using uint = unsigned int;
using ll = long long int;
using ull = unsigned long long int;


struct Node{
    uint value;
    bool operator < (const Node & n) const{
        return value < n.value;
    }
    explicit Node(uint v): value(v){
        cout << "constructor was called" << endl;
        cout << v << endl;
    }
    Node(const Node & n): value(n.value){
        cout << "copy constructer (const) was called" << endl;
        cout << "my value will be " << n.value << endl;
    };
    Node(Node & n): value(n.value){
        cout << "copy constructer was called" << endl;
        cout << "my value will be " << n.value << endl;
    };
};

int main() {
    pairing_heap<Node&> h;
    vector<pairing_heap<Node&>::handle_type> node_handles;
    for (auto &&i: irange((unsigned int) 0, (uint)10)){
        pairing_heap<Node&>::handle_type handle = h.push(Node(i));
        node_handles.push_back(handle);
    }
    (*node_handles.at(0)).value = 100;
    h.update(node_handles.at(0));
    while (!h.empty()){
        cout << h.top().value << endl;
        h.pop();
    }
    cout << endl;
    for (auto &&i: irange((unsigned int) 0, (uint)10)){
        cout << (*node_handles.at(i)).value << endl;
    }

    return 0;
}