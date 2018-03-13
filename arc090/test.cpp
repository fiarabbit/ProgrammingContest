#include <iostream>
#include <vector>
#include <memory>
#include <boost/range/irange.hpp>
#include <unordered_map>
#include <deque>

using namespace std;

template<class Data, class PriorityCalcFunctor>
struct PairingHeapHashMap {
    // other ways to go are ..
    //   use vector for name resolution and force outer-node to have "id" field
    //   merit: fast. cannot assert decreasing key


    struct InnerNode {
        using NumberLike = decltype(declval<PriorityCalcFunctor>()(
                declval<Data>())); // number_like = prioity_calc_functor(outer_node);

        Data *data_ptr; // not nullptr by constructor
        const PriorityCalcFunctor &priority_calc_functor; // where priority_calc_functor(const Data & outer_node)
        NumberLike key; // Note: smaller key-value have more priority
        InnerNode *parent{nullptr};
        InnerNode *children_leftest{nullptr};
        InnerNode *my_right{nullptr};
        InnerNode *my_left{nullptr};
        InnerNode *root;
        static unordered_map<Data *, InnerNode *> data_to_node;

        // constructor
        InnerNode(Data &data, const PriorityCalcFunctor &priority_calc_functor) :
                data_ptr(&data),
                priority_calc_functor(priority_calc_functor),
                key(priority_calc_functor(data)),
                root{this} {
            data_to_node.insert(make_pair(data_ptr, this));
        };

    private:
#ifdef DEBUG
        // assertation
        static void root_assert(HeapNode * inner_node_ptr){
          assert(inner_node_ptr->root == inner_node_ptr);
        };
        static void lhs_prior_to_rhs_assert(HeapNode * more_prior_node_ptr, HeapNode * less_prior_node_ptr){
            assert(more_prior_node_ptr->key <= less_prior_node_ptr->key);
        }
#endif

        static void rootize(InnerNode *inner_node_ptr) {
            inner_node_ptr->root = inner_node_ptr;
            inner_node_ptr->my_right = nullptr;
            inner_node_ptr->my_left = nullptr;
            inner_node_ptr->parent = nullptr;
        }

        InnerNode *merge_less_prior_root(InnerNode *to_be_child_node_ptr) {
#ifdef DEBUG
            root_assert(this);
            root_assert(to_be_child_node_ptr);
            lhs_prior_to_rhs_assert(this, to_be_child_node_ptr);
#endif
            to_be_child_node_ptr->my_right = this->children_leftest;
            this->children_leftest->my_left = to_be_child_node_ptr;
            this->children_leftest = to_be_child_node_ptr;
            to_be_child_node_ptr->parent = this;
            to_be_child_node_ptr->root = this;
            return this;
        }

        InnerNode *merge_more_prior_root(InnerNode *to_be_child_node_ptr) {
#ifdef DEBUG
            root_assert(this);
            root_assert(to_be_child_node_ptr);
            lhs_prior_to_rhs_assert(to_be_child_node_ptr, this);
#endif
            to_be_child_node_ptr->merge_less_prior_root(this);
            return to_be_child_node_ptr;
        }

    public:
        static InnerNode *merge(InnerNode *root_node_ptr_1, InnerNode *root_node_ptr_2) {
#ifdef DEBUG
            root_assert(root_node_ptr_1);
            root_assert(root_node_ptr_2);
#endif
            if (!root_node_ptr_1) {
                return root_node_ptr_2;
            } else if (!root_node_ptr_2) {
                return root_node_ptr_1;
            } else if (root_node_ptr_1->key <= root_node_ptr_2->key) {
                return root_node_ptr_1->merge_less_prior_root(root_node_ptr_2);
            } else {
                return root_node_ptr_1->merge_more_prior_root(root_node_ptr_2);
            }
        }

        InnerNode *erase_top() {
#ifdef DEBUG
            root_assert(this);
#endif
            InnerNode *leftest_ptr = this->children_leftest;
#ifdef DEBUG
            this->children_left = nullptr;
#endif
            delete this;
            deque<InnerNode> q{};
            while (leftest_ptr) {
                InnerNode *left_ptr = leftest_ptr;
                if (left_ptr->my_right) {
                    InnerNode *right_ptr = leftest_ptr->my_right;
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

        InnerNode *update_decrease_key() {
#ifdef DEBUG
            assert(priority_calc_functor(*(this->data_ptr)) < this->key);
#endif
            this->key = priority_calc_functor(*(this->data_ptr));
            if (this->parent && this->key < this->parent->key) {
                // if key between parent-child violate, cut off this from parent, and merge to root.
                auto original_root = this->root;
                if (this->my_left) {
                    this->my_left->my_right = this->my_right;
                } else {
                    this->parent->children_leftest = this->my_right;
                }
                if (this->my_right) {
                    this->my_right->my_left = this->my_left;
                }
                // set this as root
                rootize(this);
                // merge
                return merge(this, original_root);
            } else {
                return this->root;
            }
        }
    };
    InnerNode *root_ptr{nullptr};
    const PriorityCalcFunctor &priority_calc_functor;

    explicit PairingHeapHashMap(const PriorityCalcFunctor &priority_calc_functor) :
            root_ptr(nullptr),
            priority_calc_functor(priority_calc_functor) {}

    explicit PairingHeapHashMap(const PriorityCalcFunctor &priority_calc_functor, Data &data) :
            root_ptr(new InnerNode(data, priority_calc_functor)),
            priority_calc_functor(priority_calc_functor) {}

    template<class Container>
    explicit PairingHeapHashMap(const PriorityCalcFunctor &priority_calc_functor, Container c):
            priority_calc_functor(priority_calc_functor) {
        for (auto &&item: c) {
            root_ptr = InnerNode::merge(root_ptr, new InnerNode{item, priority_calc_functor});
        }
    };

    bool empty() {
        return (bool) root_ptr;
    }

    Data &top() {
#ifdef DEBUG
        assert(!empty());
#endif
        return *(root_ptr->data_ptr);
    }

    void pop() {
#ifdef DEBUG
        assert(!empty());
#endif
        root_ptr = root_ptr->erase_top();
    }

    void merge(PairingHeapHashMap &another_heap) {
        root_ptr = InnerNode::merge(root_ptr, another_heap.root_ptr);
        another_heap.root_ptr = nullptr;
    }

    void update_decrease_key(Data &data) {
        InnerNode::data_to_node.find(data)->update_decrease_key();
    }

    void insert(Data &data) {
        root_ptr = InnerNode::merge(root_ptr, new InnerNode{data, priority_calc_functor});
    }
};

int main() {
    const auto priority_functor = [](int x) { return x; };
    vector<int> v{1, 2, 3};
    PairingHeapHashMap<int, decltype(priority_functor)> h{priority_functor, v};
    cout << h.top() << endl;
}