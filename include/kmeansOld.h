#ifndef KMEANS_H
#define KMEANS_H

#include "point.h"
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <utility>
#include <limits>
#include <numeric>
#include <random>
#include <vector>
#include <execution>


std::pair<DataFrame, std::vector<int>> k_means(const DataFrame& data, int k);


#endif
