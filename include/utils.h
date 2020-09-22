/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 11:58:07 by nalysann          #+#    #+#             */
/*   Updated: 2020/09/14 11:58:08 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "fractol.h"

# define ALLOC_MSG		"Error: memory allocation failed"
# define USAGE_MSG		NULL
# define MLX_MSG		"Error: mlx initialization failed"
# define WIN_MSG		"Error: window creation failed"
# define IMG_MSG		"Error: image creation failed"
# define ADDR_MSG		"Error: image address retrieval failed"
# define PLAT_MSG		"Error: couldn't identify any cl platforms"
# define N_PLAT_MSG		"Error: current version supports only one cl platform"
# define G_PLAT_MSG		"Error: couldn't get cl platform"
# define DEV_MSG		"Error: couldn't identify any cl devices"
# define N_DEV_MSG		"Error: current version supports only one cl device"
# define G_DEV_MSG		"Error: couldn't get cl device"
# define OPEN_MSG		"Error: couldn't open file"
# define CLOSE_MSG		"Error: couldn't close file descriptor"

# define E_ALLOC	1
# define E_USAGE	2
# define E_MLX		3
# define E_OPENCL	4
# define E_FILE		5

void	print_usage(void);
char	*read_kernel_file(char *filename);
void	reset(t_fractol *fractol);

#endif
