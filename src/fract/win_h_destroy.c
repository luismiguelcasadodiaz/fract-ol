/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_h_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:14:23 by luicasad          #+#    #+#             */
/*   Updated: 2024/02/10 16:38:20 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"
#include <stdlib.h>

int	win_h_destroy(t_win *w)
{
	mlx_destroy_window(w->mlx_ptr, w->win_ptr);
	free(w->mlx_ptr);
	return (0);
}
