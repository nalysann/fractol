/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 14:44:26 by nalysann          #+#    #+#             */
/*   Updated: 2020/09/22 14:44:26 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

/*
** Error messages
*/

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
# define CONTEXT_MSG	"Error: failed to create cl context"
# define QUEUE_MSG		"Error: failed to create cl command queue"
# define PROGRAM_MSG	"Error: failed to create cl program"
# define BUILD_MSG		"Error: failed to build cl program"
# define KERNEL_MSG		"Error: failed to create cl kernel"
# define BUFFER_MSG		"Error: failed to create cl buffer"
# define ARG_MSG		"Error: failed to set cl kernel argument"
# define BUFFER_W_MSG	"Error: failed to write to cl buffer"
# define BUFFER_R_MSG	"Error: failed to read from cl buffer"
# define EXECUTE_MSG	"Error: failed to execute cl kernel"

/*
** Error codes
*/

# define E_ALLOC	1
# define E_USAGE	2
# define E_MLX		3
# define E_OPENCL	4
# define E_FILE		5

#endif
