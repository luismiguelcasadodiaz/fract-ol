/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_h_mouse_down.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:32:45 by luicasad          #+#    #+#             */
/*   Updated: 2024/02/25 18:59:28 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>
#include "keys_ubuntu.h"


int	win_h_mouse_down(int button, int x, int y, t_win *w)
{
	printf("dowm (%d, %d) button %d zoom %d \n", x, y, button, w->zoom);
	return (0);
}
