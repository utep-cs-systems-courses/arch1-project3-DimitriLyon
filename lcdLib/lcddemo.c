/** \file lcddemo.c
 *  \brief A simple demo that draws a string and square
 */

#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"

/** Initializes everything, clears the screen, draws "hello" and a square */
int
main()
{
  configureClocks();
  lcd_init();
  u_char width = screenWidth, height = screenHeight;

  clearScreen(COLOR_AQUAMARINE);

  u_char row = 20;
  u_char col = 40;
  
  for (char i = 0; i < 60; i++) {
    drawPixel(col, row, 0x000f);
    row++;
    if (i % 2 == 0) {
      col++;
    }
  }

  for (u_char i = 0; i < 30; i++) {
    drawPixel(col, row, COLOR_RED);
    row++;
    col--;
  }

  for (u_char i = 0; i < 90; i++) {
    drawPixel(col, row, COLOR_RED);
    row--;
  }
  
}
