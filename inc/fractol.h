/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 19:47:24 by luicasad          #+#    #+#             */
/*   Updated: 2024/01/17 17:07:00 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define MLX_ERROR 1
# define XK_Escape 65
typedef struct	s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}				t_data;

int win_h_key_press(int keysym, t_data *data);
int win_h_key_relea(int keysym, t_data *data);
int win_h_not_event(void *data);

#endif
