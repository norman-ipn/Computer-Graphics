/*
 Produce/Create/Build an image

 Image Format: PPM (Plain PPM): P3 (RAW)

 Full HD resolution Image

 1920 x 1080 raster
 
*/
#include<iostream>

using namespace std;

void 
paint( int r, int g, int b, int n) {
  int i = 0;
  for(i = 0; i< n; i++) {
    cout<<(unsigned char)r; /* 8 bits per channel */
    cout<<(unsigned char)g;
    cout<<(unsigned char)b;
  }
}
int main(void) {
  int i = 0;
  cout<<"P6\n";
  cout<<"1920 1080 255\n";

  for(i=0;i<1080/3;i++) {
   paint(0,   255, 0,   1920/3);
   paint(255, 255, 255, 1920/3);
   paint(255, 0,   0,   1920/3);
  }
  for(i=0;i<1080/3;i++) {
   paint(0,   255, 0,   1920/3);
   paint(100, 50,  0,   1920/3);
   paint(255, 0,   0,   1920/3);
  }
  for(i=0;i<1080/3;i++) {
   paint(0,   255, 0,   1920/3);
   paint(255, 255, 255, 1920/3);
   paint(255, 0,   0,   1920/3);
  }

  return 0;
} 
