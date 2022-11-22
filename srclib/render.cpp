#include "../includes/render.h"
#include "../includes/utils.h"

void render_point(char *frame, float *zbuff, int s_width, int s_height, float k1, float k2, float *pos, char c){
    // Compute pixel points in the simulated screen
    pos[2] += k2;
    float ooz = 1 / pos[2];
    int xp = (int) (s_width / 2 + k1 * pos[0] * ooz * 2);  // Takes into account that chars are usually are twice as tall compared to their width
    int yp = (int) (s_height / 2 + k1 * pos[1] * ooz);

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


void render_point_luminance(char *frame, float *zbuff, int s_width, int s_height, float k1, float k2, float *pos, float *normal, float *light){
    // Compute pixel points in the simulated screen
    pos[2] += k2;
    float ooz = 1 / pos[2];
    int xp = (int) (s_width / 2 + k1 * pos[0] * ooz * 2);  // Takes into account that chars are usually are twice as tall compared to their width
    int yp = (int) (s_height / 2 + k1 * pos[1] * ooz);

    // Compute buffer index from the coordinates
    int idx = xp + yp * s_width;

    // Compute luminance
    normalize(light);  // Needed for correct luminance calculation
    float lum = normal[0] * light[0] + normal[1] * light[1] + normal[2] * light[2];
    int lum_index = (int) (lum * LUMINANCE_LEN);

    // Update buffers when valid
    if (0 < idx && idx < s_height * s_width){
        if (ooz >= zbuff[idx]){
            if (lum >= 0){
                zbuff[idx] = ooz;
                frame[idx] = LUMINANCE_STR[lum_index];
            } else {
                zbuff[idx] = ooz;
                frame[idx] = '.';
            }
            
        }
    }
}
