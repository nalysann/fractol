/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 11:35:10 by nalysann          #+#    #+#             */
/*   Updated: 2020/09/13 16:45:55 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cl_funs.h"
#include "error.h"
#include "fractol.h"
#include "hook.h"
#include "utils.h"

#include "ft_error.h"
#include "ft_stdlib.h"
#include "ft_string.h"

#include "mlx.h"

#include <stddef.h>
#include <stdlib.h>

static void		get_type(char *str, t_fractol *fractol)
{
	int		i;
	char	*repr;

	i = 1;
	while (i <= FRACTAL_TYPES)
	{
		repr = ft_itoa(i);
		if (ft_strequ(str, repr))
		{
			fractol->data.type = i;
			free(repr);
			return ;
		}
		free(repr);
		++i;
	}
	print_usage();
}

static void		init_draw(t_fractol *fractol)
{
	t_draw	*data;
	double	real_resized;

	data = &fractol->data;
	fractol->data.size_x = fractol->size_x;
	data->min_re = MIN_RE_DEF;
	data->max_re = MAX_RE_DEF;
	real_resized = (data->max_re - data->min_re) / fractol->size_x *
												fractol->size_y / 2.0;
	data->min_im = -real_resized;
	data->max_im = real_resized;
	data->delta_re = (data->max_re - data->min_re) / (fractol->size_x - 1);
	data->delta_im = (data->max_im - data->min_im) / (fractol->size_y - 1);
	data->p_re = P_RE_DEF;
	data->p_im = P_IM_DEF;
	data->max_iter = MAX_ITER_DEF;
}

static void		init_fractol(t_fractol *fractol)
{
	fractol->mlx_ptr = mlx_init();
	if (fractol->mlx_ptr == NULL)
		ft_throw(MLX_MSG, E_MLX);
	mlx_get_screen_size(fractol->mlx_ptr, &fractol->size_x, &fractol->size_y);
	fractol->win_ptr = mlx_new_window(fractol->mlx_ptr,
						fractol->size_x, fractol->size_y, "widePeepoFractol");
	if (fractol->win_ptr == NULL)
		ft_throw(WIN_MSG, E_MLX);
	fractol->img.ptr = mlx_new_image(fractol->mlx_ptr,
						fractol->size_x, fractol->size_y);
	if (fractol->img.ptr == NULL)
		ft_throw(IMG_MSG, E_MLX);
	fractol->img.data_addr = (int *)mlx_get_data_addr(
			fractol->img.ptr,
			&fractol->img.bits_per_pixel,
			&fractol->img.size_line,
			&fractol->img.endian);
	if (fractol->img.data_addr == NULL)
		ft_throw(ADDR_MSG, E_MLX);
	init_draw(fractol);
}

int				main(int argc, char *argv[])
{
	t_fractol	fractol;

	if (argc != 2)
	{
		print_usage();
	}
	get_type(argv[1], &fractol);
	init_fractol(&fractol);
	init_cl(&fractol);
	run_cl(&fractol);
	hook_all(&fractol);
	mlx_loop(fractol.mlx_ptr);
}
