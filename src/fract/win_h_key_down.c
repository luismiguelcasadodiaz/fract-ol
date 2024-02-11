/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_h_key_down.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 21:19:34 by luicasad          #+#    #+#             */
/*   Updated: 2024/02/10 16:44:37 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if defined(__APPLE__) && defined(__MACH__)
# include "keys_mac.h"
#else
# include "keys_ubuntu.h"
#endif
#include "fractol.h"
#include "ft_printf.h"
#include "mlx.h"

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
