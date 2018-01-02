/**
 * C implementation of Ramer-Douglas-Peucker algorithm.
 *  The path that is to be simplified is assumed to be made
 *  out of points with integer coordinates.
 *
 * @author  Bruno Vandekerkhove
 * @version 1.0
 */

#include "geom.h"

/*
 * Simplify the given linked list of points assuming given epsilon.
 *
 * @param   start_point
 *          The starting point of the linked list of points to simplify.
 * @param   end_point
 *          The end point of the linked list of points to simplify.
 * @param   epsilon
 *          The maximum distance for points to be used when simplifying.
 */
void simplify(point_2d *start_point, point_2d *end_point, double epsilon);