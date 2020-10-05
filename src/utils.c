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
#include "error.h"
#include "fractol.h"

#include "ft_error.h"
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
	ft_printf("    [4] Bonus 1\n");
	ft_printf("    [5] Bonus 2\n");
	ft_printf("    [6] Bonus 3\n");
	ft_printf("    [7] Bonus 4\n");
	ft_printf("    [8] Bonus 5\n");
	ft_throw(USAGE_MSG, E_USAGE);
}

char	*read_kernel_file(char *filename)
{
	int			fd;
	char		*buf;
	ssize_t		ret;
	int			status;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_throw(OPEN_MSG, E_FILE);
	buf = (char *)malloc(KERNEL_FILE_MAX_SIZE);
	if (buf == NULL)
		ft_throw(ALLOC_MSG, E_ALLOC);
	ret = read(fd, buf, KERNEL_FILE_MAX_SIZE);
	buf[ret] = '\0';
	status = close(fd);
	if (status < 0)
		ft_throw(CLOSE_MSG, E_FILE);
	return (buf);
}

void	reset(int *int_params, double *double_params)
{
	double	real_resized;

	int_params[3] = MAX_ITER_DEF;
	double_params[0] = MIN_RE_DEF;
	double_params[1] = MAX_RE_DEF;
	real_resized = (double_params[1] - double_params[0]) / int_params[1] *
															int_params[2] / 2.0;
	double_params[2] = -real_resized;
	double_params[3] = real_resized;
	double_params[4] = (double_params[1] - double_params[0]) /
															(int_params[1] - 1);
	double_params[5] = (double_params[3] - double_params[2]) /
															(int_params[2] - 1);
	double_params[6] = P_RE_DEF;
	double_params[7] = P_IM_DEF;

}
