/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:49:57 by luicasad          #+#    #+#             */
/*   Updated: 2024/02/21 12:57:03 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "ft_complex.h"
#include "mlx.h"
#include <stdlib.h>
#include "ft_printf.h"
#include "libft.h"

static void	set_init_values_img(t_win *w, int real, int imag)
{
	int	m_x;
	int	m_y;

	w->img.w = w->w;
	w->img.h = w->h;
	m_x = w->img.w / 2;
	m_y = w->img.h / 2;
	w->img.lu_x = -m_x;
	w->img.lu_y = m_y;
	w->img.rd_x = m_x;
	w->img.rd_y = -m_y;
	w->img.x_0 = 0;
	w->img.y_0 = 0;
	w->img.real = 2 * COMPLEX_REAL_MAX;
	w->img.imag = 2 * COMPLEX_IMAG_MAX;
	w->img.r_x = w->img.real / w->img.w;
	w->img.r_y = w->img.imag / w->img.h;
	w->img.z = create(1.0 * real / WINDOW_W, 1.0 * imag / WINDOW_H);
}

static void	set_init_values_win(t_win *w, char *title, int real, int imag)
{
	ft_bzero(w, sizeof(t_win));
	w->title = title;
	w->w = WINDOW_W;
	w->h = WINDOW_H;
	w->lu_x = 0;
	w->lu_y = 0;
	w->rd_x = w->w;
	w->rd_y = w->h;
	w->md_x = 0;
	w->md_y = 0;
	w->mu_x = 0;
	w->mu_y = 0;
	w->mm_x = 0;
	w->mm_y = 0;
	w->zoom = INITIAL_ZOOM;
	w->shift_x = 0;
	w->shift_y = 0;
	w->palette = 0x0003F40B;
	w->iteractions = MAX_ITERATIONS;
	set_init_values_img(w, real, imag);
}

t_win	win_init(char *title, char *real_txt, char *imag_txt)
{
	t_win	w;

	set_init_values_win(&w, title, ft_atoi(real_txt), ft_atoi(imag_txt));
	w.mlx_ptr = mlx_init();
	if (w.mlx_ptr == NULL)
		exit (-1);
	w.win_ptr = mlx_new_window(w.mlx_ptr, w.w, w.h, w.title);
	if (w.win_ptr == NULL)
	{
		free(w.mlx_ptr);
		exit (-1);
	}
	w.img.img_ptr = mlx_new_image(w.mlx_ptr, w.img.w, w.img.h);
	if (w.img.img_ptr == NULL)
	{
		free(w.win_ptr);
		free(w.mlx_ptr);
		exit (-1);
	}
	w.img.addr = mlx_get_data_addr(w.img.img_ptr,
			&w.img.bits_per_pixel,
			&w.img.line_length,
			&w.img.endian);
	return (w);
}
/*	ft_printf("win %s bit per pixel %d, line_length %d endian %d\n",
		w.title,
		w.img.bits_per_pixel,
		w.img.line_length,
		w.img.endian,
		w.img.addr);
		*/
