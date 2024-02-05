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
# What i read

[Monitor aspect ratio, dpi, resolution ](https://www.viewsonic.com/library/tech/monitor-resolution-aspect-ratio/)
