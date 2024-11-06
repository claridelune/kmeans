#ifndef KDTREE_H
#define KDTREE_H

#include "node.h"

class KDTree {
    private:
        Node* root;
        int size;

        void nearest_recursive(Node* node, std::vector<double>& point, double& min_distance, Node*& best_node) const {
            if (!node) return;

            double distance = squared_distance(node->values, point);

            if (distance < min_distance) {
                min_distance = distance;
                best_node = node;
            }

            int axis = node->depth % point.size();

            Node* default_branch = nullptr;
            Node* other_branch = nullptr;

            if (point[axis] < node->values[axis]) {
                default_branch = node->left;
                other_branch = node->right;
            } else {
                default_branch = node->right;
                other_branch = node->left;
            }

            nearest_recursive(default_branch, point, min_distance, best_node);
            
            double axis_dist = point[axis] - node->values[axis];
            if (axis_dist * axis_dist < min_distance) {
                nearest_recursive(other_branch, point, min_distance, best_node);
            }
        }

      public:
        KDTree() : root(nullptr), size(0) {}
        ~KDTree() {
            clear_recursive(root);
        }

        void clear_recursive(Node *node) {
            if (!node) return;
            clear_recursive(node->left);
            clear_recursive(node->right);
            delete node;
        }

        void clear() {
            clear_recursive(root);
            root = nullptr;
            size = 0;
        }

        void insert(std::vector<double>& point) {
            Node** p = &root;

            int depth = 0;

            while (*p) {
                if ((*p)->values == point) {
                    return;
                }
                int axis = depth % point.size();

                if (point[axis] < (*p)->values[axis]) {
                    p = &(*p)->left;
                } else {
                    p = &(*p)->right;
                }
                depth++;
            }

            *p = new Node(point, depth);
            size++;
        }

        Node& nearest_neighbor(std::vector<double>& point) const {
            double min_distance = std::numeric_limits<double>::max();
            Node* best_node = root;
            nearest_recursive(root, point, min_distance, best_node);

            return *best_node;
        }
};

#endif
