#include "kmeans_brute_force.h"
#include "utils.h"
#include <limits>

int KMeansBF::find_closest_centroid(Point& point) {
    int best_cluster = 0;
    double best_distance = std::numeric_limits<double>::max();

    for (int i = 0; i < k; ++i) {
        double distance = squared_distance(point, centroids[i]);
        if (distance < best_distance) {
            best_distance = distance;
            best_cluster = i;
        }
    }
    return best_cluster;
}
