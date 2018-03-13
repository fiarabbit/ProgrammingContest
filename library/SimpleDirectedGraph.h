#ifndef LIBRARY_LIBRARY_H
#define LIBRARY_LIBRARY_H

# include <vector>
# include <set>

class AdjacencyMatrix {
public:
    explicit AdjacencyMatrix(unsigned int node_size) :
            node_size_(node_size),
            edge_size_(0),
            adjacency_list_(node_size, std::vector<unsigned int>(node_size)) {};
    unsigned int node_size_;
    unsigned int edge_size_;
    std::vector<std::vector<unsigned int>> adjacency_list_;

    void add_edge(unsigned int node_from, unsigned int node_to) {

    };
};


class UnionFind {
public:
    void mergeGroup(unsigned int node_1, unsigned int node_2);

    bool isSameGroup(unsigned int node_1, unsigned int node_2);

    unsigned int group_size;

};

#endif