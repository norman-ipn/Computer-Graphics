#include<stdio.h>

int
main(void) {
 int x = 0;
 int y = 0;
 int x1 = 0;
 int y1 = 0;
 int x2 = 0;
 int y2 = 0;

 int dx = 0;
 int dy = 0;

 int p = 0;
 int k = 0;

 int updateUp = 0;
 int updateRight = 0;

 scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

 dx = x2 - x1;
 dy = y2 - y1;

 updateUp = 2*dy - 2*dx;
 updateRight = 2*dy;
 
 p = 2*dy - dx;
 
 printf(" k\t|\t(  x ,  y )\t|\tp\n");
 printf("%d\t|\t(  %d, %d )\t|\t%d\n", k++, x1, y1, p );

 for(x = x1+1, y = y1; x < x2 ; x++ ) {
   if(p <= 0) {
     p += updateRight;
   } else {
     p += updateUp;
     y++;
   }
   printf("%d\t|\t(  %d, %d )\t|\t%d\n", k++, x, y, p );
 }
 printf("%d\t|\t(  %d, %d )\t|\t-\n", k, x2, y2 );

 return 0;
}
