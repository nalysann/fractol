/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 11:22:17 by nalysann          #+#    #+#             */
/*   Updated: 2020/09/14 11:22:18 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYBOARD_H
# define KEYBOARD_H

/*
** Functional keys
*/

# ifdef __APPLE__
#  define KEY_F1		122
#  define KEY_F2		120
#  define KEY_F3		99
#  define KEY_F4		118
#  define KEY_F5		96
#  define KEY_F6		97
#  define KEY_F7		98
#  define KEY_F8		100
#  define KEY_F9		101
#  define KEY_F10		109
#  define KEY_F11		110
#  define KEY_F12		111
#  define KEY_F13		105
#  define KEY_F14		107
#  define KEY_F15		113
#  define KEY_F16		106
#  define KEY_F17		64
#  define KEY_F18		79
#  define KEY_F19		80
# endif

/*
** Numbers, plus, minus
*/

# ifdef __APPLE__
#  define KEY_1			18
#  define KEY_2			19
#  define KEY_3			20
#  define KEY_4			21
#  define KEY_5			23
#  define KEY_6			22
#  define KEY_7			26
#  define KEY_8			28
#  define KEY_9			25
#  define KEY_0			29
#  define KEY_MINUS		27
#  define KEY_PLUS		24
# endif

/*
** Alphabet
*/

# ifdef __APPLE__
#  define KEY_A			0
#  define KEY_B			11
#  define KEY_C			8
#  define KEY_D			2
#  define KEY_E			14
#  define KEY_F			3
#  define KEY_G			5
#  define KEY_H			4
#  define KEY_I			34
#  define KEY_J			38
#  define KEY_K			40
#  define KEY_L			37
#  define KEY_M			46
#  define KEY_N			45
#  define KEY_O			31
#  define KEY_P			35
#  define KEY_Q			12
#  define KEY_R			15
#  define KEY_S			1
#  define KEY_T			17
#  define KEY_U			32
#  define KEY_V			9
#  define KEY_W			13
#  define KEY_X			7
#  define KEY_Y			16
#  define KEY_Z			6
# endif

/*
** Misc
*/

# ifdef __APPLE__
#  define KEY_ESC		53
#  define KEY_LSHIFT	257
#  define KEY_RSHIFT	258
#  define KEY_LCTRL		256
#  define KEY_RCTRL		269
#  define KEY_LCMD		259
#  define KEY_RCMD		260
#  define KEY_TAB		48
#  define KEY_ENTER		53
#  define KEY_CAPS		272
#  define KEY_ENTER		53
#  define KEY_SPACE		49
# endif

/*
** Arrows
*/

# ifdef __APPLE__
#  define KEY_UP		126
#  define KEY_DOWN		125
#  define KEY_LEFT		123
#  define KEY_RIGHT		124
# endif

/*
** Numpad
*/

# ifdef __APPLE__
#  define KEY_NUM_1		83
#  define KEY_NUM_2		84
#  define KEY_NUM_3		85
#  define KEY_NUM_4		86
#  define KEY_NUM_5		87
#  define KEY_NUM_6		88
#  define KEY_NUM_7		89
#  define KEY_NUM_8		91
#  define KEY_NUM_9		92
#  define KEY_NUM_0		82
#  define KEY_NUM_MINUS	78
#  define KEY_NUM_PLUS	69
# endif

/*
** Hook functions
*/

int		key_press(int keycode, void *param);
int		key_release(int keycode, void *param);
int		destroy_notify(void *param);

/*
** Keycode handlers
*/

void	change_max_iter(int keycode, t_fractol *fractol);
void	move(int keycode, t_fractol *fractol);
void	change_palette(int keycode, t_fractol *fractol);
void	change_type(int keycode, t_fractol *fractol);

#endif
