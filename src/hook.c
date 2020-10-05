/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 14:27:11 by nalysann          #+#    #+#             */
/*   Updated: 2020/09/14 14:27:12 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "hook.h"
#include "keyboard.h"
#include "mouse.h"

#include "mlx.h"

void	hook_all(void *param)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)param;
	mlx_hook(fractol->win_ptr, KEY_PRESS, KEY_PRESS_MASK,
				key_press, param);
	mlx_hook(fractol->win_ptr, KEY_RELEASE, KEY_RELEASE_MASK,
				key_release, param);
	mlx_hook(fractol->win_ptr, BUTTON_PRESS, BUTTON_PRESS_MASK,
				button_press, param);
	mlx_hook(fractol->win_ptr, BUTTON_RELEASE, BUTTON_RELEASE_MASK,
				button_release, param);
	if (fractol->int_params[0] == T_JULIA)
	{
		mlx_hook(fractol->win_ptr, MOTION_NOTIFY, MOTION_NOTIFY_MASK,
				motion_notify, param);
	}
	mlx_hook(fractol->win_ptr, DESTROY_NOTIFY, STRUCTURE_NOTIFY_MASK,
				destroy_notify, param);
}
