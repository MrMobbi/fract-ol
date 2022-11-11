/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:53:14 by mjulliat          #+#    #+#             */
/*   Updated: 2022/11/09 17:34:34 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FRACTOL_H
# define FRACTOL_H

# include "../libmlx/mlx.h"
# include "keycode.h"
# include <stdlib.h>

# define WIN_LEN		1920
# define WIN_HIGH		1080

typedef	struct	s_cord {
	int		x;
	int		y;
}		t_cord;

typedef struct	s_nbcomp {
	double	r;
	double	i;
}			t_nbcomp;

typedef	struct	s_data {
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_len;
	int			endian;
	void		*mlx;
	void		*win;
}				t_data;

int	key_hook(int keycode, t_data *prog);
int close(t_data *prog);

#endif
