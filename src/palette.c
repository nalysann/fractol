/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palette.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 09:42:40 by nalysann          #+#    #+#             */
/*   Updated: 2020/09/24 09:42:41 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

#include "ft_error.h"

#include <stdlib.h>

static int		get_color(int color_beg, int color_end, int iter, int max_iter)
{
	int		red;
	int		green;
	int		blue;

	red = ((color_beg & 0xFF0000) >> 16) + (((color_end & 0xFF0000) >> 16) - ((color_beg & 0xFF0000) >> 16)) * iter / max_iter;
	green = ((color_beg & 0x00FF00) >> 8) + (((color_end & 0x00FF00) >> 8) - ((color_beg & 0x00FF00) >> 8)) * iter / max_iter;
	blue = (color_beg & 0x0000FF) + ((color_end & 0x0000FF) - (color_beg & 0x0000FF)) * iter / max_iter;
	return (red << 16 | green << 8 | blue);
}

void			generate_palette(int **palette, int color_beg, int color_end,
						int max_iter)
{
	int		iter;

	*palette = (int *)malloc(sizeof(int) * (max_iter + 1));
	if (palette == NULL)
		ft_throw(ALLOC_MSG, E_ALLOC);
	iter = 0;
	while (iter <= max_iter)
	{
		(*palette)[iter] = get_color(color_beg, color_end, iter, max_iter);
		++iter;
	}
}
