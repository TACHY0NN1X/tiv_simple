/********************************
 * Port Of The Viewer to C Much *
 * More Simpler, Almost Half    *
 * The Executable Size          *
 * For Compiling '-lm' To Be    *
 * Added As A Compiler Flag     *
 ********************************/

#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include <sys/ioctl.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"
#define STB_IMAGE_RESIZE_IMPLEMENTATION
#include "stb/stb_image_resize.h"

void pixel_print( int r , int g , int b ){
   printf( "\e[48;2;%d;%d;%dm \e[0m" , r, g, b );
}

void print_image( unsigned char * image, int height, int width ){
   int index = 0;
   for ( int y = 0; y < height; y++ ){
      for ( int x = 0; x < width; x++ ){

         int r = image[ index++ ];
         int g = image[ index++ ];
         int b = image[ index++ ];

         pixel_print( r, g, b );
      }
   }
}

int main( int argc , char ** argv ){

   if ( argc < 2 || 2 < argc ){
      printf( " Usage : %s <path_to_img> \n" , argv[0] );
      printf( " A Simple Terminal Image Viewer \n" );
      printf( " Uses ANSI Escape codes for color \n" );
      exit(1);
   }

   char *filename = argv[ 1 ];
   int height, width, channels;

   unsigned char *image = stbi_load( filename, &width, &height, &channels, 3);
   if( image == NULL ) {
      printf( " Error In Loading The Image \n");
      printf( " Maybe Check For A Typo \n" );
      exit(1);
   }

   struct winsize w;
   ioctl(0, TIOCGWINSZ, &w);

   int resize = w.ws_col;

   unsigned char *pixels = ( unsigned char * )calloc( resize * resize * 3, sizeof( unsigned char ) );

   if ( pixels == NULL ){
      printf( " Memory For Execution Couldn't be Allocated \n" );
      exit( 1 );
   }

   stbir_resize_uint8( image, width, height,0,
                       pixels, resize, resize,0,
                       channels);

   print_image( pixels , resize, resize);

   free( pixels );

   return 0;
}
