#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <fstream>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <vector>

inline double squared_distance(std::vector<double> &a, std::vector<double> &b) {
	int dim = a.size();
    std::vector<double> squaredDeltas(dim);
	for (int i = 0; i < dim; i++) {
		double delta = (a[i] - b[i]);
		squaredDeltas[i] = delta * delta;
	}
	double distance = 0;
	for (auto it : squaredDeltas) {
		distance += it;
	}
	return (distance);
}


inline std::vector<std::vector<double>> load_data(const std::string& file_path, int num_points) {
    std::vector<std::vector<double>> data;
    std::ifstream file(file_path);
    
    if (!file.is_open()) {
        throw std::runtime_error("Error: no se pudo abrir el archivo " + file_path);
    }

    std::string line;
    int count = 0;
    while (std::getline(file, line) && count < num_points) {
        std::istringstream line_stream(line);
        std::string current_value;
        std::vector<double> point;

        while (std::getline(line_stream, current_value, ',')) {
            double val = stod(current_value);
            point.push_back(val);
        }
        data.push_back(point);
        count++;
    }

    if (count < num_points) {
        std::cerr << "Advertencia: el archivo contiene solo " << count << " puntos de los " << num_points << " solicitados.\n";
    }

    return data;
}

/* inline void save_timing_results(const std::string& file_path, int k, int n, double time_without_kdtree, double time_with_kdtree) {
    std::ofstream file(file_path, std::ios::app);
    file << k << "," << n << "," << time_without_kdtree << "," << time_with_kdtree << "\n";
} */

inline void save_clustering_results(const std::string& clusters_file, const std::string& centroids_file, const std::vector<int>& assignments, const std::vector<std::vector<double>>& centroids) {
    std::ofstream clusters_out(clusters_file);
    clusters_out << "point_id,cluster\n";

    for (int i = 0; i < assignments.size(); ++i) {
        clusters_out << i << "," << assignments[i] << "\n";
    }

    std::ofstream centroids_out(centroids_file);
    for (const auto& centroid : centroids) {
        for (int i = 0; i < centroid.size() - 1; i++) {
            centroids_out << centroid[i] << ",";
        }
        centroids_out << centroid[centroid.size() - 1] << '\n';
    }
}


#endif
