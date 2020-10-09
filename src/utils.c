/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 14:36:08 by nalysann          #+#    #+#             */
/*   Updated: 2020/09/14 14:36:09 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cl_data.h"
#include "cl_funs.h"
#include "error.h"
#include "fractol.h"

#include "ft_stdio.h"

#include <fcntl.h>
#include <stddef.h>
#include <stdlib.h>
#include <sys/uio.h>
#include <unistd.h>

void	print_usage(void)
{
	ft_printf("usage: ./fractol <number>\n");
	ft_printf("available fractals:\n");
	ft_printf("    [1] Mandelbrot\n");
	ft_printf("    [2] Julia\n");
	ft_printf("    [3] Burning Ship\n");
	ft_printf("    [4] Tricorn\n");
	ft_printf("    [5] Multibrot 3\n");
	ft_printf("    [6] Multi-Julia 3\n");
	ft_printf("    [7] Juliacorn\n");
	ft_printf("    [8] Buffalo\n");
	exit_with_error(USAGE_MSG, E_USAGE);
}

char	*read_kernel_file(char *filename)
{
	int			fd;
	char		*buf;
	ssize_t		ret;
	int			status;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		exit_with_error(OPEN_MSG, E_FILE);
	}
	buf = (char *)malloc(KERNEL_FILE_MAX_SIZE);
	if (buf == NULL)
	{
		exit_with_error(ALLOC_MSG, E_ALLOC);
	}
	ret = read(fd, buf, KERNEL_FILE_MAX_SIZE);
	buf[ret] = '\0';
	status = close(fd);
	if (status < 0)
	{
		exit_with_error(CLOSE_MSG, E_FILE);
	}
	return (buf);
}

void	reset(t_fractol *fractol)
{
	fractol->data.max_iter = MAX_ITER_DEF;
	fractol->data.scale = SCALE_DEF;
	fractol->data.shift_re = -(fractol->sizex / 2) * fractol->data.scale;
	fractol->data.shift_im = -(fractol->sizey / 2) * fractol->data.scale;
	if (fractol->data.type == T_JULIA ||
		fractol->data.type == T_MULTIJULIA3 ||
		fractol->data.type == T_JULIACORN)
	{
		fractol->is_fixed = 0;
	}
	else
	{
		fractol->is_fixed = 1;
	}
	run_cl(fractol);
}
