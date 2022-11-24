/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 19:03:55 by mjulliat          #+#    #+#             */
/*   Updated: 2022/11/24 14:58:34 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void	set_complex(t_data *p)
{
	(void) p;
}

int	render_next_frame(t_data *p)
{
	set_complex(p);
	fractal_init(p);
	mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
	return (0);
}

void	ft_init_offset(t_data *p)
{
	p->c.r = -1.75;
	p->c.i = 0.0;
	p->c1.r = 0.0;
	p->c1.i = 0.0;
	p->complx.imag_max = 1.5;
	p->complx.imag_min = -1.5;
	p->complx.imag_l = 3.0;
	p->complx.real_max = 2.0;
	p->complx.real_min = -2.0;
	p->complx.real_l = 4.0;
	p->off_x = 0.0;
	p->off_y = 0.0;
}

int	fractal_close(t_data *p)
{
	(void) p;
	exit(0);
	return (0);
}
