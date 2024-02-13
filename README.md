# fract-ol
This project is about creating graphically beautiful fractals.

# First Steps
1.- Download libraries to `fract-ol/src` directory

minilibx-linux.tgz

minilibx_mms_beta.tgz

minilibx_opengl.tgz

2.- Unzip them with `gunzip filename.tgz` and extract files with `tar --extract -f filename.tar`

3.- Navigate to man folder of minilibx-linux. use `pwd`to know where you are and add it to ~/.manpath 

``` bash
MANDATORY_MANPATH /home/luis/Documentos/c/cursus/circle3/fract-ol/src/minilibx-linux/man
```

4.- Test `man mlx`, `man mlx_loop`, `man mlx_new_image`,  `man mlx_new_window` y `man mlx_pixel_put`

5.- Watch two introductory videos in the 42 intra net e-learnig section.

[Introduction to MinilibX](https://elearning.intra.42.fr/notions/minilibx/subnotions/mlx-introduction/videos/introduction-to-minilibx)

[MinilibX : Events](https://elearning.intra.42.fr/notions/minilibx/subnotions/mlx-events/videos/minilibx-events)

6.- Create libmlx.a library `./configure' from minilibx-linux.  `make -F Makefile.gen show` shows flags required for compiling in your environment.

7.- Play with the 3 windows `test/mlx-test` the configuration process has created and study `main.c` that created them. 

https://www.youtube.com/watch?v=FFftmWSzgmk


## Mandelbrot
This image helps us to get an idea about the window size required for this fractal. It will have a ratio aspect of 3:2 (600:400 || 900:600).


![image](https://github.com/luismiguelcasadodiaz/fract-ol/assets/19540140/71151d52-f132-4459-a7dc-228fb8f0cac5)

We need to shift de (0,0) origin from our window [(0,0), (600, 400)], situated in the left upper corner, to (400,200) or (600, 300). Then our window will become [(-400, 200), (200, -200)]

Additionally, a translation of pixel coordinates of the new window, [(-400, 200), (200, -200)] into fractal area [(-2, i), (1, -i)] 

# What i read

[Monitor aspect ratio, dpi, resolution ](https://www.viewsonic.com/library/tech/monitor-resolution-aspect-ratio/)
