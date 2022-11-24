/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:06:20 by mjulliat          #+#    #+#             */
/*   Updated: 2022/11/22 17:10:13 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYCODE_H
# define KEYCODE_H

//	## Quit ##
# define KEY_ESC	53

//	## Set Color ##
# define KEY_1		18
# define KEY_2		19
# define KEY_3		20
# define KEY_4		21

//	## Set Fractal ##
# define KEY_M		46
# define KEY_J		38
# define KEY_B		11
# define KEY_SPACE	49

//	## Movement ##
# define KEY_LEFT	123
# define KEY_RIGTH	124
# define KEY_UP		126
# define KEY_DOWN	125

//	## Set Supported Events ##
# define ON_KEYDOWN		2
# define ON_KEYUP		3
# define ON_MOUSEDOWN	4
# define ON_MOUSEUP		5
# define ON_MOUSEMOVE	6
# define ON_EXPOSE		12
# define ON_DESTROY		17

#endif
