/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 12:42:46 by nalysann          #+#    #+#             */
/*   Updated: 2020/09/14 12:42:46 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOUSE_H
# define MOUSE_H

# include "fractol.h"

/*
** Button codes
*/

# ifdef __APPLE__
#  define BUT_LEFT		1
#  define BUT_RIGHT		2
#  define BUT_MIDDLE	3
#  define BUT_UP		4
#  define BUT_DOWN		5
# endif

/*
** Hook functions
*/

int		button_press(int button, int x, int y, void *param);
int		motion_notify(int x, int y, void *param);

/*
** Button handlers
*/

void	zoom(int button, int x, int y, t_fractol *fractol);

#endif
