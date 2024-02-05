/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 10:28:52 by luicasad          #+#    #+#             */
/*   Updated: 2024/02/05 22:00:53 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdlib.h>
#include "fractol.h"
#include <stdio.h>

/* ************************************************************************** */
/**
   @file main.c
   @brief main() helps tha author to learnt minilibx

   @param[in]  s: The stack to calculate value's future positions.

   @details
   mlx_init() initializes the conexion with the windows enviroment, eithe X
   or opengl.

   mlx_init returns a void * pointer wha have to check for error.

   Loops the stack. For each node loops the stack couting how manu values
   are lower than current (external loop node) node's value.

   @author LMCD (Luis Miguel Casado Díaz)
 *****************************************************************************/
//https://aurelienbrabant.fr/blog/events-with-the-minilibxi
//https://03-jon-perez.gitbook.io/coding-library/c/minilibx
//https://harm-smits.github.io/42docs/libs/minilibx

int	main(void)
{
	t_win	w1;
	t_win	w2;
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
		return (MLX_ERROR);
	w1.mlx_ptr = mlx_ptr;
	w1.w = 500;
	w1.h = 500;
	w1.title = "Luis";
	w1.win_ptr = mlx_new_window(w1.mlx_ptr, w1.w, w1.h, w1.title);
	if (w1.win_ptr == NULL)
	{
		free(w1.mlx_ptr);
		return (MLX_ERROR);
	}
	w1.img.w = w1.w;
	w1.img.h = w1.h;
	w1.img.img_ptr = mlx_new_image(w1.mlx_ptr, w1.img.w, w1.img.h);
	if (w1.img.img_ptr == NULL)
	{
		free(w1.win_ptr);
		free(w1.mlx_ptr);
		return (MLX_ERROR);
	}
	w1.img.addr = mlx_get_data_addr(w1.img.img_ptr,
			&w1.img.bits_per_pixel,
			&w1.img.line_length,
			&w1.img.endian);
	printf("win %s bit per pixel %d, line_length %d endian %d\n",
			w1.title,
			w1.img.bits_per_pixel,
			w1.img.line_length,
			w1.img.endian);
	win_pixel_put(w1, 20, 20,  0x0000FF00);
	mlx_put_image_to_window(w1.mlx_ptr, w1.win_ptr, w1.img.img_ptr, 0, 0);
	w2.mlx_ptr = mlx_ptr;
	w2.w = 700;
	w2.h = 700;
	w2.title = "Sandra";
	w2.win_ptr = mlx_new_window(w2.mlx_ptr, w2.w, w2.h, w2.title);
	if (w2.win_ptr == NULL)
		return (MLX_ERROR);
	w2.img.w = w2.w;
	w2.img.h = w2.h;
	w2.img.img_ptr = mlx_new_image(w2.mlx_ptr, w2.img.w, w2.img.h);
	if (w2.img.img_ptr == NULL)
	{
		free(w1.win_ptr);
		return (MLX_ERROR);
	}
	w2.img.addr = mlx_get_data_addr(w2.img.img_ptr,
			&w2.img.bits_per_pixel,
			&w2.img.line_length,
			&w2.img.endian);
	printf("win %s bit per pixel %d, line_length %d endian %d\n",
			w2.title,
			w2.img.bits_per_pixel,
			w2.img.line_length,
			w2.img.endian);
	mlx_loop_hook(w1.mlx_ptr, &win_h_not_event, &w1);
	mlx_key_hook(w1.win_ptr, &win_h_key_press, &w1);
	mlx_loop(w1.mlx_ptr);
	mlx_destroy_window(w1.mlx_ptr, w1.win_ptr);
//
//mlx_destroy_display(win1.mlx_ptr);
	//free(win1.mlx_ptr);
	return (0);
}
