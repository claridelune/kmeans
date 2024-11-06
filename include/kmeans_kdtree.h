#ifndef KMEANS_KDTREE_H
#define KMEANS_KDTREE_H

#include "kdtree.h"
#include "kmeans.h"

class KMeansKDTree : public KMeans {
    public:
        KMeansKDTree(int k, std::vector<Point>& data) : KMeans(k, data) {}
    private:
        KDTree kdtree;

    protected:
      void initialize_centroids() override;
      int find_closest_centroid(Point& point) override;
      void update_centroids() override;
};

#endif
