#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "graphics.h"
#include "linalg.h"

int main(int argc, char** argv) {
    
    if(argc < 3) {
        printf("Proper usage: ./%s <width> <height>\n", argv[0]);
        exit(1);
    }

    int width = atoi(argv[1]);
    int height = atoi(argv[2]);
    char frame[width*height];
    init_canvas(width, height, frame);
    printf("\n");
    while(1) {
        draw_bounding_box(frame);
    }

    return 0;
}
