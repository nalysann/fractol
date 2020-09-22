/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_data.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 16:41:20 by nalysann          #+#    #+#             */
/*   Updated: 2020/09/18 16:41:22 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CL_DATA_H
# define CL_DATA_H

# ifdef __APPLE__
#  include <OpenCL/opencl.h>
# else
#  include <CL/cl.h>
# endif

# define PLATFORMS	1
# define DEVICES	1

# define KERNEL_FILE			"./src/kernel.cl"
# define KERNEL_FILE_MAX_SIZE	8192

typedef struct	s_cl
{
	cl_uint				num_platforms;
	cl_platform_id		platform;
	cl_uint				num_devices;
	cl_device_type		device_type;
	cl_device_id		device;
	cl_context			context;
	cl_command_queue	queue;
	cl_program			program;
	cl_kernel			kernel;
	cl_mem				data;
	cl_mem				img;
	cl_int				status;
}				t_cl;

#endif
