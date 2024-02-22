/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_white.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 09:56:29 by luicasad          #+#    #+#             */
/*   Updated: 2024/02/22 13:31:42 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"

/******************************************************************************/
/**
   @file is_white.c
   @brief draw_white() Draws a white screen when required to draw a non coded
   fractal.

   @param[in]  w: a window struct to draw the fractal.

   @details

   Loops from left uppper y coordinate to right down y coordinate
   	loops from left uppeer x coordinate to right down x coordinate
		for each (x, y) 
            set color (x, y) to WHITE.

   @author LMCD (Luis Miguel Casado Díaz)
 *****************************************************************************/
void	draw_white(t_win w)
{
	int			wx0;
	int			wy0;

	wy0 = w.lu_y;
	while (wy0 < w.rd_y)
	{
		wx0 = w.lu_x;
		while (wx0 < w.rd_x)
		{
			win_pixel_put(w, wx0, wy0, WHITE);
			wx0++;
		}
		wy0++;
	}
	mlx_put_image_to_window(w.mlx_ptr, w.win_ptr, w.img.img_ptr, 0, 0);
	mlx_string_put(w.mlx_ptr, w.win_ptr, 10, 10, 0x00FF0000, "I can not render it");
}
