# tiv_simple
A Simple Terminal Image Viewer uses the **AWESOME** [STB single file header library](https://github.com/nothings/stb)
The concept is sooo **AWESOME**.

**HATS-OFF** to the authors.
Respect from the depth of my heart to them.
All I've done is made a brick from the fantastic
lego blocks, **I'm a NOOB**, Please consider
while reacting,

You like it, use it,
Don't like it, cool!

# **Setup :**
[+] No dependencies\
[+] Just make a directory named "stb" \
[+] Inside it download and place : \
(#) https://github.com/nothings/stb/blob/master/stb_image.h \
(#) https://github.com/nothings/stb/blob/master/stb_image_resize.h \
and done. you just compile this and run .

For C++ Sources\
**To Compile**
```
g++ -o <whatever-you-wanna-call-it> <source-file>
```
Or if you have *Make*
```
make <source-filename>
```
For C source\
**To Compile**
```
gcc -o <your-call> <source-file> -lm
```
The C source is much simpler, and half the
executable size

It has simple logic :\
[+] Load Image\
[+] Resize Image to fit terminal window\
[+] Get rgb value of pixel\
[+] Print Pixel using bash ansi color code
```bash
\e[48;2;r;g;bm \e[0m
```
A pixel is a space character with respective rgb value

There are two source files, tiv_simple & one with auto resize
In tiv_simple you need to specify the resize size
In auto_resize with the help of ioctl the window size is
found. The image resize's the image to dimensions of
```resize * resize```
Basically a square image

You can change this nature by editing height argument in resize function in the source
```c
int rz_height = w.ws_row ;
int rz_width = w.ws_col ;
stbir_resize_uint8(input_img, width, height,0,
                           pixels, rz_width, rz_height,0,
                           channels) ;
```
