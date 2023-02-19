#ifndef LINALG_H
#define LINALG_H

#include <math.h>

typedef struct vec {
    double x;
    double y;
} vec;

vec init_vec(double, double);
vec vec_sum(vec, vec);
double vec_length(vec);
vec flip_x(vec);
vec flip_y(vec);
vec flip(vec);
vec v_diff(vec, vec);
vec scale(vec, double);
vec norm(vec);
vec transform(vec, double, double);

#endif // LINALG_H
