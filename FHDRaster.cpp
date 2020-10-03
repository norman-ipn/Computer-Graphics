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
      /*  ???   line drawing algorith(s) */
     // DDA, Bresenham -> parallel 
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

 raster->write();

 return 0;
}
