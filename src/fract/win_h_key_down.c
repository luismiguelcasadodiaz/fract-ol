/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_h_key_down.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 21:19:34 by luicasad          #+#    #+#             */
/*   Updated: 2024/02/16 11:30:07 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#if defined(__APPLE__) && defined(__MACH__)
# include "keys_mac.h"
#else
# include "keys_ubuntu.h"
#endif
*/

#include "keys_mac.h"
#include "fractol.h"
#include "ft_printf.h"
#include "mlx.h"

int	win_h_key_down(int	keysym, t_win *w)
{
	if (keysym == KEY_ESC)
	{
		mlx_destroy_window(w->mlx_ptr, w->win_ptr);
		free(w->mlx_ptr);
		exit (0);
	}
	if (keysym == KEY_R)
		w->palette = 0x00FF0000;
	if (keysym == KEY_G)
		w->palette = 0x0000FF00;
	if (keysym == KEY_B)
		w->palette = 0x000000FF;
	if (keysym == KEY_S)
		w->palette = 0x0003F40B;
	if (keysym == ARROW_UP)
		w->h_0 += 10;
	if (keysym == ARROW_DOWN)
		w->h_0 -= 10;
	if (keysym == ARROW_RIGHT)
		w->w_0 += 10;
	if (keysym == ARROW_LEFT)
		w->w_0 -= 10;
	draw_fractal(*w);

	ft_printf("Key_down: %d\n", keysym);
	return (0);
}
