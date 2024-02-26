/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 09:56:29 by luicasad          #+#    #+#             */
/*   Updated: 2024/02/26 00:51:19 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_complex.h"
#include "fractol.h"
#include "mlx.h"
#include "ft_printf.h"

/******************************************************************************/
/**
   @file is_julia.c
   @brief is_julia() Calculates if z belongs to the orbit of c.

   @param[in]  z: a complex number to determine if belongs or not ot the orbit
   of the c complex number.
   @param[in]  c: a complex number to determine if z belongs to c's orbit.
   @param[in]  palette: a RGB integer to multiply by escape iterations.

   @details
   Loops MAX_ITERATIONS times calculating Zn = (Zn-1)2 + C while the real and
   the imaginary part of Zn are smaller than 2.

   if either the real or the imaginary part 'Escape' the boundaries (<= 2) then
   z does not belong to the julia set and deserves a color.
   if loop exhausts the iterations then z belongs to the Julia set and gets the
   black color.

   @author LMCD (Luis Miguel Casado Díaz)
 *****************************************************************************/
static void	is_julia(t_win w, int wx0, int wy0, int *n)
{
	t_complex	z0;
	t_complex	zn;
	t_complex	c;
	int			ix;
	int			iy;

	ix = wx0 + w.shift.x + w.img.lu.x;
	iy = -wy0 + w.shift.y + w.img.lu.y;
	*n = 0;
	c = w.img.z;
	z0 = create(ix * w.img.r_x / w.scale, iy * w.img.r_y / w.scale);
	while ((mod(z0) <= 4) && (*n <= w.iteractions))
	{
		zn = add(multiply(z0, z0), c);
		z0 = zn;
		(*n)++;
	}
}

/******************************************************************************/
/**
   @file is_julia.c
   @brief draw_julia() Calculates if z belongs to the orbit of c.

   @param[in]  w: awindow sruct with axis of coordinates and values to to draw
   the fractal.

   @details

   Loops from negative ys to positive y
   	loops from negative xs to positive x
		for each (x, y) 
			calculates iterations to define if (x, y) belongs to the set.	
            color (x, y) accordingly.

   @author LMCD (Luis Miguel Casado Díaz)
 *****************************************************************************/
void	draw_julia(t_win w)
{
	int	wx0;
	int	wy0;
	int	n;

	wy0 = w.lu.y;
	while (wy0 < w.rd.y)
	{
		wx0 = w.lu.x;
		while (wx0 < w.rd.x)
		{
			is_julia(w, wx0, wy0, &n);
			if (n <= w.iteractions)
				win_pixel_put(w, wx0, wy0, n * w.palette);
			else
				win_pixel_put(w, wx0, wy0, BLACK);
			wx0++;
		}
		wy0++;
	}
	mlx_put_image_to_window(w.mlx_ptr, w.win_ptr, w.img.img_ptr, 0, 0);
}
