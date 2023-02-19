#include <stdio.h>
#include <stdlib.h>
#include "graphics.h"

int main(int argc, char** argv) {
    if(argc < 3) {
        printf("Please specify a canvas size: ./%s <width> <height>\n", argv[0]);
        exit(1);
    }
    init_canvas(atoi(argv[1]), atoi(argv[2]));
    draw_square(0,0,5,'#',false, NULL);
    return 0;
}
