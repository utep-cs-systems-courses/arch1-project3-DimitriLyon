#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"
#include "maze.h"
#include "player.h"

u_int bg = COLOR_BLACK;

void test_1() {
  configureClocks();
  lcd_init();
  clearScreen(bg);
  drawPixel(0,0,COLOR_DARK_GREEN);
  drawPixel(127,159, COLOR_DARK_GREEN);
  draw_directions();
  
  drawString5x7(5,0,"Maze 1", COLOR_STEEL_BLUE, COLOR_BLACK);
  
  draw_maze();
  draw_tiles();
  draw_player();
}

int main() {
  configureClocks();
  lcd_init();

  
  clearScreen(bg);
  fillRectangle(0,0,10,20,COLOR_BROWN);
  fillRectangle(0,5,10,2, 0x7bef);
  fillRectangle(0,7,10,2, 0x39e7);
  fillRectangle(0,13,10,2, 0x4a69);
 
  return 0;
}

