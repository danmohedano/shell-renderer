#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "../includes/render.h"

#define S_WIDTH 144
#define S_HEIGHT 68

int main(void){
    float zbuff[S_WIDTH * S_HEIGHT];
    char frame[S_WIDTH * S_HEIGHT];
    float k1 = 40;
    float pos[3] = {0, 0, -49};

    float increments = 0.01;

    while (true){
        memset(frame, '.', S_WIDTH * S_HEIGHT);
        memset(zbuff, 0, S_WIDTH * S_HEIGHT * sizeof(float));

        // Compute frame
        for (float i = -10; i < 10; i += increments){
            for (float j = -10; j < 10; j += increments){
                pos[0] = i; pos[1] = j;
                render_point(frame, zbuff, S_WIDTH, S_HEIGHT, k1, 50, pos, '~');
            }
        }

        // Clear terminal
        printf("\x1b[H");
        // Print frame
        for (int k = 0; k < S_WIDTH * S_HEIGHT; ++k){
            putchar(k % S_WIDTH ? frame[k] : 10);
        }

        usleep(1000000);
    }

    return 0;
}