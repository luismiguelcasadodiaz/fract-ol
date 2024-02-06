/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_h_mouse_up.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:39:38 by luicasad          #+#    #+#             */
/*   Updated: 2024/02/06 12:45:07 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"
#include <stdio.h>

int	win_h_mouse_up(int button, int x, int y, t_win *w)
{
	printf("in window %s, mouse_up (%d, %d) button %d\n", w->title, x ,y , button);
	return (0);
}

