#include <iostream>
#include <vector>
#include <memory>
#include <unordered_map>
#include <deque>
#include <cassert>

using namespace std;

// other ways to go are ..
//   use vector for name resolution and force outer-node to have "id" field
//   merit: fast. cannot assert decreasing key
template<class Data, class PriorityCalcFunctor>
struct HeapNode{
    Data * data_ptr;
    const PriorityCalcFunctor & priority_calc_functor;
    decltype(declval<PriorityCalcFunctor>()(declval<Data>())) key;
    HeapNode<Data, PriorityCalcFunctor> * parent;
    HeapNode<Data, PriorityCalcFunctor> * children_leftest;
    HeapNode<Data, PriorityCalcFunctor> * my_right;
    HeapNode<Data, PriorityCalcFunctor> * my_left;
    static unordered_map<Data *, HeapNode<Data, PriorityCalcFunctor> *> map;

    HeapNode();
    HeapNode(Data &data, const PriorityCalcFunctor &priority_calc_functor);
    static void root_assert(HeapNode<Data, PriorityCalcFunctor> * inner_node_ptr);
    static void rootize(HeapNode<Data, PriorityCalcFunctor> *inner_node_ptr);
    static HeapNode<Data, PriorityCalcFunctor> * merge(HeapNode<Data, PriorityCalcFunctor> *root_ptr_1, HeapNode<Data, PriorityCalcFunctor> *root_ptr_2);
    HeapNode<Data, PriorityCalcFunctor> *pop();
    HeapNode<Data, PriorityCalcFunctor> *update_decrease_key(Data * updated_data_ptr);
    HeapNode<Data, PriorityCalcFunctor> * insert(Data & data);
};

// constructor
template <class Data, class PriorityCalcFunctor>
unordered_map<Data * , HeapNode<Data, PriorityCalcFunctor> *>  HeapNode<Data, PriorityCalcFunctor>::map{unordered_map<Data * , HeapNode<Data, PriorityCalcFunctor> *>()};

template<class Data, class PriorityCalcFunctor>
HeapNode<Data, PriorityCalcFunctor>::HeapNode():
data_ptr(nullptr),
priority_calc_functor(NULL),
key(NULL),
parent(nullptr),
children_leftest(nullptr),
my_right(nullptr),
my_left(nullptr)
{}

template <class Data, class PriorityCalcFunctor>
HeapNode<Data, PriorityCalcFunctor>::HeapNode(Data &data, const PriorityCalcFunctor &priority_calc_functor):
data_ptr(&data),
priority_calc_functor(priority_calc_functor),
key(priority_calc_functor(data)),
parent(nullptr),
children_leftest(nullptr),
my_right(nullptr),
my_left(nullptr)
{
    map.insert(make_pair(data_ptr, this));
}

template <class Data, class PriorityCalcFunctor>
void HeapNode<Data, PriorityCalcFunctor>::root_assert(HeapNode<Data, PriorityCalcFunctor> *inner_node_ptr) {
    assert(!inner_node_ptr->parent);
}

template <class Data, class PriorityCalcFunctor>
void HeapNode<Data, PriorityCalcFunctor>::rootize(HeapNode<Data, PriorityCalcFunctor> *inner_node_ptr) {
    inner_node_ptr->my_right = nullptr;
    inner_node_ptr->my_left = nullptr;
    inner_node_ptr->parent = nullptr;
}

