#include <iostream>
#include <vector>
#include <memory>

using namespace std;

template <class Data>
struct Hoge{
    vector<Data> v;
    explicit Hoge(vector<int> to_be_multiplied):v{}{
        for (auto &&item: to_be_multiplied){
            v.push_back(item*10);
        }
    }
    template <class Container> explicit Hoge(Container c):v{}{
        for (auto &&item: c){
            v.push_back(item);
        }
    };
};

int main(){
    array<int, 3> a{0, 1, 2};
    Hoge<int> hoge_array{a};
    for (auto &&i: hoge_array.v){
        cout << i << endl;
    }

    vector<int> v{0, 1, 2};
    Hoge<int> hoge_vector{v};
    for (auto &&i: hoge_vector.v){
        cout << i << endl;
    }

}