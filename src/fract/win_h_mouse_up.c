/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_h_mouse_up.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:39:38 by luicasad          #+#    #+#             */
/*   Updated: 2024/02/26 00:21:04 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "ft_printf.h"

int	win_h_mouse_up(int button, int x, int y, t_win *w)
{
	ft_printf("w=%s, mouse_up (%d, %d) button %d\n", w->title, x, y, button);
	w->mu = point_set(x, y);
	return (0);
}
