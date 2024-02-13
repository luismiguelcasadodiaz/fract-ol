/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:49:57 by luicasad          #+#    #+#             */
/*   Updated: 2024/02/13 15:52:29 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"
#include <stdlib.h>
#include "ft_printf.h"

static void	set_init_values(t_win *w, char *title, int wide, int height)
{
	w->title = title;
	w->w = wide;
	w->h = height;
	w->md_x = 0;
	w->md_y = 0;
	w->mu_x = 0;
	w->mu_y = 0;
	w->mm_x = 0;
	w->mm_y = 0;
	w->img.w = w->w;
	w->img.h = w->h;
	w->zoom = 0;
}
/*
static void	set_init_values_2(t_win w, char *title, int wide, int height)
{
	w.title = title;
	w.w = wide;
	w.h = height;
	w.md_x = 0;
	w.md_y = 0;
	w.mu_x = 0;
	w.mu_y = 0;
	w.mm_x = 0;
	w.mm_y = 0;
	w.img.w = w.w;
	w.img.h = w.h;
}
*/
t_win	*win_init(char *title, int wide, int height)
{
	t_win	*w;

	w = (t_win *) malloc(sizeof(t_win));
	if (!w)
		return ((t_win *) NULL);
	set_init_values(w, title, wide, height);
	w->mlx_ptr = mlx_init();
	if (w->mlx_ptr == NULL)
	{
		free(w);
		return ((t_win *) NULL);
	}
	w->win_ptr = mlx_new_window(w->mlx_ptr, w->w, w->h, w->title);
	if (w->win_ptr == NULL)
	{
		free(w->mlx_ptr);
		free(w);
		return ((t_win *) NULL);
	}
	w->img.img_ptr = mlx_new_image(w->mlx_ptr, w->img.w, w->img.h);
	if (w->img.img_ptr == NULL)
	{
		free(w->win_ptr);
		free(w->mlx_ptr);
		free(w);
		return ((t_win *) NULL);
	}
	w->img.addr = mlx_get_data_addr(w->img.img_ptr,
			&w->img.bits_per_pixel,
			&w->img.line_length,
			&w->img.endian);
	ft_printf("win %s bit per pixel %d, line_length %d endian %d\n",
		w->title,
		w->img.bits_per_pixel,
		w->img.line_length,
		w->img.endian,
		w->img.addr);
	return (w);
}

t_win	win_init_2(char *title, int wide, int height)
{
	t_win	w;

	w.title = title;
	set_init_values(&w, title, wide, height);
	w.mlx_ptr = mlx_init();
	if (w.mlx_ptr == NULL)
		exit (-1);
	w.win_ptr = mlx_new_window(w.mlx_ptr, w.w, w.h, w.title);
	if (w.win_ptr == NULL)
	{
		free(w.mlx_ptr);
		exit (-1);
		//return ((t_win *) NULL);
	}
	w.img.img_ptr = mlx_new_image(w.mlx_ptr, w.img.w, w.img.h);
	if (w.img.img_ptr == NULL)
	{
		free(w.win_ptr);
		free(w.mlx_ptr);
		exit (-1);
		//return ((t_win *) NULL);
	}
	w.img.addr = mlx_get_data_addr(w.img.img_ptr,
			&w.img.bits_per_pixel,
			&w.img.line_length,
			&w.img.endian);
	ft_printf("win %s bit per pixel %d, line_length %d endian %d\n",
		w.title,
		w.img.bits_per_pixel,
		w.img.line_length,
		w.img.endian,
		w.img.addr);
	return (w);
}
