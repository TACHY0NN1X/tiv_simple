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

**To Compile**
```
gcc -o <whatever-you-wanna-call-it> <source-file>
```
It has simple logic :\
[+] Load Image\
[+] Resize Image to fit terminal window\
[+] Get rgb value of pixel\
[+] Print Pixel using bash ansi color code\
```bash
\e[48;2;r;g;bm \e[0m
```
