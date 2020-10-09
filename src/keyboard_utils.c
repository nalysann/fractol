/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 14:07:04 by nalysann          #+#    #+#             */
/*   Updated: 2020/10/09 14:07:14 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cl_funs.h"
#include "fractol.h"
#include "keyboard.h"
#include "utils.h"

#include "mlx.h"

#include <stdlib.h>

void	change_max_iter(int keycode, t_fractol *fractol)
{
	if (keycode == KEY_PLUS)
	{
		if (fractol->data.max_iter < MAX_ITER_DEF)
			++fractol->data.max_iter;
		else if (fractol->data.max_iter < MAX_ITER_CAP)
			fractol->data.max_iter += (fractol->data.max_iter / 100);
	}
	else
	{
		if (fractol->data.max_iter > MAX_ITER_DEF)
			fractol->data.max_iter -= (fractol->data.max_iter / 100);
		else if (fractol->data.max_iter > 1)
			--fractol->data.max_iter;
	}
	run_cl(fractol);
}

void	move(int keycode, t_fractol *fractol)
{
	if (keycode == KEY_LEFT)
		fractol->data.shift_re -= MOVE_DELTA * fractol->data.scale;
	else if (keycode == KEY_RIGHT)
		fractol->data.shift_re += MOVE_DELTA * fractol->data.scale;
	else if (keycode == KEY_UP)
		fractol->data.shift_im -= MOVE_DELTA * fractol->data.scale;
	else if (keycode == KEY_DOWN)
		fractol->data.shift_im += MOVE_DELTA * fractol->data.scale;
	run_cl(fractol);
}

void	change_palette(int keycode, t_fractol *fractol)
{
	if (keycode == KEY_F1)
		fractol->data.palette = P_RAINBOW;
	else if (keycode == KEY_F2)
		fractol->data.palette = P_MONOCHROME;
	else if (keycode == KEY_F3)
		fractol->data.palette = P_PASTEL;
	else if (keycode == KEY_F4)
		fractol->data.palette = P_COLD;
	run_cl(fractol);
}

void	change_type(int keycode, t_fractol *fractol)
{
	if (keycode == KEY_1)
		fractol->data.type = 1;
	else if (keycode == KEY_2)
		fractol->data.type = 2;
	else if (keycode == KEY_3)
		fractol->data.type = 3;
	else if (keycode == KEY_4)
		fractol->data.type = 4;
	else if (keycode == KEY_5)
		fractol->data.type = 5;
	else if (keycode == KEY_6)
		fractol->data.type = 6;
	else if (keycode == KEY_7)
		fractol->data.type = 7;
	else if (keycode == KEY_8)
		fractol->data.type = 8;
	reset(fractol);
	run_cl(fractol);
}

int		destroy_notify(void *param)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)param;
	release_cl(fractol);
	mlx_destroy_image(fractol->mlx_ptr, fractol->img.ptr);
	mlx_destroy_window(fractol->mlx_ptr, fractol->win_ptr);
	exit(EXIT_SUCCESS);
}