template <class Data, class PriorityCalcFunctor>
HeapNode<Data, PriorityCalcFunctor> * HeapNode<Data, PriorityCalcFunctor>::merge(HeapNode<Data, PriorityCalcFunctor> * root_ptr_1, HeapNode<Data, PriorityCalcFunctor> * root_ptr_2){
    if (!root_ptr_1->data_ptr){
        return root_ptr_2;
    } else if (!root_ptr_2->data_ptr) {
        return root_ptr_1;
    } else {
        root_assert(root_ptr_1);
        root_assert(root_ptr_2);
        HeapNode<Data, PriorityCalcFunctor> *to_be_root_ptr;
        HeapNode<Data, PriorityCalcFunctor> *to_be_child_ptr;
        if (root_ptr_1->key < root_ptr_2->key) {
            to_be_root_ptr = root_ptr_1;
            to_be_child_ptr = root_ptr_2;
        } else {
            to_be_root_ptr = root_ptr_2;
            to_be_child_ptr = root_ptr_1;
        }
        to_be_child_ptr->my_right = to_be_root_ptr->children_leftest;
        if (to_be_child_ptr->children_leftest) {
            to_be_root_ptr->children_leftest->my_left = to_be_child_ptr;
        }
        to_be_root_ptr->children_leftest = to_be_child_ptr;
        to_be_child_ptr->parent = to_be_root_ptr;
        return to_be_root_ptr;
    }
}

template <class Data, class PriorityCalcFunctor>
HeapNode<Data, PriorityCalcFunctor> * HeapNode<Data, PriorityCalcFunctor>::pop() {
    deque<HeapNode<Data, PriorityCalcFunctor>*> q{};
    root_assert(this);
    auto * root_ptr = this;
    auto * leftest_ptr = root_ptr->children_leftest;
    HeapNode<Data, PriorityCalcFunctor>::map.erase(root_ptr->data_ptr);
    delete root_ptr;
    while (leftest_ptr) {
        auto *left_ptr = leftest_ptr;
        if (left_ptr->my_right) {
            auto *right_ptr = leftest_ptr->my_right;
            leftest_ptr = right_ptr->my_right;
            rootize(left_ptr);
            rootize(right_ptr);
            q.emplace_back(merge(left_ptr, right_ptr));
        } else {
            rootize(left_ptr);
            leftest_ptr = nullptr;
            q.emplace_back(left_ptr);
        }
    }
    if (!q.empty()) {
        leftest_ptr = q.back();
        q.pop_back();
        while (!q.empty()) {
            merge(leftest_ptr, q.back());
            q.pop_back();
        }
    }
    return leftest_ptr;
}

template <class Data, class PriorityCalcFunctor>
HeapNode<Data, PriorityCalcFunctor>* HeapNode<Data, PriorityCalcFunctor>::update_decrease_key(Data * updated_data_ptr) {
    root_assert(this);
    HeapNode<Data, PriorityCalcFunctor>* target_node_ptr = HeapNode<Data, PriorityCalcFunctor>::map.find(updated_data_ptr)->second;
    assert(target_node_ptr->priority_calc_functor(*updated_data_ptr) <= target_node_ptr->key);
    target_node_ptr->key = target_node_ptr->priority_calc_functor(*updated_data_ptr);
    if (target_node_ptr->parent && target_node_ptr->key < target_node_ptr->parent->key){
        auto original_root = this;
        if (target_node_ptr->my_left) {
            target_node_ptr->my_left->my_right = target_node_ptr->my_right;
        } else {
            target_node_ptr->parent->children_leftest = target_node_ptr->my_right;
        }
        if (target_node_ptr->my_right) {
            target_node_ptr->my_right->my_left = target_node_ptr->my_left;
        }
        rootize(target_node_ptr);
        return merge(target_node_ptr, original_root);
    } else {
        return target_node_ptr;
    }
}

template<class Data, class PriorityCalcFunctor>
HeapNode<Data, PriorityCalcFunctor> * HeapNode<Data, PriorityCalcFunctor>::insert(Data & data) {
    return merge(this, new HeapNode(data, this->priority_calc_functor));
}

int main() {
    vector<int> v{10,20,30};
    auto l = [](int i){return i;};
    auto h = new HeapNode<int, decltype(l)>(v.at(1), l);
    h = h->insert(v.at(0));
    v.at(1) = 1;
    h = h->update_decrease_key(&v.at(1));
    cout << *(h->data_ptr) << endl;
}