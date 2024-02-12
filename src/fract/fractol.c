/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 10:28:52 by luicasad          #+#    #+#             */
/*   Updated: 2024/02/12 13:32:19 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdlib.h>
#include "fractol.h"
#include "ft_printf.h"

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
	t_win	*w;
	t_point	ul;
	t_point	lr;

	w = win_init("Luis", 500, 500);
	if (!w)
		return (MLX_ERROR);
	ul.x = 20;
	ul.y = 20;
	lr.x = 50;
	lr.y = 70;
	win_pixel_put(*w, 20, 20, 0x0000FF00);
	draw_fractal(*w);
	mlx_put_image_to_window(w->mlx_ptr, w->win_ptr, w->img.img_ptr, 0, 0);
	mlx_loop_hook(w->mlx_ptr, &win_h_not_event, w);
	mlx_hook(w->win_ptr, ON_KEYDOWN, 0, &win_h_key_down, w);
	mlx_hook(w->win_ptr, ON_KEYUP, 0, &win_h_key_up, w);
	mlx_hook(w->win_ptr, ON_MOUSEDOWN, 0, &win_h_mouse_down, w);
	mlx_hook(w->win_ptr, ON_MOUSEUP, 0, &win_h_mouse_up, w);
	mlx_hook(w->win_ptr, ON_MOUSEMOVE, 0, &win_h_mouse_move, w);
	mlx_hook(w->win_ptr, ON_DESTROY, 0, &win_h_destroy, w);
	mlx_loop(w->mlx_ptr);
	return (0);
}
