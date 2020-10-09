/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 14:35:54 by nalysann          #+#    #+#             */
/*   Updated: 2020/09/14 14:35:55 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "keyboard.h"
#include "utils.h"

int		key_press(int keycode, void *param)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)param;
	if (keycode == KEY_PLUS || keycode == KEY_MINUS)
		change_max_iter(keycode, fractol);
	else if (keycode == KEY_UP || keycode == KEY_DOWN ||
			keycode == KEY_LEFT || keycode == KEY_RIGHT)
		move(keycode, fractol);
	else if (keycode == KEY_R)
		reset(fractol);

	else if (keycode == KEY_F1 || keycode == KEY_F2 ||
			keycode == KEY_F3 || keycode == KEY_F4)
		change_palette(keycode, fractol);
	else if (keycode == KEY_1 || keycode == KEY_2 || keycode == KEY_3 ||
			keycode == KEY_4 || keycode == KEY_5 || keycode == KEY_6 ||
			keycode == KEY_7 || keycode == KEY_8)
		change_type(keycode, fractol);
	else if (keycode == KEY_SPACE &&
		(fractol->data.type == T_JULIA || fractol->data.type == T_MULTIJULIA3 ||
		fractol->data.type == T_JULIACORN))
		fractol->is_fixed = (fractol->is_fixed + 1) % 2;
	else if (keycode == KEY_ESC)
		destroy_notify(param);
	return (0);
}
