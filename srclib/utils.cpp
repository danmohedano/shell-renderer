#include <math.h>
#include "../includes/utils.h"

void rotation(float x, float y, float z, float A, float B, float C, float *rx, float *ry, float *rz){
    *rx = x*cos(B)*cos(C) + y*cos(B)*sin(C) - z*sin(B);
    *ry = x*(-cos(A)*sin(C) + sin(A)*sin(B)*cos(C)) + y*(cos(A)*cos(C) + sin(A)*sin(B)*sin(C)) + z*sin(A)*cos(B);
    *rz = x*(sin(A)*sin(C) + cos(A)*sin(B)*cos(C)) + y*(-sin(A)*cos(C) + cos(A)*sin(B)*sin(C)) + z*cos(A)*cos(B);
}