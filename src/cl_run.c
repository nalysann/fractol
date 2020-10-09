/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_run.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 18:22:57 by nalysann          #+#    #+#             */
/*   Updated: 2020/09/18 18:22:58 by nalysann         ###   ########.fr       */
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

#include "ft_stdio.h"

#include "mlx.h"

void	run_cl(t_fractol *fractol)
{
	t_cl			*cl;
	const size_t	global_work_size = fractol->sizex * fractol->sizey;

	cl = &fractol->cl;
	cl->status = clEnqueueWriteBuffer(cl->queue, cl->data, CL_TRUE, 0,
				sizeof(t_draw), &fractol->data, 0, NULL, NULL);
	if (cl->status != CL_SUCCESS)
	{
		exit_with_error(BUFFER_W_MSG, E_OPENCL);
	}
	cl->status = clEnqueueNDRangeKernel(cl->queue, cl->kernel, 1, NULL,
									&global_work_size, NULL, 0, NULL, NULL);
	if (cl->status != CL_SUCCESS)
	{
		exit_with_error(EXECUTE_MSG, E_OPENCL);
	}
	cl->status = clEnqueueReadBuffer(cl->queue, cl->img, CL_TRUE, 0,
				sizeof(int) * fractol->data.size_line_int * fractol->sizey,
				fractol->img.data_addr, 0, NULL, NULL);
	if (cl->status != CL_SUCCESS)
	{
		exit_with_error(BUFFER_R_MSG, E_OPENCL);
	}
	mlx_put_image_to_window(fractol->mlx_ptr, fractol->win_ptr,
							fractol->img.ptr, 0, 0);
}
