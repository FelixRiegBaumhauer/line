#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
  //the left half
  if(x0>x1){
    draw_line(x1, y1, x0, y0, s, c);
  }//octants 1,2,7,8
  else{
    //ocatant 7,8
    if(y0<=y1){
      if((x1-x0)>(y1-y0)){
	draw_basic_line(x0,y0,x1,y1,s,c,0,0);
      }
      else{
	draw_basic_line(x0,y0,x1,y1,s,c,1,0);
      }
    }
    //octants 1,2
    else{
      if((x1-x0)>(y0-y1)){
	draw_basic_line(x0,y0,x1,y1,s,c,0,1);
      }
      else{
	draw_basic_line(x0,y0,x1,y1,s,c,1,1);
      }
    }
    
  }
}


//this is the basic version of the function
//it works for octant 1, if we cahnge some variable, as negate the appropriate
//values, we can effectivelly shift and reflect our line
//my line algorithm uses this one function and simpily reflects and shifts the line created in the 1st quadrant
void draw_basic_line(int x0, int y0, int x1, int y1, screen s, color c, int swap, int bottom) {

  //int swap is 0 or 1, if 1 you switch them (x and y)
  //int bottom is 0 if not in octant 7,8, 1 if it is in octant 7 or 8

  if(bottom == 1){
    //shift down by 500
    y0=y0-500;
    y1=y1-500;
    
    //reflect y=0
    y0=-1*y0;
    y1=-1*y1;
  }

  if(swap == 1){
      int zero_hold  = x0;
      int one_hold = x1;
      
      x0=y0;
      y0=zero_hold;
      x1=y1;
      y1=one_hold;
  }
  
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
    if(swap == 0){
      if(bottom == 1){
	plot(s, c, x, -1*y+500);
      }
      else{
	plot(s, c, x, y);
      }
    }
    else{
      if(bottom == 1){
	plot(s, c, y, -1*x+500);
      }
      else{
	plot(s, c, y, x);
      }
    }
    if(d>0){
      y++;
      d+=B;
    }
    x++;
    d+=A;
  }
  
}

/*
This is the solution for the 1st octant only
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
*/


/*

These are the various draw_line fxns for the various quadrants,
these fxns are not neede anymore, but are a proof of concept



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


void draw_line_8(int x0, int y0, int x1, int y1, screen s, color c) {

  //shift down by 500
  y0=y0-500;
  y1=y1-500;

  //reflect y=0
  y0=-1*y0;
  y1=-1*y1;
  
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
    //when we plot we revert them
    plot(s, c, x, -1*y+500);

    if(d>0){
      y++;
      d+=B;
    }
    x++;
    d+=A;
  }
  
}

void draw_line_7(int x0, int y0, int x1, int y1, screen s, color c) {
  
  //shift down by 500
  y0=y0-500;
  y1=y1-500;

  //reflect y=0
  y0=-1*y0;
  y1=-1*y1;

  int zero_hold  = x0;
  int one_hold = x1;

  x0=y0;
  y0=zero_hold;
  x1=y1;
  y1=one_hold;
  
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
    //when we plot we revert them
    plot(s, c, y, -1*x+500);

    if(d>0){
      y++;
      d+=B;
    }
    x++;
    d+=A;
  }
  
}
*/



/*

//This is the solution based on the work we did in class, it also works


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
*/
