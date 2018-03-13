#include <iostream>
#include <vector>
#include <memory>
#include <unordered_map>
#include <deque>
#include <cassert>

using namespace std;

template<class Data, class PriorityCalcFunctor>
struct HeapNode {
    Data *data_ptr;
    const PriorityCalcFunctor &priority_calc_functor;
    decltype(declval<PriorityCalcFunctor>()(declval<Data>())) key;
    HeapNode<Data, PriorityCalcFunctor> *parent;
    HeapNode<Data, PriorityCalcFunctor> *children_leftest;
    HeapNode<Data, PriorityCalcFunctor> *my_right;
    HeapNode<Data, PriorityCalcFunctor> *my_left;
    static unordered_map<const Data *, HeapNode<Data, PriorityCalcFunctor> *> map;

    HeapNode(Data &data, const PriorityCalcFunctor &priority_calc_functor);

    static void root_assert(HeapNode<Data, PriorityCalcFunctor> *inner_node_ptr);

    static void rootize(HeapNode<Data, PriorityCalcFunctor> *inner_node_ptr);

    static HeapNode<Data, PriorityCalcFunctor> *
    merge(HeapNode<Data, PriorityCalcFunctor> *root_ptr_1, HeapNode<Data, PriorityCalcFunctor> *root_ptr_2);

    HeapNode<Data, PriorityCalcFunctor> *pop();

    HeapNode<Data, PriorityCalcFunctor> *update_decrease_key(const Data &updated_data);

    HeapNode<Data, PriorityCalcFunctor> *insert(Data &data);
};


// constructor
template<class Data, class PriorityCalcFunctor>
unordered_map<const Data *, HeapNode<Data, PriorityCalcFunctor> *>  HeapNode<Data, PriorityCalcFunctor>::map{
        unordered_map<const Data *, HeapNode<Data, PriorityCalcFunctor> *>()};


template<class Data, class PriorityCalcFunctor>
HeapNode<Data, PriorityCalcFunctor>::HeapNode(Data &data, const PriorityCalcFunctor &priority_calc_functor):
        data_ptr(&data),
        priority_calc_functor(priority_calc_functor),
        key(priority_calc_functor(data)),
        parent(nullptr),
        children_leftest(nullptr),
        my_right(nullptr),
        my_left(nullptr) {
    map.insert(make_pair(data_ptr, this));
}

template<class Data, class PriorityCalcFunctor>
void HeapNode<Data, PriorityCalcFunctor>::root_assert(HeapNode<Data, PriorityCalcFunctor> *inner_node_ptr) {
    assert(!inner_node_ptr->parent);
}

template<class Data, class PriorityCalcFunctor>
void HeapNode<Data, PriorityCalcFunctor>::rootize(HeapNode<Data, PriorityCalcFunctor> *inner_node_ptr) {
    inner_node_ptr->my_right = nullptr;
    inner_node_ptr->my_left = nullptr;
    inner_node_ptr->parent = nullptr;
}

