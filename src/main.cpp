// #include "../include/kmeans.h"
#include "kmeans_kdtree.h"
#include "utils.h"
#include "timer.h"
#include <iostream>

/* void run_timing_experiment(const std::string &data_file,
                           const std::vector<int> &ks,
                           const std::vector<int> &ns,
                           const std::string &output_file) {
    for (const auto &k : ks) {
        for (const auto &n : ns) {
            auto data = load_data(data_file, n);

            Timer timer;
            auto [centroids1, assignments1] = k_means(data, k);
            double time_without_kdtree = timer.elapsed();

            timer = Timer();
            // con kd tree
            double time_with_kdtree = timer.elapsed();

            save_timing_results(output_file, k, n, time_without_kdtree, time_with_kdtree);
        }
    }
} */

int main() {
    const std::string data_file = "data/data2k.csv";
    const std::vector<int> ks1 = {5, 15, 25, 50, 75};
    const std::vector<int> ns1 = {1000, 1150, 1300, 1450, 1600, 1750, 1900, 2050, 2200, 2400};
    const std::vector<int> ks2 = {5, 15, 25, 50, 75, 100, 125, 150, 200};
    const std::vector<int> ns2 = {1000, 1450, 1900, 2400};
    
    // run_timing_experiment(data_file, ks1, ns1, "data/times_k_fixed.csv");
    // run_timing_experiment(data_file, ks2, ns2, "data/times_n_fixed.csv");
    auto data = load_data(data_file, 2400);
    std::cout << data.size() << std::endl;

    KMeansKDTree kmeans_kd(5, data);
    kmeans_kd.run();
    auto centroids = kmeans_kd.centroids;
    auto assignments = kmeans_kd.assignments;
    save_clustering_results("data/clusters.csv", "data/centroids.csv", assignments, centroids);

    std::cout << "end xd" << std::endl;

    return 0;
}
