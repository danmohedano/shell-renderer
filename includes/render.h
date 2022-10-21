#ifndef RENDER_H
#define RENDER_H

#define LUMINANCE_STR ",-~:;=!*#$"

/**
 * Renders a single point in the screen provided as the character given. Does 
 * not take into account luminance.
 * @brief Single point simple renderer.
 * @param frame A character buffer representing the rendered frame.
 * @param zbuff A ZBuffer containing the depths of the points.
 * @param s_width Screen width.
 * @param s_height Screen height.
 * @param k1 Distance from the camera to the screen.
 * @param k2 Distance from the camera to the object.
 * @param x Coordinate x of the point.
 * @param y Coordinate y of the point.
 * @param z Coordinate z of the point.
 * @param c Character to use to represent the point in the frame.
 */
void render_point(char *frame, float *zbuff, int s_width, int s_height, float k1, float k2, float x, float y, float z, char c);


void render_point_luminance(char *frame, float *zbuff, int s_width, int s_height, float k1, float k2, float x, float y, float z, float nx, float ny, float nz, float lx, float ly, float lz);

#endif