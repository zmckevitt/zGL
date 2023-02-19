#include "linalg.h"

vec init_vec(double x, double y) {
    vec v;
    v.x = x;
    v.y = y;
    return v;
}

vec vec_sum(vec v1, vec v2) {
    vec v;
    v.x = v1.x + v2.x;
    v.y = v1.y + v2.y;
    return v;
}

double vec_length(vec v) {
    return sqrt(v.x*v.x + v.y*v.y);
}

vec flip_x(vec v) {
    vec v_t;
    v_t.x = -1 * v.x;
    v_t.y = v.y;
    return v_t;
}

vec flip_y(vec v) {
    vec v_t;
    v_t.x = v.x;
    v_t.y = -1 * v.y;
    return v_t;
}

vec flip(vec v) {
    vec v_t;
    v_t.x = -1 * v.x;
    v_t.y = -1 * v.y;
    return v_t;
}

vec v_diff(vec v1, vec v2) {
    vec v_t;
    v_t.x = v2.x - v1.x;
    v_t.y = v2.y - v1.y;
    return v_t;
}

vec scale(vec v, double sf) {
    vec v_t;
    v_t.x = v.x * sf;
    v_t.y = v.y * sf;
    return v_t;
}

// not currently working??
vec norm(vec v) {
    vec v_t;
    v_t.x = ceil(v.x / vec_length(v));
    v_t.y = ceil(v.y / vec_length(v));
    return v_t;
}

vec transform(vec v, double xsf, double ysf) {
    vec v_t;
    v_t.x = v.x * xsf;
    v_t.y = v.y * ysf;
    return v_t;
}
