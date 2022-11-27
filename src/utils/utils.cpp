#include <math.h>
#include "utils.h"

void rotation(float *pos, float *angles, float *res){
    float temp_x, temp_y, temp_z;
    temp_x = pos[0]*cos(angles[1])*cos(angles[2]) + pos[1]*cos(angles[1])*sin(angles[2]) - pos[2]*sin(angles[1]);
    temp_y = pos[0]*(-cos(angles[0])*sin(angles[2]) + sin(angles[0])*sin(angles[1])*cos(angles[2])) + pos[1]*(cos(angles[0])*cos(angles[2]) + sin(angles[0])*sin(angles[1])*sin(angles[2])) + pos[2]*sin(angles[0])*cos(angles[1]);
    temp_z = pos[0]*(sin(angles[0])*sin(angles[2]) + cos(angles[0])*sin(angles[1])*cos(angles[2])) + pos[1]*(-sin(angles[0])*cos(angles[2]) + cos(angles[0])*sin(angles[1])*sin(angles[2])) + pos[2]*cos(angles[0])*cos(angles[1]);
    res[0] = temp_x;
    res[1] = temp_y,
    res[2] = temp_z;
}

void normalize(float *vec){
    float normal = sqrt(vec[0]*vec[0] + vec[1]*vec[1] + vec[2]*vec[2]);
    vec[0] = vec[0] / normal;
    vec[1] = vec[1] / normal;
    vec[2] = vec[2] / normal;
}