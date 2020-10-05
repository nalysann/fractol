/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_utils.c                                     :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 17:40:15 by nalysann          #+#    #+#             */
/*   Updated: 2020/09/14 17:40:17 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cl_funs.h"
#include "fractol.h"
#include "keyboard.h"
#include "palette.h"

#include "mlx.h"

#include <stdlib.h>

void	change_max_iter(int keycode, t_fractol *fractol)
{
	if (keycode == KEY_PLUS)
	{
		if (fractol->int_params[3] < MAX_ITER_DEF)
		{
			++fractol->int_params[3];
		}
		else if (fractol->int_params[3] < MAX_ITER_CAP)
		{
			fractol->int_params[3] += (fractol->int_params[3] / 50);
		}
	}
	else
	{
		if (fractol->int_params[3] > MAX_ITER_DEF)
		{
			fractol->int_params[3] -= (fractol->int_params[3] / 50);

		}
		else if (fractol->int_params[3] > 1)
		{
			--fractol->int_params[3];
		}
	}
	run_cl(fractol);
}

void	move(int keycode, t_fractol *fractol)
{
	double	re;
	double	im;

	re = fractol->double_params[1] - fractol->double_params[0];
	im = fractol->double_params[3] - fractol->double_params[2];
	if (keycode == KEY_LEFT)
	{
		re = -re;
	}
	if (keycode == KEY_DOWN)
	{
		im = -im;
	}
	if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
	{
		fractol->double_params[0] += re * MOVE_DELTA;
		fractol->double_params[1] += re * MOVE_DELTA;
	}
	else
	{
		fractol->double_params[2] += im * MOVE_DELTA;
		fractol->double_params[3] += im * MOVE_DELTA;
	}
	run_cl(fractol);
}

void	change_palette(int keycode, t_fractol *fractol)
{
	free(fractol->palette);
	if (keycode == KEY_F1)
	{
		generate_palette(&fractol->palette, 0xde0000, 0xde6161, fractol->int_params[3]);
	}
	else if (keycode == KEY_F2)
	{
		generate_palette(&fractol->palette, 0x00e900, 0xE7E9BB, fractol->int_params[3]);
	}
	else if (keycode == KEY_F3)
	{
		generate_palette(&fractol->palette, 0x000000, 0xFFFFFF, fractol->int_params[3]);
	}
	else
	{
		generate_palette(&fractol->palette, 0x000000, 0xFF33FF, fractol->int_params[3]);
	}
	run_cl(fractol);
}

int		destroy_notify(void *param)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)param;
	mlx_destroy_image(fractol->mlx_ptr, fractol->img.ptr);
	mlx_destroy_window(fractol->mlx_ptr, fractol->win_ptr);
	exit(EXIT_SUCCESS);
}
