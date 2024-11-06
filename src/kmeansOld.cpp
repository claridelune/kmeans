#include "../include/kmeans.h"

DataFrame initialize_random_centroids(const DataFrame& data, int k) {
    static std::random_device seed;
    static std::mt19937 random_number_generator(seed());
    std::uniform_int_distribution<size_t> indices(0, data.size() - 1);

    DataFrame centroids(k);
    for (auto& centroid : centroids) {
        centroid = data[indices(random_number_generator)];
    }
    return centroids;
}

std::pair<DataFrame, std::vector<int>> k_means(const DataFrame &data, int k) {
    DataFrame means = initialize_random_centroids(data, k);

    std::vector<int> assignments(data.size());

    bool has_converged = false;

    while (!has_converged) {
        has_converged = true;

        for (int point = 0; point < data.size(); point++) {
            double best_distance = std::numeric_limits<double>::max();
            int best_cluster = 0;
            for (int cluster = 0; cluster < k; cluster++) {
                double distance = euclidean_distance(data[point], means[cluster]);
                if (distance < best_distance) {
                    best_distance = distance;
                    best_cluster = cluster;
                }
            }

            if (assignments[point] != best_cluster) {
                assignments[point] = best_cluster;
                has_converged = false;
            }
        }

        DataFrame new_means(k, Point{0.0, 0.0});
        std::vector<int> counts(k, 0);
        for (int point = 0; point < data.size(); point++) {
            const auto cluster = assignments[point];
            new_means[cluster] += data[point];
            counts[cluster] += 1;
        }
        
        for (int cluster = 0; cluster < k; cluster++) {
            const auto count = std::max(1, counts[cluster]);
            means[cluster] = new_means[cluster] / count;
        }
    }

    return {means, assignments};
}
