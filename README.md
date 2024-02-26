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

8.- Identify key codes for future iteraction wiht images. Do it in 42 and in your home. I separated codes in two files `keys_mac.h` and `keys_ubuntu.h`

9.- Hooks setting differs from Mac to linux in event masks. Be aware of such circunstance.

For mac : 
```c 
	mlx_hook(w.win_ptr, ON_KEYDOWN, 0, &win_h_key_down, &w);
```
For linux:
```c
	mlx_hook(w.win_ptr, ON_KEYDOWN, (1L << 0), &win_h_key_down, &w);
```

https://www.youtube.com/watch?v=FFftmWSzgmk

# The complex numbers
I create a basic complex library to help me to simplify fractal formulas : create, add, multiply, absolutize (for the ship fractal) print ....

```c
typedef struct s_complex
{
	float	x;
	float	y;
}	t_complex;
```


## Three reference axis

I have to deal with 3 reference axis. The windows axis, the image axis, and the complex (real / imaginary axis)

This image helps us to get an idea about the window size required for this fractal. It will have a ratio aspect of 3:2 (600:400 || 900:600).




We need to shift de (0,0) origin from our window [(0,0), (600, 400)], situated in the left upper corner, to (400,200) or (600, 300). Then our image will become [(-400, 200), (200, -200)]

Additionally, a translation of pixel coordinates of the new window, [(-400, 200), (200, -200)] into fractal area [(-2, i), (1, -i)] 


win (0,0)

          x-------------------------------------------------------------------x
      	  |          ^                                                        |
   	  |          |                                                        |
   	  |          |                                                        |
   	  |          |                                                        |
   	  |        offsety                                                    |
   	  |          |                                                        |
   	  |          |   x(15, 7)                                             |
   	  |          |                                                        |
	  |          v img(0,0)                                               |
	  |<-offsetx>#........................................................|..................#
	  |          .                                                        |                  .
	  |          .                                                        |                  .
	  |          .                                                        |                  .
	  |          .                                                        |                  .
	  |          .                                                        |                  .
	  |          .                                                        |                  .
	  |          .                                                        |                  .
	  |          .               # (15,7)                                 |                  .
	  x-------------------------------------------------------------------xwin (600, 400)    .
	             .                                                                           .
	             .                                                                           .
	             .                                                                           .
	             .                                                                           .
		     #...........................................................................#

At zero zoom the relationship between win and img is 1:1

img2win transformation ==> x = # - offsets
win2img transformation ==> # = x + offsets

# Mandelbrot
![image](https://github.com/luismiguelcasadodiaz/fract-ol/assets/19540140/71151d52-f132-4459-a7dc-228fb8f0cac5)

## Julia

<img width="900" alt="image" src="https://github.com/luismiguelcasadodiaz/fract-ol/assets/19540140/ed492569-6722-4455-a8a7-71cb64c544e8">

<img width="900" alt="image" src="https://github.com/luismiguelcasadodiaz/fract-ol/assets/19540140/d9d74f45-8ea8-47fc-baaa-334d72dfb73b">

<img width="900" alt="image" src="https://github.com/luismiguelcasadodiaz/fract-ol/assets/19540140/a375cb1d-eefc-409b-845c-a4f65791ad2d">

<img width="900" alt="image" src="https://github.com/luismiguelcasadodiaz/fract-ol/assets/19540140/7c0e44b4-e4b7-4bc2-ac74-99f143b1ed72">

## Ship


<img width="900" alt="image" src="https://github.com/luismiguelcasadodiaz/fract-ol/assets/19540140/da99b372-dc25-4ed5-8684-782744a0482c">


# What i read/watch

[Monitor aspect ratio, dpi, resolution ](https://www.viewsonic.com/library/tech/monitor-resolution-aspect-ratio/)

[zooming & Panning](https://www.youtube.com/watch?v=ZQ8qtAizis4&t=1326s)



