/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kernel.cl                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 18:34:30 by nalysann          #+#    #+#             */
/*   Updated: 2020/09/18 18:34:32 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma OPENCL EXTENSION cl_khr_fp64 : enable

typedef struct	s_draw
{
	int		type;
	int		sizex;
	int		size_line_int;
	int		max_iter;
	int		palette;
	double	scale;
	double	shift_re;
	double	shift_im;
	double	param_re;
	double	param_im;
}				t_draw;

static int		get_color(double z_re, double z_im, int iter, int palette)
{
	union	u_color
	{
		int				value;
		unsigned char	channels[4];
	}		color;

	double continuous_index = iter + 1 - log2(log2(z_re * z_re + z_im * z_im));

	if (palette == 1)
	{
		color.channels[0] = (unsigned char)(sin(0.05 * continuous_index + 0) * 127 + 128);
		color.channels[1] = (unsigned char)(sin(0.05 * continuous_index + 2) * 127 + 128);
		color.channels[2] = (unsigned char)(sin(0.05 * continuous_index + 4) * 127 + 128);
	}
	else if (palette == 2)
	{
		color.channels[0] = (unsigned char)(sin(0.05 * continuous_index + 0) * 127 + 128);
		color.channels[1] = (unsigned char)(sin(0.05 * continuous_index + 0) * 127 + 128);
		color.channels[2] = (unsigned char)(sin(0.05 * continuous_index + 0) * 127 + 128);
	}
	else if (palette == 3)
	{
		color.channels[0] = (unsigned char)(sin(0.05 * continuous_index + 0) * 25 + 230);
		color.channels[1] = (unsigned char)(sin(0.05 * continuous_index + 2) * 25 + 230);
		color.channels[2] = (unsigned char)(sin(0.05 * continuous_index + 4) * 25 + 230);
	}
	else
	{
		color.channels[0] = (unsigned char)(cos(0.05 * continuous_index + 4) * 127 + 128);
		color.channels[1] = (unsigned char)(sin(0.04 * continuous_index + 2) * 127 + 128);
		color.channels[2] = (unsigned char)(cos(0.03 * continuous_index + 0) * 127 + 128);
	}

	color.channels[3] = 0;

	return color.value;
}

static int		iterate(__global t_draw *data, int x, int y)
{
	double	c_re;
	double	c_im;
	double	z_re;
	double	z_im;
	double	tmp;
	int		iter;

	c_re = x * data->scale + data->shift_re;
	c_im = y * data->scale + data->shift_im;
	z_re = c_re;
	z_im = c_im;
	iter = 0;
	while (z_re * z_re + z_im * z_im <= 4 && iter < data->max_iter)
	{
		tmp = z_re;
		if (data->type == 1)
		{
			z_re = z_re * z_re - z_im * z_im + c_re;
			z_im = 2 * tmp * z_im + c_im;
		}
		else if (data->type == 2)
		{
			z_re = z_re * z_re - z_im * z_im + data->param_re;
			z_im = 2 * tmp * z_im + data->param_im;
		}
		else if (data->type == 3)
		{
			z_re = z_re * z_re - z_im * z_im + c_re;
			z_im = fabs(2 * tmp * z_im) + c_im;
		}
		else if (data->type == 4)
		{
			z_re = z_re * z_re - z_im * z_im + c_re;
			z_im = -2 * tmp * z_im + c_im;
		}
		else if (data->type == 5)
		{
			z_re = z_re * z_re * z_re - 3 * z_re * z_im * z_im + c_re;
			z_im = 3 * tmp * tmp * z_im - z_im * z_im * z_im + c_im;
		}
		else if (data->type == 6)
		{
			z_re = z_re * z_re * z_re - 3 * z_re * z_im * z_im + data->param_re;
			z_im = 3 * tmp * tmp * z_im - z_im * z_im * z_im + data->param_im;
		}
		else if (data->type == 7)
		{
			z_re = z_re * z_re - z_im * z_im + data->param_re;
			z_im = -2 * tmp * z_im + data->param_im;
		}
		else if (data->type == 8)
		{
			z_re = fabs(z_re * z_re - z_im * z_im) + c_re;
			z_im = 2 * fabs(tmp * z_im) + c_im;
		}
		++iter;
	}
	return (iter == data->max_iter ? 0x000000 : get_color(z_re, z_im, iter, data->palette));
}

__kernel void	fractol(__global t_draw *data, __global int *img)
{
	int		id;
	int		x;
	int		y;

	id = get_global_id(0);
	x = id % data->sizex;
	y = id / data->sizex;
	img[y * data->size_line_int + x] = iterate(data, x, y);
}
