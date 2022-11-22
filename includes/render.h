#ifndef RENDER_H
#define RENDER_H

#define LUMINANCE_STR ",-~:;=!*#$"
#define LUMINANCE_LEN 10

/**
 * Renders a single point in the screen provided as the character given.
 * @brief Single point simple renderer.
 * @param frame A character buffer representing the rendered frame.
 * @param zbuff A ZBuffer containing the depths of the points.
 * @param s_width Screen width.
 * @param s_height Screen height.
 * @param k1 Distance from the camera to the screen.
 * @param k2 Distance from the camera to the object.
 * @param pos Coordinates of the point in 3D space.
 * @param c Character to use to represent the point in the frame.
 */
void render_point(char *frame, float *zbuff, int s_width, int s_height, float k1, float k2, float *pos, char c);

/**
 * Renders a single point in the screen applying luminance.
 * @brief Single point simple renderer.
 * @param frame A character buffer representing the rendered frame.
 * @param zbuff A ZBuffer containing the depths of the points.
 * @param s_width Screen width.
 * @param s_height Screen height.
 * @param k1 Distance from the camera to the screen.
 * @param k2 Distance from the camera to the object.
 * @param pos Coordinates of the point in 3D space.
 * @param normal Normal vector of the surface being rendered.
 * @param light Light vector to calculate the luminance.
 * @param c Character to use to represent the point in the frame.
 */
void render_point_luminance(char *frame, float *zbuff, int s_width, int s_height, float k1, float k2, float *pos, float *normal, float *light);

#endif