#ifndef KMEANS_BRUTE_FORCE_H
#define KMEANS_BRUTE_FORCE_H

#include "kmeans.h"

class KMeansBF : public KMeans {
    public:
        KMeansBF(int k, std::vector<Point> &data) : KMeans(k, data) {}
            
    protected:
        int find_closest_centroid(Point& point) override;
};

#endif
