#include "kmeans_kdtree.h"
#include "kmeans_brute_force.h"
#include "utils.h"
#include "timer.h"
#include <iostream>

void run_timing_experiment(const std::string &data_file,
                           const std::vector<int> &ks,
                           const std::vector<int> &ns,
                           const std::string &output_file) {
    for (const auto &k : ks) {
        for (const auto &n : ns) {
            auto data = load_data(data_file, n);

            Timer timer;
            KMeansBF kmeans_bf(k, data);
            kmeans_bf.run();
            double time_without_kdtree = timer.elapsed();

            timer = Timer();
            KMeansKDTree kmeans_kd(k, data);
            kmeans_kd.run();
            double time_with_kdtree = timer.elapsed();

            save_timing_results(output_file, k, n, time_without_kdtree, time_with_kdtree);
            std::cout << "time results saved" << std::endl;
        }
    }
}


void run_experiment(const std::string &data_file, int k, int n, int experiment_id) {
    auto data = load_data(data_file, n);

    KMeansBF kmeans_bf(k, data);
    kmeans_bf.run();

    KMeansKDTree kmeans_kd(k, data);
    kmeans_kd.run();

    std::string clusters_file_kd = "data/kd_cluster_" + std::to_string(experiment_id) + ".csv";
    std::string assignments_file_kd = "data/kd_assignments_" + std::to_string(experiment_id) + ".csv";
    std::string clusters_file_bf = "data/bf_cluster_" + std::to_string(experiment_id) + ".csv";
    std::string assignments_file_bf = "data/bf_assignments_" + std::to_string(experiment_id) + ".csv";
    save_clustering_results(assignments_file_kd, clusters_file_kd, kmeans_kd.assignments, kmeans_kd.centroids);
    save_clustering_results(assignments_file_bf, clusters_file_bf, kmeans_bf.assignments, kmeans_bf.centroids);

    std::cout << "Experiment " << experiment_id << " completed and saved.\n";
}

int main() {
    const std::string data_file = "data/data2k.csv";
    const std::vector<int> ks1 = {5, 15, 25, 50, 75};
    const std::vector<int> ns1 = {1000, 1150, 1300, 1450, 1600, 1750, 1900, 2050, 2200, 2400};
    const std::vector<int> ks2 = {5, 15, 25, 50, 75, 100, 125, 150, 200};
    const std::vector<int> ns2 = {1000, 1450, 1900, 2400};
    
    run_timing_experiment(data_file, ks1, ns1, "data/times_k_fixed.csv");
    run_timing_experiment(data_file, ks2, ns2, "data/times_n_fixed.csv");

    for (int i = 1; i <= 10; ++i) {
        run_experiment(data_file, 18, 2400, i);
    }

    /* KMeansKDTree kmeans_kd(5, data);
    kmeans_kd.run();
    auto centroids = kmeans_kd.centroids;
    auto assignments = kmeans_kd.assignments;
    save_clustering_results("data/clusters.csv", "data/centroids.csv", assignments, centroids); */

    return 0;
}
