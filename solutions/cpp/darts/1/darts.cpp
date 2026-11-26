#include "darts.h"
#include <cmath>

namespace darts {

    int score(double x, double y) {
        double dist_sq = x * x + y * y;
    
        if (dist_sq <= 1.0) return 10;
        if (dist_sq <= 25.0) return 5;
        if (dist_sq <= 100.0) return 1;

        return 0;
    };

}  // namespace darts