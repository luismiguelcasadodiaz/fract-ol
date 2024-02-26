# fract-ol
This project is about creating graphically beautiful fractals.

## First Steps
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

## The complex numbers
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

To support this three references i defined one struct for the image,

``` c
typedef struct s_img
{
	void		*img_ptr;
	char		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	t_point		size;
	t_point		lu;
	t_point		rd;
	int		x_0;
	int		y_0;
	float		real;
	float		imag;
	float		r_x;
	float		r_y;
	t_complex	z;
}	t_img;
```
and other for the window

```c
typedef struct s_win
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
	char		*title;
	t_point		size;
	t_point		lu;
	t_point		rd;
	t_point		md;
	t_point		mu;
	t_point		mm;
	int			zoom;
	float		scale;
	t_point		shift;
	int			palette;
	int			iteractions;
}				t_win;
```
## The fractal concept

It is a iterative calculation that uses the previous result of the same calculation

| Conjunto Mandelbrot       | Conjunto Julia de parametro c |
|:--------------------------|:------------------------------|
|                           |                               |
|z0   = 0                   |z0   = z                       |
|z1   = F(z0) = z0^2 + c    |z1   = F(z0) = z0^2 + c        |
|z2   = F(z1) = z1^2 + c    |z2   = F(z1) = z1^2 + c        |    
|       ...                 |                               |
|       ...                 |                               |
|zn+1 = F(zn) = zn^2 + c    |zn+1 = F(zn) = zn^2 + c        |

The higher the n, the higher resolution the fractal will have and the higher workload for yor computer.
The function loops thru n till MAX iterations or when the module of the Z complex is > 4. 

If mod(z) does not growth .....

c belongs to Mandelbrot set.

Initial z belongs to Juia set of parameter c.

In this case c (when Mandelbrot) or Z when (Julia) get BLACK color. Otherwise C or Z get a color from a palette. Ths color with the index of the nth iterations that made mod(z) > 4.

This image shows range of real an imaginary axis in the complex numbers world.

![image](https://github.com/luismiguelcasadodiaz/fract-ol/assets/19540140/71151d52-f132-4459-a7dc-228fb8f0cac5)

## Mandelbrot

<img width="900" alt="image" src="https://github.com/luismiguelcasadodiaz/fract-ol/assets/19540140/b5d1a9ff-39fe-40bd-b26d-e3d2f4431f45">

<img width="900" alt="image" src="https://github.com/luismiguelcasadodiaz/fract-ol/assets/19540140/6d9caa63-1f30-4787-9fc0-ffbb1e1a4c3a">

## zoom=55 n=55

<img width="900" alt="image" src="https://github.com/luismiguelcasadodiaz/fract-ol/assets/19540140/2255a427-47cb-456b-b604-f89bcfb11e26">

## zoom=80 n=100

<img width="900" alt="image" src="https://github.com/luismiguelcasadodiaz/fract-ol/assets/19540140/8db93869-72fa-4f3a-8089-c8bd022226e7">


## Julia

<img width="900" alt="image" src="https://github.com/luismiguelcasadodiaz/fract-ol/assets/19540140/ed492569-6722-4455-a8a7-71cb64c544e8">

<img width="900" alt="image" src="https://github.com/luismiguelcasadodiaz/fract-ol/assets/19540140/d9d74f45-8ea8-47fc-baaa-334d72dfb73b">

<img width="900" alt="image" src="https://github.com/luismiguelcasadodiaz/fract-ol/assets/19540140/a375cb1d-eefc-409b-845c-a4f65791ad2d">

<img width="900" alt="image" src="https://github.com/luismiguelcasadodiaz/fract-ol/assets/19540140/7c0e44b4-e4b7-4bc2-ac74-99f143b1ed72">

## Ship


<img width="900" alt="image" src="https://github.com/luismiguelcasadodiaz/fract-ol/assets/19540140/da99b372-dc25-4ed5-8684-782744a0482c">


## What i read/watch

[Monitor aspect ratio, dpi, resolution ](https://www.viewsonic.com/library/tech/monitor-resolution-aspect-ratio/)

[zooming & Panning](https://www.youtube.com/watch?v=ZQ8qtAizis4&t=1326s)


[one minilibx tutorial ](https://aurelienbrabant.fr/blog/getting-started-with-the-minilibx)

[other tutorial](https://03-jon-perez.gitbook.io/coding-library/c/minilibx)

[otheer minilibx tutorial ](https://harm-smits.github.io/42docs/libs/minilibx)

##  What i learnt.

In this proyect i started to used sanitize flag at compilation time. That helps me to find memory leaks and segmentation fault.

I added man pages to man path.

i discover vim -p *.c to open all files in the folder one shot.

There are differences betwenn keycodes in differente OS.
