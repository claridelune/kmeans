#include "kmeans_kdtree.h"

void KMeansKDTree::initialize_centroids() {
    KMeans::initialize_centroids();
    for (auto &centroid : centroids) {
        kdtree.insert(centroid);
    }
}

int KMeansKDTree::find_closest_centroid(Point &point) {
    Node nearest_node = kdtree.nearest_neighbor(point);
    auto it = std::find(centroids.begin(), centroids.end(), nearest_node.values);
    // std::cout << centroids.size() << " - "  << std::distance(centroids.begin(), it) << std::endl;
    return it - centroids.begin();
}

void KMeansKDTree::update_centroids() {
    KMeans::update_centroids();
    kdtree.clear();
    for (auto &centroid : centroids) {
        kdtree.insert(centroid);
    }
}
