/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_release.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 12:24:19 by nalysann          #+#    #+#             */
/*   Updated: 2020/10/09 12:24:20 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef __APPLE__
# include <OpenCL/opencl.h>
#else
# include <CL/cl.h>
#endif

#include "cl_data.h"
#include "error.h"
#include "fractol.h"

#include "ft_stdio.h"

void	release_cl(t_fractol *fractol)
{
	t_cl	*cl;

	cl = &fractol->cl;
	cl->status = clReleaseMemObject(cl->img);
	if (cl->status != CL_SUCCESS)
		exit_with_error(M_RELEASE_MSG, E_OPENCL);
	cl->status = clReleaseMemObject(cl->data);
	if (cl->status != CL_SUCCESS)
		exit_with_error(M_RELEASE_MSG, E_OPENCL);
	cl->status = clReleaseKernel(cl->kernel);
	if (cl->status != CL_SUCCESS)
		exit_with_error(K_RELEASE_MSG, E_OPENCL);
	cl->status = clReleaseProgram(cl->program);
	if (cl->status != CL_SUCCESS)
		exit_with_error(P_RELEASE_MSG, E_OPENCL);
	cl->status = clReleaseCommandQueue(cl->queue);
	if (cl->status != CL_SUCCESS)
		exit_with_error(Q_RELEASE_MSG, E_OPENCL);
	cl->status = clReleaseContext(cl->context);
	if (cl->status != CL_SUCCESS)
		exit_with_error(C_RELEASE_MSG, E_OPENCL);
}
