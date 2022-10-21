#include <iostream>
#include <unistd.h>
#include <string.h>
#import <math.h>
#include "../includes/render.h"
#include "../includes/utils.h"

#define S_WIDTH 150
#define S_HEIGHT 50
#define PI 3.14159265

int main(void){
    // Screen variables
    float zbuff[S_WIDTH * S_HEIGHT];
    char frame[S_WIDTH * S_HEIGHT];
    float k1 = 50;
    float k2 = 120;

    // Rendering variables
    float increments = 0.5;
    float x, y, z;

    // Cube variables
    float cube_dim = 20;
    float A = PI/4;
    float B = PI/4;
    float C = 0;

    // Lighting variables
    float lx = -1.0/sqrt(3);
    float ly = -1.0/sqrt(3);
    float lz = -1.0/sqrt(3);

    // Normal vector variables
    float nx, ny, nz;

    while (true){
        memset(frame, ' ', S_WIDTH * S_HEIGHT);
        memset(zbuff, 0, S_WIDTH * S_HEIGHT * sizeof(float));

        // Compute frame
        for (float i = -cube_dim; i < cube_dim; i += increments){
            for (float j = -cube_dim; j < cube_dim; j += increments){
                // Face F
                x = i; y = j; z = -cube_dim;
                nx = 0; ny = 0; nz = -1;
                rotation(x, y, z, A, B, C, &x, &y, &z);
                rotation(nx, ny, nz, A, B, C, &nx, &ny, &nz);
                render_point_luminance(frame, zbuff, S_WIDTH, S_HEIGHT, k1, k2, x, y, z, nx, ny, nz, lx, ly, lz);
                // Face R
                x = cube_dim; y = j; z = i;
                nx = 1; ny = 0; nz = 0;
                rotation(x, y, z, A, B, C, &x, &y, &z);
                rotation(nx, ny, nz, A, B, C, &nx, &ny, &nz);
                render_point_luminance(frame, zbuff, S_WIDTH, S_HEIGHT, k1, k2, x, y, z, nx, ny, nz, lx, ly, lz);
                // Face L
                x = -cube_dim; y = j; z = -i;
                nx = -1; ny = 0; nz = 0;
                rotation(x, y, z, A, B, C, &x, &y, &z);
                rotation(nx, ny, nz, A, B, C, &nx, &ny, &nz);
                render_point_luminance(frame, zbuff, S_WIDTH, S_HEIGHT, k1, k2, x, y, z, nx, ny, nz, lx, ly, lz);
                // Face B
                x = -i; y = j; z = cube_dim;
                nx = 0; ny = 0; nz = 1;
                rotation(x, y, z, A, B, C, &x, &y, &z);
                rotation(nx, ny, nz, A, B, C, &nx, &ny, &nz);
                render_point_luminance(frame, zbuff, S_WIDTH, S_HEIGHT, k1, k2, x, y, z, nx, ny, nz, lx, ly, lz);
                // Face U
                x = i; y = cube_dim; z = j;
                nx = 0; ny = 1; nz = 0;
                rotation(x, y, z, A, B, C, &x, &y, &z);
                rotation(nx, ny, nz, A, B, C, &nx, &ny, &nz);
                render_point_luminance(frame, zbuff, S_WIDTH, S_HEIGHT, k1, k2, x, y, z, nx, ny, nz, lx, ly, lz);
                // Face D
                x = i; y = -cube_dim; z = -j;
                nx = 0; ny = -1; nz = 0;
                rotation(x, y, z, A, B, C, &x, &y, &z);
                rotation(nx, ny, nz, A, B, C, &nx, &ny, &nz);
                render_point_luminance(frame, zbuff, S_WIDTH, S_HEIGHT, k1, k2, x, y, z, nx, ny, nz, lx, ly, lz);
            }
        }

        // Clear terminal
        printf("\x1b[H");

        // Print frame
        for (int k = 0; k < S_WIDTH * S_HEIGHT; ++k){
            putchar(k % S_WIDTH ? frame[k] : 10);
        }

        A += 0.2;
        B += 0.1;
        C += 0.05;
        //usleep(500000);
        usleep(100000);
    }

    return 0;
}