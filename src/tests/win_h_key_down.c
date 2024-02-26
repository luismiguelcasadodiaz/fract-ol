/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_h_key_down.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 21:19:34 by luicasad          #+#    #+#             */
/*   Updated: 2024/02/26 12:28:13 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keys_ubuntu.h"
#include "fractol.h"
#include <stdio.h>
#include "mlx.h"

int	win_h_key_down(int keysym, t_win *w)
{
	if (keysym == KEY_ESC)
	{
		mlx_destroy_window(w->mlx_ptr, w->win_ptr);
		free(w->mlx_ptr);
		exit (0);
	}
	printf("Key_down: %d\n", keysym);
	return (0);
}
