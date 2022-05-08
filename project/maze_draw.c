#include <msp430.h>
#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"
#include "maze.h"


u_int maze_bg_c = COLOR_SEA_GREEN;
u_int maze_wall_c = COLOR_RED;

void draw_tile(u_char row, u_char col) {
  //Get pixel positions to draw at from position of cell in maze.
  //cellPos * cellSize + offset 
  u_char draw_pos_row = row * 10 + mazeStartRow; 
  u_char draw_pos_col = col * 10 + mazeStartCol;
  fillRectangle(draw_pos_col, draw_pos_row, 10, 10, maze_bg_c);
  //Draw corners
  fillRectangle(draw_pos_col, draw_pos_row, 2, 2, maze_wall_c);
  fillRectangle(draw_pos_col + 8, draw_pos_row, 2, 2, maze_wall_c);
  fillRectangle(draw_pos_col, draw_pos_row + 8, 2, 2, maze_wall_c);
  fillRectangle(draw_pos_col + 8, draw_pos_row + 8, 2, 2, maze_wall_c);

  u_char cell_data = maze_data[maze_num][row][col];
  if (!(cell_data & 1)) { // can't go up
    fillRectangle(draw_pos_col + 2, draw_pos_row, 6, 2, maze_wall_c);
  }
  if (!(cell_data & 2)) {//can't go down
    fillRectangle(draw_pos_col + 2, draw_pos_row + 8, 6, 2, maze_wall_c);
  }
  if (!(cell_data & 4)) {//can't go left
    fillRectangle(draw_pos_col, draw_pos_row + 2, 2, 6, maze_wall_c);
  }
  if (!(cell_data & 8)) {//can't go right
    fillRectangle(draw_pos_col + 8, draw_pos_row + 2, 2, 6, maze_wall_c);
  }
}
