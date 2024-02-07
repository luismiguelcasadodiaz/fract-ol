/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_h_key_press.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 21:19:34 by luicasad          #+#    #+#             */
/*   Updated: 2024/02/07 13:32:36 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "ft_printf.h"
#include "mlx.h"
#if defined(__APPLE__) && defined(__MACH__)
#include "keys_mac.h"
#else
#include "keys_ubuntu.h"
#endif

int	win_h_key_down(int	keysym, t_win *w)
{
	if (keysym == KEY_ESC)
		mlx_destroy_window(w->mlx_ptr, w->win_ptr);
	if (keysym == KEY_C)
	{
		//mlx_destroy_image(w->mlx_ptr, w->img.img_ptr);
		w->img.img_ptr = mlx_new_image(w->mlx_ptr, w->img.w, w->img.h);
	}
	ft_printf("Key_down: %d\n", keysym);
	return (0);
}
