/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_h_key_up.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 21:19:34 by luicasad          #+#    #+#             */
/*   Updated: 2024/02/25 18:56:21 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int	win_h_key_up(int keysym, t_win *data)
{
	if (data->win_ptr == NULL)
		printf("NULL POINTER");
	printf("Key_up: %d\n", keysym);
	return (0);
}
