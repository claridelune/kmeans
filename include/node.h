#include <algorithm>
#include <limits>
#include <optional>
#include <vector>

#include "utils.h"

struct Node {
	int depth;
	std::vector<double> values;
	Node* left=0;
	Node* right=0;
	Node(std::vector<double>& vals, int depth) {
		values = vals;
	}
};
