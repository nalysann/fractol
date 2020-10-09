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

#include "ft_stdio.h"
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

static void		init_fractol(t_fractol *fractol)
{
	fractol->mlx_ptr = mlx_init();
	if (fractol->mlx_ptr == NULL)
		exit_with_error(MLX_MSG, E_MLX);
	fractol->sizex = WIDTH;
	fractol->sizey = HEIGHT;
	fractol->win_ptr = mlx_new_window(fractol->mlx_ptr, fractol->sizex,
								fractol->sizey, "widePeepoFractol");
	if (fractol->win_ptr == NULL)
		exit_with_error(WIN_MSG, E_MLX);
	fractol->img.ptr = mlx_new_image(fractol->mlx_ptr,
								fractol->sizex, fractol->sizey);
	if (fractol->img.ptr == NULL)
		exit_with_error(IMG_MSG, E_MLX);
	fractol->img.data_addr = (int *)mlx_get_data_addr(
			fractol->img.ptr,
			&fractol->img.bits_per_pixel,
			&fractol->img.size_line,
			&fractol->img.endian);
	if (fractol->img.data_addr == NULL)
		exit_with_error(ADDR_MSG, E_MLX);
	fractol->data.sizex = fractol->sizex;
	fractol->data.size_line_int = fractol->img.size_line / 4;
	fractol->data.palette = P_RAINBOW;
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
	reset(&fractol);
	hook_all(&fractol);
	mlx_loop(fractol.mlx_ptr);
}
