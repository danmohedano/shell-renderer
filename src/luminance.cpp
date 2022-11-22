#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
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
    float increments = 1;
    float pos[3] = {0};

    // Cube variables
    float cube_dim = 20;
    float angles[3] = {PI/4, PI/4, 0};

    // Lighting variables
    float light[3] = {1, 0, -1};

    // Normal vector variables
    float normal[3] = {0};

    while (true){
        memset(frame, ' ', S_WIDTH * S_HEIGHT);
        memset(zbuff, 0, S_WIDTH * S_HEIGHT * sizeof(float));

        // Compute frame
        for (float i = -cube_dim; i < cube_dim; i += increments){
            for (float j = -cube_dim; j < cube_dim; j += increments){
                // Face F
                pos[0] = i; pos[1] = j; pos[2] = -cube_dim;
                normal[0] = 0; normal[1] = 0; normal[2] = -1;
                rotation(pos, angles, pos);
                rotation(normal, angles, normal);
                render_point_luminance(frame, zbuff, S_WIDTH, S_HEIGHT, k1, k2, pos, normal, light);
                // Face R
                pos[0] = cube_dim; pos[1] = j; pos[2] = i;
                normal[0] = 1; normal[1] = 0; normal[2] = 0;
                rotation(pos, angles, pos);
                rotation(normal, angles, normal);
                render_point_luminance(frame, zbuff, S_WIDTH, S_HEIGHT, k1, k2, pos, normal, light);
                // Face L
                pos[0] = -cube_dim; pos[1] = j; pos[2] = -i;
                normal[0] = -1; normal[1] = 0; normal[2] = 0;
                rotation(pos, angles, pos);
                rotation(normal, angles, normal);
                render_point_luminance(frame, zbuff, S_WIDTH, S_HEIGHT, k1, k2, pos, normal, light);
                // Face B
                pos[0] = -i; pos[1] = j; pos[2] = cube_dim;
                normal[0] = 0; normal[1] = 0; normal[2] = 1;
                rotation(pos, angles, pos);
                rotation(normal, angles, normal);
                render_point_luminance(frame, zbuff, S_WIDTH, S_HEIGHT, k1, k2, pos, normal, light);
                // Face U
                pos[0] = i; pos[1] = cube_dim; pos[2] = j;
                normal[0] = 0; normal[1] = 1; normal[2] = 0;
                rotation(pos, angles, pos);
                rotation(normal, angles, normal);
                render_point_luminance(frame, zbuff, S_WIDTH, S_HEIGHT, k1, k2, pos, normal, light);
                // Face D
                pos[0] = i; pos[1] = -cube_dim; pos[2] = -j;
                normal[0] = 0; normal[1] = -1; normal[2] = 0;
                rotation(pos, angles, pos);
                rotation(normal, angles, normal);
                render_point_luminance(frame, zbuff, S_WIDTH, S_HEIGHT, k1, k2, pos, normal, light);
            }
        }

        // Clear terminal
        printf("\x1b[H");

        // Print frame
        for (int k = 0; k < S_WIDTH * S_HEIGHT; ++k){
            putchar(k % S_WIDTH ? frame[k] : 10);
        }

        angles[0] += 0.2;
        angles[1] += 0.1;
        angles[2] += 0.05;
        //usleep(500000);
        usleep(100000);
    }

    return 0;
}