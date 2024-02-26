/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fenetre.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 10:28:52 by luicasad          #+#    #+#             */
/*   Updated: 2024/02/26 12:31:39 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdlib.h>
#include "fractol.h"

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
	t_win	win1;
	t_win	win2;
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
		return (MLX_ERROR);
	win1.mlx_ptr = mlx_ptr;
	win1.win_ptr = mlx_new_window(win1.mlx_ptr, 500, 500, "LUIS");
	if (win1.win_ptr == NULL)
	{
		free(win1.mlx_ptr);
		return (MLX_ERROR);
	}
	mlx_loop_hook(win1.mlx_ptr, &win_h_not_event, &win1);
	mlx_key_hook(win1.win_ptr, &win_h_key_up, &win1);
	mlx_mouse_hook(win1.win_ptr, &win_h_mouse_down, &win1);
	mlx_loop(win1.mlx_ptr);
	mlx_destroy_window(win1.mlx_ptr, win1.win_ptr);
	mlx_destroy_display(win1.mlx_ptr);
	return (0);
}
