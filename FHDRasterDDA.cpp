#include<cstring>
#include<iostream>
#include<random>

using namespace std;

class FHDRaster {
  unsigned char data[1920][1080][3];
  public:
  FHDRaster(void) {
    memset(data, 0, 1920*1080*3);  
  }
  void
  setPixel(unsigned int x, unsigned int y, 
            unsigned char r, 
            unsigned char g, 
            unsigned char b) {
      if( x >= 1920 || y >= 1080) {
        return;
      }
      data[x][y][0] = r;
      data[x][y][1] = g;
      data[x][y][2] = b;
  }
  void
  write(void) {
   int x = 0;
   int y = 0;
   cout<<"P6\n1920 1080 255\n";
   for(y=0;y<1080;y++) {
     for(x=0;x<1920;x++) {
      cout<<data[x][y][0];
      cout<<data[x][y][1];
      cout<<data[x][y][2];
     } 
   }
  }
 void drawLine( 
  unsigned int x1, unsigned int y1, 
   unsigned int x2, unsigned int y2, 
    unsigned char r,
    unsigned char g,
    unsigned char b) {
      /* Line drawing algorith(s) */

      // Improvements pending to code....
      //  1. check x1 < x2 
      //  2. larger axis, y2-y1 > x2-x1
      //  The code/idea only works on the first octant.
      //  
     
      // line equation: 
      //    y = m*x + b   
      ///  if you change x, you get y values
      double m = (double)(y2-y1)/(double)(x2-x1); //slope
      double be = (double)y1 - (m*x1) ;
      unsigned int x = 0;
      unsigned int y = 0;

      // iteration:    x1 < x2      
      setPixel(x1, y1, r, g, b);
      setPixel(x2, y2, r, g, b);
       
      y = m*x1 + be; // stating value.
      for( x=x1+1 ; x<x2 ; x++) {
        //y = m*x + be; // Naive solution
        y = y + m;      // DDA (floating point addition)
                        // Bresehman (middle point)
                        //   idea: integer addition. 
                        //         just integer operations.
                        //  1 fp > ~7 integer operations
        setPixel(x, y, r, g, b);
      } 
  /*
      // DDA  -Digital Diffential Analysis
           y = m*x + be;      // 1st
      next y = m*(x+1) + be;  // 2nd
      next y = m*x + m + be
      next y = m*x + be + m
      next y = y + m  /// << result of the DDA.
   */
      
       
   
   }
};

/* testing */
int main(void) {
 FHDRaster * raster = new FHDRaster();
 unsigned int x = 0;
 unsigned int y = 0;
 unsigned char r = 0x00;
 unsigned char g = 0x00;
 unsigned char b = 0x00;
 int n = 0;
 /*
 default_random_engine generator;
 uniform_int_distribution<unsigned int> distX(0,1919);
 uniform_int_distribution<unsigned int> distY(0,1079);
 uniform_int_distribution<unsigned char> distC(0x00,0xff);

 for(n=0; n<100000; n++) {
   x = distX(generator);
   y = distY(generator);
   r = distC(generator);
   g = distC(generator);
   b = distC(generator);
   raster->setPixel(x,y, r, g, b);
 }
 */
 raster->drawLine(0,0, 1000, 1000, 255, 255, 255);
 raster->drawLine(0,0, 1000,  500, 255, 255, 255);
 raster->drawLine(0,0, 500,  1000, 255, 255, 255);
 raster->drawLine(0,0, 100,  1000, 255, 255, 255);

 raster->write();

 return 0;
}
