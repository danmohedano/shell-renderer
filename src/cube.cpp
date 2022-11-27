#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include "render/render.h"
#include "utils/utils.h"

#define S_WIDTH 200
#define S_HEIGHT 64

int main(void){
    // Screen variables
    float zbuff[S_WIDTH * S_HEIGHT];
    char frame[S_WIDTH * S_HEIGHT];
    float k1 = 50;
    float k2 = 120;

    // Rendering variables
    float increments = 0.35;
    float pos[3] = {0};

    // Cube variables
    float cube_dim = 35;
    float angles[3] = {0};

    while (true){
        memset(frame, ' ', S_WIDTH * S_HEIGHT);
        memset(zbuff, 0, S_WIDTH * S_HEIGHT * sizeof(float));

        // Compute frame
        for (float i = -cube_dim; i < cube_dim; i += increments){
            for (float j = -cube_dim; j < cube_dim; j += increments){
                // Face F
                pos[0] = i; pos[1] = j; pos[2] = -cube_dim;
                rotation(pos, angles, pos);
                render_point(frame, zbuff, S_WIDTH, S_HEIGHT, k1, k2, pos, '@');
                // Face R
                pos[0] = cube_dim; pos[1] = j; pos[2] = i;
                rotation(pos, angles, pos);
                render_point(frame, zbuff, S_WIDTH, S_HEIGHT, k1, k2, pos, '~');
                // Face L
                pos[0] = -cube_dim; pos[1] = j; pos[2] = -i;
                rotation(pos, angles, pos);
                render_point(frame, zbuff, S_WIDTH, S_HEIGHT, k1, k2, pos, '~');
                // Face B
                pos[0] = -i; pos[1] = j; pos[2] = cube_dim;
                rotation(pos, angles, pos);
                render_point(frame, zbuff, S_WIDTH, S_HEIGHT, k1, k2, pos, '@');
                // Face U
                pos[0] = i; pos[1] = cube_dim; pos[2] = j;
                rotation(pos, angles, pos);
                render_point(frame, zbuff, S_WIDTH, S_HEIGHT, k1, k2, pos, '+');
                // Face D
                pos[0] = i; pos[1] = -cube_dim; pos[2] = -j;
                rotation(pos, angles, pos);
                render_point(frame, zbuff, S_WIDTH, S_HEIGHT, k1, k2, pos, '+');
            }
        }

        // Clear terminal
        printf("\x1b[H");
        // Print frame
        for (int k = 0; k < S_WIDTH * S_HEIGHT; ++k){
            putchar(k % S_WIDTH ? frame[k] : 10);
        }

        angles[0] += 0.1;
        angles[1] += 0.05;
        angles[2] += 0.05;
        usleep(100);
    }

    return 0;
}