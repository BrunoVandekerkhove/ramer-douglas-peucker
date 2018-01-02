/**
 * C implementation of Ramer-Douglas-Peucker algorithm.
 *
 * @author  Bruno Vandekerkhove
 * @version 1.0
 */

#include <stdlib.h>
#include <math.h>

#include "simplify.h"

void simplify(point_2d *start_point, point_2d *end_point, double epsilon) {
    
    if (start_point == end_point || start_point == NULL || end_point == NULL || start_point->next == NULL)
        return; // Nothing to simplify
    
    // Initialization
    int dx = end_point->x - start_point->x;
    int dy = end_point->y - start_point->y;
    
    // Furthest point (updated throughout iteration)
    double d, dmax = 0.0; // Maximum distance of point from line through endpoints so far
    point_2d *furthest_point = start_point;
    
    // Loop through points between endpoints
    double norm = sqrt(dx * dx + dy * dy);
    point_2d *current_point = start_point->next;
    while (current_point != end_point) {
        
        // Calculate distance of current point to line between endpoints
        d = abs(dx * (start_point->y - current_point->y)
                   - dy * (start_point->x - current_point->x)) / norm;
        
        // Update if point lies further than other points
        if (d > dmax) {
            furthest_point = current_point;
            dmax = d;
        }
        
        // Next iteration
        current_point = current_point->next;
        
    }
    
    // Check if maximum distance deviates enough
    if (dmax > epsilon) { // Yes - point is to be kept, recursion applied
        simplify(start_point, furthest_point, epsilon);
        simplify(furthest_point, end_point, epsilon);
    }
    else { // No - only endpoints matter anymore
        
        // Free all points after start point
        point_2d *current_point = start_point->next, *previous_point;
        while (current_point != end_point) {
            previous_point = current_point;
            current_point = current_point->next;
            free(previous_point);
        }
        
        // Chain endpoints together
        start_point->next = end_point;
        
    }
    
}