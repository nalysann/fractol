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

#include "ft_error.h"

static void		get_platform(t_cl *cl)
{
	cl->status = clGetPlatformIDs(0, NULL, &cl->num_platforms);
	if (cl->status != CL_SUCCESS)
	{
		ft_throw(PLAT_MSG, E_OPENCL);
	}
	if (cl->num_platforms != PLATFORMS)
	{
		ft_throw(N_PLAT_MSG, E_OPENCL);
	}
	cl->status = clGetPlatformIDs(PLATFORMS, &cl->platform, NULL);
	if (cl->status != CL_SUCCESS)
	{
		ft_throw(G_PLAT_MSG, E_OPENCL);
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
		ft_throw(DEV_MSG, E_OPENCL);
	}
	if (cl->num_devices != DEVICES)
	{
		ft_throw(N_DEV_MSG, E_OPENCL);
	}
	cl->status = clGetDeviceIDs(cl->platform, cl->device_type, DEVICES,
								&cl->device, NULL);
	if (cl->status != CL_SUCCESS)
	{
		ft_throw(G_DEV_MSG, E_OPENCL);
	}
}

static void		init_kernel_args(t_fractol *fractol)
{
	t_cl	*cl;

	cl = &fractol->cl;
	cl->data = clCreateBuffer(cl->context, CL_MEM_USE_HOST_PTR, sizeof(t_draw),
								&fractol->data, &cl->status);
	if (cl->status != CL_SUCCESS)
	{
		ft_throw(BUFFER_MSG, E_OPENCL);
	}
	cl->img = clCreateBuffer(cl->context, CL_MEM_READ_WRITE,
			sizeof(int) * fractol->size_x * fractol->size_y, NULL, &cl->status);
	if (cl->status != CL_SUCCESS)
	{
		ft_throw(BUFFER_MSG, E_OPENCL);
	}
	cl->status = clSetKernelArg(cl->kernel, 0, sizeof(cl_mem), &cl->data);
	if (cl->status != CL_SUCCESS)
	{
		ft_throw(ARG_MSG, E_OPENCL);
	}
	cl->status = clSetKernelArg(cl->kernel, 1, sizeof(cl_mem), &cl->img);
	if (cl->status != CL_SUCCESS)
	{
		ft_throw(ARG_MSG, E_OPENCL);
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
		ft_throw(PROGRAM_MSG, E_OPENCL);
	}
	free(kernel_str);
	cl->status = clBuildProgram(cl->program, cl->num_devices, &cl->device,
								NULL, NULL, NULL);
	if (cl->status != CL_SUCCESS)
	{
		ft_throw(BUILD_MSG, E_OPENCL);
	}
	cl->kernel = clCreateKernel(cl->program, "fractol", &cl->status);
	if (cl->status != CL_SUCCESS)
	{
		ft_throw(KERNEL_MSG, E_OPENCL);
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
		ft_throw(CONTEXT_MSG, E_OPENCL);
	}
	cl->queue = clCreateCommandQueue(cl->context, cl->device, 0, &cl->status);
	if (cl->status != CL_SUCCESS)
	{
		ft_throw(QUEUE_MSG, E_OPENCL);
	}
	init_kernel(fractol);
}
