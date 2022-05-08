#ifndef MAZE_DATA
#define MAZE_DATA

#include "lcdutils.h"
extern char maze_count;
extern char maze_num;
//stored as 0000 rldu
extern const u_char maze_data[1][11][10];

extern const u_char mazeStartRow;
extern const u_char mazeStartCol;


/*
  row and col refer to position within the maze.
  automatically reads maze data to determine where to draw walls.
 */
void draw_tile(u_char row, u_char col);


#endif
