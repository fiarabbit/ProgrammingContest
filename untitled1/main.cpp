#include <unordered_map>
#include <utility>

using namespace std;

template<class Functor, class Data>
class PairingHeap{
    using NumberLike = decltype(declval<Functor>()(declval<Data>()));
    // inner class
    struct Node{
        // member variables
        PairingHeap<Functor, Data> * heap_ptr;
        Data *  data_ptr; // might cause SEGV, the parameter of constructor would better be reference...  (not shared_pointer)
        NumberLike priority;  // copyable
        Node * children_head;
        Node * parent;
        Node * next;
        Node * prev;

        // constructor
        Node(PairingHeap<Functor, Data> * heap_ptr, Data & data);
    };
private:
    // member variables
    Node * root_ptr;
    unordered_map<Data *, Node *> map;
    const Functor & func; // where [](Data)->NumberLike

public:
    // constructor
    explicit PairingHeap(const Functor & func); // constructor 1
    PairingHeap(const Functor & func, Data & data);    // constructor  2

    // member functions
    bool empty();
    void insert(Data & data);
    void merge(PairingHeap * heap_ptr);
    Data & top();
    void pop();    // properly release memory
    void update_decrease_key(Data & data);
};

template <class Functor, class Data>
PairingHeap<Functor, Data>::Node::Node(PairingHeap<Functor, Data> * heap_ptr, Data &data):
        heap_ptr(heap_ptr),
        data_ptr(&data),
        priority(heap_ptr->func(data)),
        children_head(nullptr),
        parent(nullptr),
        next(nullptr),
        prev(nullptr)
{}

template <class Functor, class Data>
PairingHeap<Functor, Data>::PairingHeap(const Functor &func):
        root_ptr(nullptr),
        map({}),
        func(func)
{}

template <class Functor, class Data>
PairingHeap<Functor, Data>::PairingHeap(const Functor &func, Data &data):
        root_ptr(new PairingHeap<Functor, Data>::Node(this, data)),
        map({{&data, root_ptr}}),
        func(func)
{}

template <class Functor, class Data>
bool PairingHeap<Functor, Data>::empty() {
    return !(bool)root_ptr;
}

template <class Functor, class Data>
void PairingHeap<Functor, Data>::insert(Data &data) {
    auto new_node_ptr = new PairingHeap<Functor, Data>::Node(this, data);
    map.insert({&data, new_node_ptr});
    if (!root_ptr){
        root_ptr = new_node_ptr;
    }else{
        if (root_ptr->priority > new_node_ptr->priority) swap(root_ptr, new_node_ptr);
        new_node_ptr->next = root_ptr->children_head;
        if (root_ptr->children_head) root_ptr->children_head->prev = new_node_ptr;
        root_ptr->children_head = new_node_ptr;
        new_node_ptr->parent = root_ptr;
    }
}

template <class Functor, class Data>
void PairingHeap<Functor, Data>::merge(PairingHeap *heap_ptr) {
    map.insert();
    if (!root_ptr){
        root_ptr = heap_ptr->root_ptr;
    } else if (heap_ptr){
        if (root_ptr->priority > heap_ptr->root_ptr->priority) swap(root_ptr, heap_ptr->root_ptr);
        heap_ptr->root_ptr->next = root_ptr->children_head;
        if (root_ptr->children_head) root_ptr->children_head->prev = heap_ptr->root_ptr;
        root_ptr->children_head = heap_ptr->root_ptr;
        heap_ptr->root_ptr->parent = root_ptr;
        delete heap_ptr;
    }
}

int main(){
    auto l = [](int a){return a;};
    int a{1};
    PairingHeap<decltype(l), decltype(a)> h{l, a};
    int b{3};
    h.insert(b);
}