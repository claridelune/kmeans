#include "kmeans.h"
#include <random>

KMeans::KMeans(int k, const std::vector<Point> &data) : k(k), data(data) {
    assignments = std::vector<int>(data.size(), -1);
    centroids = std::vector<Point>(k);
}

void KMeans::run() {
    initialize_centroids();
    
    bool has_converged = false;

    while (!has_converged) {
        has_converged = true;
        for (int i = 0; i < data.size(); i++) {
            int best_cluster =  find_closest_centroid(data[i]);

            if (assignments[i] != best_cluster) {
                assignments[i] = best_cluster;
                has_converged = false;
            }
        }
        update_centroids();
    }
}

void KMeans::initialize_centroids() {
    static std::random_device seed;
    static std::mt19937 random_number_generator(seed());
    std::uniform_int_distribution<size_t> indices(0, data.size() - 1);

    for (auto& centroid : centroids) {
        centroid = data[indices(random_number_generator)];
    }

}

void KMeans::update_centroids() {

    std::vector<Point> new_means(k, Point(data[0].size(), 0.0));

    std::vector<int> counts(k, 0);

    for (int i = 0; i < data.size(); i++) {
        const auto cluster = assignments[i];
        for (int j = 0; j < data[i].size(); j++) {
            new_means[cluster][j] += data[i][j];
        }
        counts[cluster] += 1;
    }
    
    for (int cluster = 0; cluster < k; cluster++) {
        const auto count = std::max(1, counts[cluster]);
        for (int j = 0; j < new_means[cluster].size(); j++) {
          if (!counts[cluster]) {
              new_means[cluster] = data[0];
              continue;
          }
            new_means[cluster][j] /= counts[cluster];
        }
    }

    centroids = new_means;
}
