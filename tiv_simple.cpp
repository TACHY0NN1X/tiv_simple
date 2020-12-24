/*
 For unix like shells
 with xterm-256colors
 
 A simple image viewer not as advanced
 as imgcat, but simple
 
 [+] Setup :
 # No dependencies
 # Just make a directory named "stb"
 # Inside it download and place :
 (#) https://github.com/nothings/stb/blob/master/stb_image.h
 (#) https://github.com/nothings/stb/blob/master/stb_image_resize.h
 
 and done. you just compile this and run .
 
 The STB IMAGE LIBRARY is AWESOME ;
 maybe go and throw a star to the repo
 on github .
 (Not sponsered)
 
 All I've done is assemble a brick, 
 from lego pieces, if you like it, use
 it, don't like it, cool !
*/

#include <iostream>
#include <sstream>
#include <fstream>
#include <stdint.h>
#include <vector>

#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"
#define STB_IMAGE_RESIZE_IMPLEMENTATION
#include "stb/stb_image_resize.h"

bool loadimg(std::vector<unsigned char>& image, const std::string& filename, int& x, int& y, int& channels){

    unsigned char* data = stbi_load(filename.c_str(),&x,&y,&channels,3);

    if (data != nullptr){
        image = std::vector<unsigned char> (data, data + x*y*3) ;
    }
    stbi_image_free(data) ;
    return (data != nullptr) ;
}

void pixel_print(int r, int g, int b){
    std::cout << "\e[48;2;" << r << ";" << g << ";" << b << "m \e[0m" ;
}

void printimg(uint8_t* image, int width, int height){

    int index = 0 ;
    for (int y = 0; y < height; y++){
        for (int x = 0; x < width; x++){

            int r = image[index++] ;
            int g = image[index++] ;
            int b = image[index++] ;

            pixel_print(r,g,b) ;
        }
        std::cout << std::endl ;
    }
}

int main(int argc, char **argv){

    if (argc < 2 || argc > 2){
        std::cout << " Usage : " << argv[0] << " <filename>" << std::endl ;
        exit(1) ;
    }
    std::string filename = argv[1] ;

    int width, height ;
    std::vector<unsigned char> image ;
    int channels ;

    bool success = loadimg(image, filename, width, height, channels) ;

    if (success){
        /*
        std::cout << "Image Width : " << width << "\n" ;
        std::cout << "Image Height : " << height << "\n" ;
        std::cout << "Image Channels : " << channels << "\n" ;
        */
        
        uint8_t* input_img = new uint8_t[width*height*channels] ;

        int indx = 0 ;
        for (auto x : image){
            input_img[indx++] = static_cast<int>(x) ;
        }

        int resize ;

        std::cout << " Resize : " ;

        std::cin >> resize ;

        uint8_t* pixels = new uint8_t[resize*resize*channels];

        stbir_resize_uint8(input_img, width, height,0,
                           pixels, resize, resize,0,
                           channels) ;

        printimg(pixels, resize, resize) ;
        
        delete[] pixels ; //Last edit
        
    }else{
        std::cout << "No such file found (check for typo dude)" << std::endl ;
    }
    return 0 ;
}