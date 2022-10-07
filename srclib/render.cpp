#include "../includes/render.h"

void render_point(char *frame, float *zbuff, int s_width, int s_height, float k1, float k2, float x, float y, float z, char c){
    // Compute pixel points in the simulated screen
    z += k2;
    float ooz = 1 / z;
    int xp = (int) (s_width / 2 + k1 * x * ooz * 2);  // Takes into account that chars are usually are twice as tall compared to their width
    int yp = (int) (s_height / 2 + k1 * y * ooz);

    // Compute buffer index from the coordinates
    int idx = xp + yp * s_width;

    // Update buffers when valid
    if (0 < idx && idx < s_height * s_width){
        if (ooz > zbuff[idx]){
            zbuff[idx] = ooz;
            frame[idx] = c;
        }
    }
}