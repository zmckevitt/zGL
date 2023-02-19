#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "linalg.h"
#include "graphics.h"

#define FPS 60

double rand_vel(double speed) {

    double value = speed;

    if(rand() % 2 == 0) {
        return value;
    }
    else {
        return -1 * value;
    }
}

int main(int argc, char** argv) {

    if(argc < 5) {
        printf("Please specify a canvas size, speed, and density:"
               " ./%s <width> <height> <speed> <density>\n", argv[0]);
        exit(1);
    }

    srand(time(NULL));
    int width = atoi(argv[1]);
    int height = atoi(argv[2]);
    char frame[width*height];
    init_canvas(width, height, frame);

    int n_particles = atoi(argv[4]);
    vec particles[n_particles];
    vec velocities[n_particles];

    for(int i=0; i<n_particles; ++i) {
        particles[i] = init_vec(rand() % width, rand() % height);
        velocities[i] = init_vec(rand_vel(atof(argv[3])), rand_vel(atof(argv[3]))); 
    }
    

    while(1) {
        clear(frame);
        draw_bounding_box(frame);
        for(int i=0; i<n_particles; ++i) {

            particles[i] = vec_sum(particles[i], velocities[i]);
            if(particles[i].x >= width || particles[i].x < 0) {
                velocities[i] = flip_x(velocities[i]);
                particles[i] = vec_sum(particles[i], velocities[i]);
            }
            if(particles[i].y >= height || particles[i].y < 0) {
                velocities[i] = flip_y(velocities[i]);
                particles[i] = vec_sum(particles[i], velocities[i]);
            }
            draw_char(particles[i].x, particles[i].y, '@', frame);
        }

        usleep(1000*1000/FPS);
    }

    return 0;
}
