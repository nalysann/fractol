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

static int		get_color(double cx, double cy, int iter)
{
	union	colour_u
	{
		int  number;
		unsigned char channels[4];
	};

	union colour_u	c;

	double continuous_index = iter + 1 - log(pow(cx * cx + cy * cy, 0.5)) / log(2.0);
//	c.channels[0] = (unsigned char)(sin(0.016 * continuous_index + 4) * 230 + 25);
//	c.channels[1] = (unsigned char)(sin(0.013 * continuous_index + 2) * 230 + 25);
//	c.channels[2] = (unsigned char)(sin(0.01 * continuous_index + 1) * 230 + 25);
	c.channels[0] = (unsigned char)(continuous_index);
	c.channels[1] = (unsigned char)(2 * continuous_index);
	c.channels[2] = (unsigned char)(4 * continuous_index);
	c.channels[3] = 0;

	return c.number;
}

static void		img_pixel_put(__global int *int_params,
								__global int *img,
								int x,
								int y,
								int color)
{
	size_t	offset;

	offset = y * int_params[1] + x;
	img[offset] = color;
}

static int		iterate_mandelbrot(__global int *int_params,
									__global double *double_params,
									int x,
									int y)
{
	double	cx;
	double	cy;
	double	zx;
	double	zy;
	double	tmp;
	int		iter;

	cx = double_params[0] + x * double_params[4];
	cy = double_params[3] - y * double_params[5];
	zx = cx;
	zy = cy;
	iter = 0;
	while (zx * zx + zy * zy <= 4 && iter < int_params[3])
	{
		tmp = zx * zx - zy * zy + cx;
		zy = 2.0 * zx * zy + cy;
		zx = tmp;
		++iter;
	}
	return (get_color(zx, zy, iter));
}

static int		iterate_julia(__global int *int_params,
							__global double *double_params,
							int x,
							int y)
{
	double	cx;
	double	cy;
	double	zx;
	double	zy;
	double	tmp;
	int		iter;

	cx = double_params[0] + x * double_params[4];
	cy = double_params[3] - y * double_params[5];
	zx = cx;
	zy = cy;
	iter = 0;
	while (zx * zx + zy * zy <= 4 && iter < int_params[3])
	{
		tmp = zx;
		zx = zx * zx - zy * zy + double_params[6];
		zy = 2.0 * tmp * zy + double_params[7];
		++iter;
	}
	return (get_color(zx, zy, iter));
}

static int		iterate_burning_ship(__global int *int_params,
									__global double *double_params,
									int x,
									int y)
{
	double	cx;
	double	cy;
	double	zx;
	double	zy;
	double	tmp;
	int		iter;

	cx = double_params[0] + x * double_params[4];
	cy = double_params[3] - y * double_params[5];
	zx = cx;
	zy = cy;
	iter = 0;
	while (zx * zx + zy * zy <= 4 && iter < int_params[3])
	{
		tmp = zx * zx - zy * zy + cx;
		zy = -fabs(2.0 * zx * zy) + cy;
		zx = tmp;
		++iter;
	}
	return (get_color(zx, zy, iter));
}

static int		iterate(__global int *int_params,
						__global double *double_params,
						int x,
						int y)
{
	if (int_params[0] == 1)
		return (iterate_mandelbrot(int_params, double_params, x, y));
	else if (int_params[0] == 2)
		return (iterate_julia(int_params, double_params, x, y));
	else if (int_params[0] == 3)
		return (iterate_burning_ship(int_params, double_params, x, y));
	return (0);
}

__kernel void	fractol(__global int *int_params,
						__global double *double_params,
						__global int *img,
						__global int *palette)
{
	int		id;
	int		x;
	int		y;

	id = get_global_id(0);
	x = id % int_params[1];
	y = id / int_params[1];
	img_pixel_put(int_params, img, x, y, iterate(int_params, double_params, x, y));
}
