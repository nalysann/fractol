/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 16:43:11 by nalysann          #+#    #+#             */
/*   Updated: 2020/09/18 16:43:12 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

typedef struct	s_img
{
	void	*ptr;
	int		*data_addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}				t_img;

#endif
