//
// Created by hashimoto on 2018/02/27.
//

#include <vector>
#include <unordered_map>

using namespace std;


template<class data>
struct Node {
    static vector<Node*> hoge;
    data * ptr;
};

template <class T>
vector<T> Node<T>::hoge{};

int main(){
    int x;
    decltype(x) y;
}