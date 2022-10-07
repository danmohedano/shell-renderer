#include <iostream>
#include <unistd.h>
#include <string.h>
#import <math.h>
#include "../includes/render.h"
#include "../includes/utils.h"

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
    float x, y, z;

    // Cube variables
    float cube_dim = 35;
    float A = 0;
    float B = 0;
    float C = 0;

    while (true){
        memset(frame, ' ', S_WIDTH * S_HEIGHT);
        memset(zbuff, 0, S_WIDTH * S_HEIGHT * sizeof(float));

        // Compute frame
        for (float i = -cube_dim; i < cube_dim; i += increments){
            for (float j = -cube_dim; j < cube_dim; j += increments){
                // Face F
                x = i; y = j; z = -cube_dim;
                rotation(x, y, z, A, B, C, &x, &y, &z);
                render_point(frame, zbuff, S_WIDTH, S_HEIGHT, k1, k2, x, y, z, '@');
                // Face R
                x = cube_dim; y = j; z = i;
                rotation(x, y, z, A, B, C, &x, &y, &z);
                render_point(frame, zbuff, S_WIDTH, S_HEIGHT, k1, k2, x, y, z, '~');
                // Face L
                x = -cube_dim; y = j; z = -i;
                rotation(x, y, z, A, B, C, &x, &y, &z);
                render_point(frame, zbuff, S_WIDTH, S_HEIGHT, k1, k2, x, y, z, '~');
                // Face B
                x = -i; y = j; z = cube_dim;
                rotation(x, y, z, A, B, C, &x, &y, &z);
                render_point(frame, zbuff, S_WIDTH, S_HEIGHT, k1, k2, x, y, z, '@');
                // Face U
                x = i; y = cube_dim; z = j;
                rotation(x, y, z, A, B, C, &x, &y, &z);
                render_point(frame, zbuff, S_WIDTH, S_HEIGHT, k1, k2, x, y, z, '+');
                // Face D
                x = i; y = -cube_dim; z = -j;
                rotation(x, y, z, A, B, C, &x, &y, &z);
                render_point(frame, zbuff, S_WIDTH, S_HEIGHT, k1, k2, x, y, z, '+');
            }
        }

        // Clear terminal
        printf("\x1b[H");
        // Print frame
        for (int k = 0; k < S_WIDTH * S_HEIGHT; ++k){
            putchar(k % S_WIDTH ? frame[k] : 10);
        }

        A += 0.1;
        B += 0.05;
        C += 0.05;
        usleep(100);
    }

    return 0;
}