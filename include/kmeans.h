#ifndef KMEANS_H
#define KMEANS_H

#include <vector>
#include <utility>

using Point = std::vector<double>;

class KMeans {
    protected:
        int k;
        std::vector<Point> data;

        virtual int find_closest_centroid(Point& point) = 0;
        virtual void initialize_centroids();
        virtual void update_centroids();
    public:
        KMeans(int k, const std::vector<Point>& data);
        std::vector<std::vector<double>> centroids;
        std::vector<int> assignments;

        void run();

    private:
};

#endif
