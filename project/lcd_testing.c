#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"
#include "maze.h"


u_int bg = COLOR_BLACK;

void test_arrows();
void draw_maze();
void draw_tiles();
int main() {
  configureClocks();
  lcd_init();
  clearScreen(bg);
  drawPixel(0,0,COLOR_DARK_GREEN);
  drawPixel(127,159, COLOR_DARK_GREEN);
  test_arrows();
  
  drawString5x7(5,0,"Maze 1", COLOR_STEEL_BLUE, COLOR_BLACK);
  
  draw_maze();
  draw_tiles();
  return 0;
}

void draw_tiles() {
  for(char r = 0; r < 11; r++) {
    for (char c = 0; c < 10; c++) {
      draw_tile(r,c);
    }
  }
}

void draw_maze() {
  /*128 wide
    10 pixel cells?
    12 cells on a screen
    1 cell + 4 pixels on each side as border
    10 wide maze max
    160 tall
    want 7 pixels on top
    using bottom 15 for controls
    leaves me with 138 usable pixels
    use 14 pixels top and bottom buffer
    110 pixels for maze
    11 cells
    buffer is from 
    col 0 to 13 and 114 to 127
    row 7 to 20 and 132 to 144
    maze can be rendered from
    col 14 to 113
    row 21 to 131
  */
  //use void fillRectangle(u_char colMin, u_char rowMin, u_char width, u_char height, u_int colorBGR);

  //draw buffer first
  u_char bufferStartCol = 0, bufferStartRow = 7, bufferEndCol = 127, bufferEndRow = 144;
  u_char bufferWidth = bufferEndCol - bufferStartCol + 1; //128
  u_char bufferHeight = bufferEndRow - bufferStartRow + 1; //139
  fillRectangle(bufferStartCol, bufferStartRow, bufferWidth, bufferHeight, COLOR_DEEP);
  
  //draw maze
  u_char mazeHeight = 110, mazeWidth = 100;
  fillRectangle(mazeStartCol, mazeStartRow, mazeWidth, mazeHeight, COLOR_GOLD);
}

void test_arrows() {
  u_char width = screenWidth, height = screenHeight;
  char *arrow_test = "SW1";
  drawString5x7(8, 145, arrow_test, COLOR_CYAN, bg);
  drawChar5x7(14, screenHeight - 7, 0x80, COLOR_CYAN, bg);
  arrow_test = "SW2";
  drawString5x7(40, 145, arrow_test, COLOR_CYAN, bg);
  drawChar5x7(46, screenHeight - 7, 0x81, COLOR_WHITE, bg);
  arrow_test = "SW3";
  drawString5x7(71, 145, arrow_test, COLOR_CYAN, bg);
  drawChar5x7(77, screenHeight - 7, 0x82, COLOR_GREEN, bg);
  arrow_test = "SW4";
  drawString5x7(103, 145, arrow_test, COLOR_CYAN, bg);
  drawChar5x7(109, screenHeight - 7, 0x83, COLOR_RED, bg);
}
