/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fenetre_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 10:28:52 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/14 10:37:51 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

int	main(void)
{
	void	*mlx_ptr;
	void	*win1_ptr;
	void	*win2_ptr;

	mlx_ptr = mlx_init();
	win1_ptr = mlx_new_window(mlx_ptr, 500, 500, "LUIS");
	win2_ptr = mlx_new_window(mlx_ptr, 500, 500, "SANDRA");
	mlx_loop(mlx_ptr);
	return (0);
}
