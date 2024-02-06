/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_h_key_press.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 21:19:34 by luicasad          #+#    #+#             */
/*   Updated: 2024/02/06 12:57:05 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>
#include "mlx.h"
#if defined(__APPLE__) && defined(__MACH__)
#include "keys_mac.h"
#else
#include "keys_ubuntu.h"
#endif

int	win_h_key_down(int	keysym, t_win *data)
{
	if (keysym == KEY_ESC)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	printf("Key_down: %d\n", keysym);
	return (0);
}
