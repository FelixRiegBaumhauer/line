#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

int main() {

  screen s;
  color c;
 
  
  c.red = 0;
  c.green = MAX_COLOR;
  c.blue = 0;
  
  clear_screen(s);

  c.red = MAX_COLOR;
  c.green = MAX_COLOR;
  c.blue = MAX_COLOR;
  draw_line(1, 2, 278, 146, s, c);

  c.red = 120;
  c.green = MAX_COLOR;
  c.blue = 0;
  draw_line(56, 89, 432, 108, s, c);


  
  display(s);
  save_ppm(s, "lines.ppm");
  save_extension(s, "lines.png");
}  
