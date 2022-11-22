#ifndef UTILS_H
#define UTILS_H

/**
 * Rotates a point with the provided angles.
 * @brief Rotation of a point.
 * @param pos Point to rotate in 3D space.
 * @param angles Angles to apply the rotations with.
 * @param res Result of the rotation (could be the same array as the `pos` argument).
 */
void rotation(float *pos, float *angles, float *res);

/**
 * Normalizes the input vector
 * @brief Normalizes the input vector.
 * @param vec Vector to normalize.
 */
void normalize(float *vec);
#endif