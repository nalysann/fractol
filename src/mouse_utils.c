/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 18:19:24 by nalysann          #+#    #+#             */
/*   Updated: 2020/09/14 18:19:26 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cl_funs.h"
#include "fractol.h"
#include "mouse.h"

void	zoom(int button, int x, int y, t_fractol *fractol)
{
	y = fractol->sizey - y;
	if (button == BUT_DOWN)
	{
		fractol->data.shift_re -=
				x * (fractol->data.scale * ZOOM_DELTA) -
				x * fractol->data.scale;
		fractol->data.shift_im -=
				y * (fractol->data.scale * ZOOM_DELTA) -
				y * fractol->data.scale;
		fractol->data.scale *= ZOOM_DELTA;
		fractol->data.max_iter -= MAX_ITER_DELTA;
	}
	else
	{
		fractol->data.shift_re -=
				x * (fractol->data.scale / ZOOM_DELTA) -
				x * fractol->data.scale;
		fractol->data.shift_im -=
				y * (fractol->data.scale / ZOOM_DELTA) -
				y * fractol->data.scale;
		fractol->data.scale /= ZOOM_DELTA;
		fractol->data.max_iter += MAX_ITER_DELTA;
	}
	run_cl(fractol);
}
