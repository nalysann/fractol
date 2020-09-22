/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 12:42:32 by nalysann          #+#    #+#             */
/*   Updated: 2020/09/14 12:42:33 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOK_H
# define HOOK_H

# define KEY_PRESS				2
# define KEY_RELEASE			3
# define BUTTON_PRESS			4
# define BUTTON_RELEASE			5
# define MOTION_NOTIFY			6
# define DESTROY_NOTIFY			17

# define KEY_PRESS_MASK			(1L << 0)
# define KEY_RELEASE_MASK		(1L << 1)
# define BUTTON_PRESS_MASK		(1L << 2)
# define BUTTON_RELEASE_MASK	(1L << 3)
# define MOTION_NOTIFY_MASK		(1L << 6)
# define STRUCTURE_NOTIFY_MASK	(1L << 17)

void	hook_all(void *param);

#endif
