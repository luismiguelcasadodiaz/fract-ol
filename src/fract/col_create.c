/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   col_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:49:06 by luicasad          #+#    #+#             */
/*   Updated: 2024/02/10 11:26:00 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	col_create(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	col_get_t(int color)
{
	return ((color >> 24) & 0xFF);
}

int	col_get_r(int color)
{
	return ((color >> 16) & 0xFF);
}

int	col_get_g(int color)
{
	return ((color >> 8) & 0xFF);
}

int	col_get_b(int color)
{
	return (color & 0xFF);
}
