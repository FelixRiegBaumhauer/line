#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
    
  //needed variables
  int A;
  int B;

  int x = x0;
  int y = y0;

  //setup
  A = y1-y0;
  B = (-1) * (x1-x0);
  //for now we can subtract x1 from x0, as we ae dealing with octet 1

  int d = 2*A + B;

  A=2*A;
  B=2*B;
  
  while(x<=x1){
    plot(s, c, x, y);

    if(d>0){
      y++;
      d+=B;
    }
    x++;
    d+=A;
  }
  
}

