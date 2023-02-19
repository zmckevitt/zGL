#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "linalg.h"
#include "graphics.h"

#define FPS 60

int main(int argc, char** argv) {

    if(argc < 5) {
        printf("Please specify a canvas size and starting velocity:"
               " ./%s <width> <height> <vel x> <vel y>\n", argv[0]);
        exit(1);
    }

    srand(time(NULL));
    int width = atoi(argv[1]);
    int height = atoi(argv[2]);
    char frame[width*height];
    init_canvas(width, height, frame);
    vec pos = init_vec(rand() % width, rand() % height);
    vec vel = init_vec(atof(argv[3]), atof(argv[4])); 

    while(1) {
        pos = vec_sum(pos, vel);
        if(pos.x >= width || pos.x < 0) {
            vel = flip_x(vel);
            pos = vec_sum(pos, vel);
        }
        if(pos.y >= height || pos.y < 0) {
            vel = flip_y(vel);
            pos = vec_sum(pos, vel);
        }
        clear(frame);
        draw_bounding_box(frame);
        draw_char(pos.x, pos.y, '@', frame);

        usleep(1000*1000/FPS);
    }

    return 0;
}