template<class Data, class PriorityCalcFunctor>
HeapNode<Data, PriorityCalcFunctor> *
HeapNode<Data, PriorityCalcFunctor>::merge(HeapNode<Data, PriorityCalcFunctor> *root_ptr_1,
                                           HeapNode<Data, PriorityCalcFunctor> *root_ptr_2) {
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

template<class Data, class PriorityCalcFunctor>
HeapNode<Data, PriorityCalcFunctor> *HeapNode<Data, PriorityCalcFunctor>::pop() {
    deque<HeapNode<Data, PriorityCalcFunctor> *> q{};
    root_assert(this);
    auto *root_ptr = this;
    auto *leftest_ptr = root_ptr->children_leftest;
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

template<class Data, class PriorityCalcFunctor>
HeapNode<Data, PriorityCalcFunctor> *
HeapNode<Data, PriorityCalcFunctor>::update_decrease_key(const Data &updated_data) {
    root_assert(this);
    auto updated_data_ptr = &updated_data;
    HeapNode<Data, PriorityCalcFunctor> *target_node_ptr = HeapNode<Data, PriorityCalcFunctor>::map.find(
            updated_data_ptr)->second;
    assert(target_node_ptr->priority_calc_functor(*updated_data_ptr) <= target_node_ptr->key);
    target_node_ptr->key = target_node_ptr->priority_calc_functor(*updated_data_ptr);
    if (target_node_ptr->parent && target_node_ptr->key < target_node_ptr->parent->key) {
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
        return this;
    }
}

template<class Data, class PriorityCalcFunctor>
HeapNode<Data, PriorityCalcFunctor> *HeapNode<Data, PriorityCalcFunctor>::insert(Data &data) {
    return merge(this, new HeapNode(data, this->priority_calc_functor));
}

template<class Data, class PriorityCalcFunctor>
struct PairingHeap {
    HeapNode<Data, PriorityCalcFunctor> *root_ptr;
    PriorityCalcFunctor &priority_calc_functor;

    explicit PairingHeap(const PriorityCalcFunctor &priority_calc_functor);

    PairingHeap(Data &data, const PriorityCalcFunctor &priority_calc_functor);

    bool empty();

    Data &top();

    void pop();

    void update_decrease_key(const Data &data);

    void insert(Data &data);

    void merge(PairingHeap<Data, PriorityCalcFunctor> &&pairing_heap);
};

template<class Data, class PriorityCalcFunctor>
PairingHeap<Data, PriorityCalcFunctor>::PairingHeap(const PriorityCalcFunctor &priority_calc_functor):
        root_ptr(nullptr),
        priority_calc_functor(priority_calc_functor) {
};

template<class Data, class PriorityCalcFunctor>
PairingHeap<Data, PriorityCalcFunctor>::PairingHeap(Data &data, const PriorityCalcFunctor &priority_calc_functor):
        root_ptr(new HeapNode<Data, PriorityCalcFunctor>(data, priority_calc_functor)),
        priority_calc_functor(priority_calc_functor) {};

template<class Data, class PriorityCalcFunctor>
bool PairingHeap<Data, PriorityCalcFunctor>::empty() {
    return !(bool) root_ptr;
}

template<class Data, class PriorityCalcFunctor>
Data &PairingHeap<Data, PriorityCalcFunctor>::top() {
    return *(root_ptr->data_ptr);
};

template<class Data, class PriorityCalcFunctor>
void PairingHeap<Data, PriorityCalcFunctor>::pop() {
    root_ptr = root_ptr->pop();
};

template<class Data, class PriorityCalcFunctor>
void PairingHeap<Data, PriorityCalcFunctor>::update_decrease_key(const Data &data) {
    root_ptr = root_ptr->update_decrease_key(data);
}

template<class Data, class PriorityCalcFunctor>
void PairingHeap<Data, PriorityCalcFunctor>::insert(Data &data) {
    if (!root_ptr) {
        root_ptr = new HeapNode<Data, PriorityCalcFunctor>(data, priority_calc_functor);
    } else {
        root_ptr = HeapNode<Data, PriorityCalcFunctor>::merge(root_ptr, new HeapNode<Data, PriorityCalcFunctor>(data,
                                                                                                                priority_calc_functor));
    }
}

template<class Data, class PriorityCalcFunctor>
void PairingHeap<Data, PriorityCalcFunctor>::merge(PairingHeap<Data, PriorityCalcFunctor> &&pairing_heap) {
    if (!root_ptr) {
        root_ptr = pairing_heap.root_ptr;
    } else if (pairing_heap.root_ptr) {
        root_ptr = HeapNode<Data, PriorityCalcFunctor>::merge(root_ptr, pairing_heap.root_ptr);
    }
    delete pairing_heap.root_ptr;
    pairing_heap.root_ptr = nullptr;
}


int main() {
    vector<int> v{10, 20, 30};
    const auto l = [](int i) { return i; };
    PairingHeap<int, decltype(l)> h(l);
    h.insert(v.at(0));
    h.insert(v.at(1));
    v.at(1) = 20;
    h.update_decrease_key(v.at(1));
    if (!h.empty()) {
        cout << h.top() << endl;
    }
}