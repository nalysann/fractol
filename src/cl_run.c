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
#include "error.h"
#include "fractol.h"

#include "ft_error.h"
#include "mlx.h"

void	run_cl(t_fractol *fractol)
{
	t_cl			*cl;
	const size_t	global_work_size = fractol->int_params[1] *
										fractol->int_params[2];

	cl = &fractol->cl;
	cl->status = clEnqueueWriteBuffer(cl->queue, cl->int_params, CL_TRUE, 0,
				sizeof(int) * INT_PARAMS, fractol->int_params, 0, NULL, NULL);
	if (cl->status != CL_SUCCESS)
		ft_throw(BUFFER_W_MSG, E_OPENCL);
	cl->status = clEnqueueWriteBuffer(cl->queue, cl->double_params, CL_TRUE, 0,
		sizeof(double) * double_PARAMS, fractol->double_params, 0, NULL, NULL);
	if (cl->status != CL_SUCCESS)
		ft_throw(BUFFER_W_MSG, E_OPENCL);
	cl->status = clEnqueueWriteBuffer(cl->queue, cl->palette, CL_TRUE, 0,
sizeof(int) * (fractol->int_params[3] + 1), fractol->palette, 0, NULL, NULL);
	if (cl->status != CL_SUCCESS)
		ft_throw(BUFFER_W_MSG, E_OPENCL);
	cl->status = clEnqueueNDRangeKernel(cl->queue, cl->kernel, 1, NULL,
									&global_work_size, NULL, 0, NULL, NULL);
	if (cl->status != CL_SUCCESS)
		ft_throw(EXECUTE_MSG, E_OPENCL);
	cl->status = clEnqueueReadBuffer(cl->queue, cl->img, CL_TRUE, 0,
				sizeof(int) * fractol->int_params[1] * fractol->int_params[2],
				fractol->img.data_addr, 0, NULL, NULL);
	if (cl->status != CL_SUCCESS)
		ft_throw(BUFFER_R_MSG, E_OPENCL);
	mlx_put_image_to_window(fractol->mlx_ptr, fractol->win_ptr,
							fractol->img.ptr, 0, 0);
}
