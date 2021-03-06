#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"


int main() {

  screen s;
  color c;
  
  clear_screen(s);
  
  c.red = MAX_COLOR;
  c.green = MAX_COLOR;
  c.blue = MAX_COLOR;

   
  int i=0;
  for(i=0; i<=10; i++){
    draw_line(250,250,50*i, 500,s,c);
  }
  
  for(i=0; i<=10; i++){
    draw_line(250,250,50*i, 0,s,c);
  }

  for(i=0; i<=10; i++){
    draw_line(250,250,500,50*i,s,c);
  }

  for(i=0; i<=10; i++){
    draw_line(250,250,0,50*i,s,c);
  }


  /*

  draw_line(1, 2, 278, 146, s, c);
  draw_line_2(1, 1, 108, 446, s, c);
  draw_line_8(100,400,400,300,s,c);
  draw_line_7(100,400,200,200,s,c);
  */


  c.red = 0;
  c.green = MAX_COLOR;
  c.blue = 0;

  /*
  
  draw_line(100, 100, 400, 400, s, c);
  draw_line(300, 400, 0, 100, s, c);
  draw_line(100, 400, 400, 400, s, c);
  draw_line(100, 100, 100, 500, s, c);
  
  */

  display(s);
  save_ppm(s, "lines.ppm");
  save_extension(s, "lines.png");
}  
