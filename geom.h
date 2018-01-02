/**
 * Geometry tools.
 *
 * @author  Team Safier
 * @version 1.0
 */

#ifndef _GEOM_
#define _GEOM_

/*
 * 2D point referring to image location.
 */
typedef struct point_struct {
    int x; // Column
    int y; // Row
} point;

/*
 * 2D point referring to image location (to be used in linked list).
 */
typedef struct point_2d_struct {
    int x; // Column
    int y; // Row
    struct point_2d_struct *next;
} point_2d;

/*
 * 2D line referring to image locations.
 */
typedef struct line_struct {
    int x1;
    int y1;
    int x2;
    int y2;
} line;

/*
 * 2D line referring to image locations (to be used in linked list).
 */
typedef struct line_2d_struct {
    int x1;
    int y1;
    int x2;
    int y2;
    struct line_2d_struct *next;
} line_2d;

/*
 * 2D rectangle referring to image locations.
 */
typedef struct rectangle_struct {
    int min_x;
    int min_y;
    int max_x;
    int max_y;
} rectangle;

#endif