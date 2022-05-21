# OpenGL 1.1

## Viewport

```c
void glViewport(GLint x, GLint y, GLsizei width, GLsizei height);
```

The `x` and `y` parameters specify the lower-left corner of the viewport within
the window. The `width` and `height` parameters specify the dimensions in 
pixels. The viewport defines the area within the window in actual screen 
coordinates that OpenGL can use to draw in. The current clipping volume is then
mapped to the new viewport.

## Clipping volume

_Aspect ratio_ is the ratio of the number of pixels along a unit of length in 
the vertical direction to the number of pixels along the same unit of length
in the horizontal direction. The width of the window divided by the height.

An aspect ratio of $1.0$ defines a square ratio. An aspect ratio of $0.5$ means 
that for every two pixels in the horizontal direction there is one pixel in the
vertical direction.