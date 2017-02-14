#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

/*
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

//222

void draw_line_2(int y0, int x0, int y1, int x1, screen s, color c) {
    
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
    plot(s, c, y, x);

    if(d>0){
      y++;
      d+=B;
    }
    x++;
    d+=A;
  }
  
}

*/


//////BAD METHOD:
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
  //[3-6]
  if(x0>x1){
    draw_line(x1, y1, x0, y0, s, c);
  }
  //else you in oct 1,2,7,8
  else{
    //7,8
    if(y0>y1){
      if(x1-x0 > y0-y1){//0
	draw_line_8(x0, y0, x1, y1, s, c);
      }
      else{
	draw_line_7(x0, y0, x1, y1, s, c);
      }
    }
    //1,2
    else{
      if(x1-x0 > y1-y0){//0
	draw_line_1(x0, y0, x1, y1, s, c);
      }
      else{
	draw_line_2(x0, y0, x1, y1, s, c);
      }
    }
  }
}

//Insert your line algorithm here
void draw_line_1(int x0, int y0, int x1, int y1, screen s, color c) {
    
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

//Insert your line algorithm here
void draw_line_2(int x0, int y0, int x1, int y1, screen s, color c) {   
  //needed variables
  int A;
  int B;

  int x = x0;
  int y = y0;

  //setup
  A = y1-y0;
  B = (-1) * (x1-x0);
  //for now we can subtract x1 from x0, as we ae dealing with octet 1

  int d = A + 2*B;

  A=2*A;
  B=2*B;
  
  while(y<=y1){
    plot(s, c, x, y);

    if(d<0){
      x++;
      d+=A;
    }
    y++;
    d+=B;
  }
}


//Insert your line algorithm here
void draw_line_7(int x0, int y0, int x1, int y1, screen s, color c) {
    
  //needed variables
  int A;
  int B;

  int x = x0;
  int y = y0;

  //setup
  A = y1-y0;
  B = (-1) * (x1-x0);
  //for now we can subtract x1 from x0, as we ae dealing with octet 1

  int d = A - 2*B;

  A=2*A;
  B=2*B;
  
  while(y>=y1){
    plot(s, c, x, y);

    if(d>0){
      x++;
      d+=A;
    }
    y--;
    d-=B;
  }
}


//Insert your line algorithm here
void draw_line_8(int x0, int y0, int x1, int y1, screen s, color c) {
  
  //needed variables
  int A;
  int B;

  int x = x0;
  int y = y0;

  //setup
  A = y1-y0;
  B = (-1) * (x1-x0);
  //for now we can subtract x1 from x0, as we ae dealing with octet 1

  int d = 2*A - B;

  A=2*A;
  B=2*B;
  
  while(x<=x1){
    plot(s, c, x, y);

    if(d<0){
      y--;
      d-=B;
    }
    x++;
    d+=A;
  }
  
}
