/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 19:47:24 by luicasad          #+#    #+#             */
/*   Updated: 2024/02/05 19:52:19 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define MLX_ERROR 1
# define XK_ESCAPE 65
# define ASPECT_RATIO_1_H 4
# define ASPECT_RATIO_1_V 3

# define ASPECT_RATIO_2_H 16
# define ASPECT_RATIO_2_V 9


# define ASPECT_RATIO_3_H 21
# define ASPECT_RATIO_3_V 9
typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		w;
	int		h;
}	t_img;
typedef struct s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	char	*title;
	int		w;
	int		h;

}				t_win;

int		win_h_key_press(int keysym, t_win *data);
int		win_h_key_relea(int keysym, t_win *data);
int		win_h_not_event(void *data);
void	win_pixel_put(t_win w, int x, int y, int color);
#endif
