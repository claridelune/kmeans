#include "kmeans_kdtree.h"

void KMeansKDTree::initialize_centroids() {
    kdtree = new KDTree;
    KMeans::initialize_centroids();
    for (auto &centroid : centroids) {
        kdtree->insert(centroid);
    }
}

int KMeansKDTree::find_closest_centroid(Point &point) {
    Node nearest_node = kdtree->nearest_neighbor(point);
    auto it = std::find(centroids.begin(), centroids.end(), nearest_node.values);
    return it - centroids.begin();
}

void KMeansKDTree::update_centroids() {
    KMeans::update_centroids();
    delete kdtree;

    kdtree = new KDTree;
    for (auto &centroid : centroids) {
        kdtree->insert(centroid);
    }
}
