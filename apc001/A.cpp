#include <iostream>
#include <vector>
#include <boost/range/irange.hpp>
#include <boost/heap/pairing_heap.hpp>

using  namespace std;
using namespace boost;

struct Node{
    int value;
    Node(int _value):value(_value){}
    bool operator > (const Node & n ) const{
        return value > n.value;
    }
};

int main() {
    heap::pairing_heap<Node, heap::compare<greater<>>> heap;
    auto handle1 = heap.emplace(Node{1});
    auto handle2 = heap.emplace(Node{2});
    cout << (*handle1).value << endl;
    (*handle1).value = 3;
    heap.update(handle1);
    while(!heap.empty()){
        cout << heap.top().value << endl;
        heap.pop();
    }





    return 0;
}