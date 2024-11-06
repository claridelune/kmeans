#include <iostream>
#include <vector>
#include "node.h"

int main() {
    KDTree tree;

    std::vector<std::vector<double>> points = {
        {3.33703239,4.7647585},
        {10.34309409,12.4084774},
        {10.37416801,99.6733904},
        {3.5, 48.5},
        {39.123, 1.7534},
    };

    for (auto v : points) {
        tree.insert(v);
    }

    std::vector<double> query = {10.0, 10.0};

    const Node& nearest = tree.nearest_neighbor(query);

    std::cout << query[0] << " , " << query[1] << " : ";
    std::cout << nearest.values[0] << " , " << nearest.values[1] << std::endl;

    return 0;
}
