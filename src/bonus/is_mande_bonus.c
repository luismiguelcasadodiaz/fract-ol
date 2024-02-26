/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_mande.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 09:13:17 by luicasad          #+#    #+#             */
/*   Updated: 2024/02/26 00:51:37 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_complex.h"
#include "fractol.h"
#include "ft_printf.h"
#include "mlx.h"

/******************************************************************************/
/**
   @file is_mande.c
   @brief is_mande() Calculates if z belongs to the orbit of c.

   @param[in]  z: a complex number to determine if belongs or not ot the orbit
   of the c complex number.
   @param[in]  palette: a RGB integer to multiply by escape iterations.

   @details
   Loops the 9 times calculating Zn = (Zn-1)2 + C.
   Verifies if it is a growing secuence.

   if it is not a growing secuence returns zero, (black color).
   if it is a growing secuence returns a color. A color made of the bigger
   number of the secuence module 255 * 255 * 255 (RGB NUM COLORS)

   @author LMCD (Luis Miguel Casado Díaz)
 *****************************************************************************/
/*
int	is_mande(t_complex c, t_complex z0, int palette)
{
	t_complex	zn;
	short		n;

	n = 0;
	while ((z0.x <= 2) && (z0.y <= 2) && (n <= MAX_ITERATIONS))
	{
		zn = add(multiply(z0, z0), c);
		z0 = zn;
		n++;
	}
	if (n <= MAX_ITERATIONS)
		return (n * palette);
	else
		return (BLACK);
}
*/

static void	is_mande(t_win w, int wx0, int wy0, int *n)
{
	t_complex	z0;
	t_complex	zn;
	t_complex	c;
	int			ix;
	int			iy;

	ix = wx0 + w.shift.x + w.img.lu.x;
	iy = -wy0 + w.shift.y + w.img.lu.y;
	*n = 0;
	z0 = w.img.z;
	c = create(ix * w.img.r_x / w.scale, iy * w.img.r_y / w.scale);
	while ((mod(z0) <= 4) && (*n <= w.iteractions))
	{
		zn = add(multiply(z0, z0), c);
		z0 = zn;
		*n = *n + 1;
	}
}

/******************************************************************************/
/**
   @file is_mande.c
   @brief draw_mande() Calculates if z belongs to the orbit of c.

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
void	draw_mande(t_win w)
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
			is_mande(w, wx0, wy0, &n);
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
