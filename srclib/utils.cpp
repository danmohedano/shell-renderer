#include <math.h>
#include "../includes/utils.h"

/*void rotation(float x, float y, float z, float A, float B, float C, float *rx, float *ry, float *rz){
    *rx = x*cos(B)*cos(C) + y*cos(B)*sin(C) - z*sin(B);
    *ry = x*(-cos(A)*sin(C) + sin(A)*sin(B)*cos(C)) + y*(cos(A)*cos(C) + sin(A)*sin(B)*sin(C)) + z*sin(A)*cos(B);
    *rz = x*(sin(A)*sin(C) + cos(A)*sin(B)*cos(C)) + y*(-sin(A)*cos(C) + cos(A)*sin(B)*sin(C)) + z*cos(A)*cos(B);
}*/

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