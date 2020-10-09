/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 11:35:15 by nalysann          #+#    #+#             */
/*   Updated: 2020/09/18 11:35:17 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef __APPLE__
# include <OpenCL/opencl.h>
#else
# include <CL/cl.h>
#endif

#include "cl_data.h"
#include "draw.h"
#include "error.h"
#include "fractol.h"
#include "utils.h"

#include "ft_stdio.h"

static void		get_platform(t_cl *cl)
{
	cl->status = clGetPlatformIDs(0, NULL, &cl->num_platforms);
	if (cl->status != CL_SUCCESS)
	{
		exit_with_error(PLAT_MSG, E_OPENCL);
	}
	if (cl->num_platforms != PLATFORMS)
	{
		exit_with_error(N_PLAT_MSG, E_OPENCL);
	}
	cl->status = clGetPlatformIDs(PLATFORMS, &cl->platform, NULL);
	if (cl->status != CL_SUCCESS)
	{
		exit_with_error(G_PLAT_MSG, E_OPENCL);
	}
}

static void		get_device(t_cl *cl)
{
	cl->status = clGetDeviceIDs(cl->platform, CL_DEVICE_TYPE_GPU, 0, NULL,
								&cl->num_devices);
	cl->device_type = CL_DEVICE_TYPE_GPU;
	if (cl->status == CL_DEVICE_NOT_FOUND)
	{
		cl->status = clGetDeviceIDs(cl->platform, CL_DEVICE_TYPE_CPU, 0, NULL,
									&cl->num_devices);
		cl->device_type = CL_DEVICE_TYPE_CPU;
	}
	if (cl->status != CL_SUCCESS)
	{
		exit_with_error(DEV_MSG, E_OPENCL);
	}
	if (cl->num_devices != DEVICES)
	{
		exit_with_error(N_DEV_MSG, E_OPENCL);
	}
	cl->status = clGetDeviceIDs(cl->platform, cl->device_type, DEVICES,
								&cl->device, NULL);
	if (cl->status != CL_SUCCESS)
	{
		exit_with_error(G_DEV_MSG, E_OPENCL);
	}
}

static void		init_kernel_args(t_fractol *fractol)
{
	t_cl	*cl;

	cl = &fractol->cl;
	cl->data = clCreateBuffer(cl->context, CL_MEM_READ_ONLY,
						sizeof(t_draw), NULL, &cl->status);
	if (cl->status != CL_SUCCESS)
	{
		exit_with_error(BUFFER_MSG, E_OPENCL);
	}
	cl->img = clCreateBuffer(cl->context, CL_MEM_WRITE_ONLY, sizeof(int) *
			fractol->data.size_line_int * fractol->sizey, NULL, &cl->status);
	if (cl->status != CL_SUCCESS)
	{
		exit_with_error(BUFFER_MSG, E_OPENCL);
	}
	cl->status = clSetKernelArg(cl->kernel, 0, sizeof(cl_mem), &cl->data);
	if (cl->status != CL_SUCCESS)
	{
		exit_with_error(ARG_MSG, E_OPENCL);
	}
	cl->status = clSetKernelArg(cl->kernel, 1, sizeof(cl_mem), &cl->img);
	if (cl->status != CL_SUCCESS)
	{
		exit_with_error(ARG_MSG, E_OPENCL);
	}
}

static void		init_kernel(t_fractol *fractol)
{
	t_cl	*cl;
	char	*kernel_str;

	cl = &fractol->cl;
	kernel_str = read_kernel_file(KERNEL_FILE);
	cl->program = clCreateProgramWithSource(cl->context, 1,
								(const char **)&kernel_str, NULL, &cl->status);
	if (cl->status != CL_SUCCESS)
	{
		exit_with_error(PROGRAM_MSG, E_OPENCL);
	}
	free(kernel_str);
	cl->status = clBuildProgram(cl->program, cl->num_devices, &cl->device,
								NULL, NULL, NULL);
	if (cl->status != CL_SUCCESS)
	{
		exit_with_error(BUILD_MSG, E_OPENCL);
	}
	cl->kernel = clCreateKernel(cl->program, "fractol", &cl->status);
	if (cl->status != CL_SUCCESS)
	{
		exit_with_error(KERNEL_MSG, E_OPENCL);
	}
	init_kernel_args(fractol);
}

void			init_cl(t_fractol *fractol)
{
	t_cl	*cl;

	cl = &fractol->cl;
	get_platform(cl);
	get_device(cl);
	cl->context = clCreateContext(NULL, DEVICES, &cl->device, NULL, NULL,
									&cl->status);
	if (cl->status != CL_SUCCESS)
	{
		exit_with_error(CONTEXT_MSG, E_OPENCL);
	}
	cl->queue = clCreateCommandQueue(cl->context, cl->device, 0, &cl->status);
	if (cl->status != CL_SUCCESS)
	{
		exit_with_error(QUEUE_MSG, E_OPENCL);
	}
	init_kernel(fractol);
}
