/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:57:14 by mjulliat          #+#    #+#             */
/*   Updated: 2022/11/24 14:57:54 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int	fractal_init(t_data *p)
{
	t_nbcomp	nbr;

	p->pos.x = 0.0;
	p->pos.y = 0.0;
	nbr.r = 0.0;
	nbr.i = 0.0;
	while (p->pos.y < WIN_HIGH)
	{
		while (p->pos.x < WIN_LEN)
		{
			calcul_real_and_im(p, &nbr);
			p->pos.x++;
		}
		p->pos.x = 0;
		p->pos.y++;
	}
	return (0);
}

void	pixel_to_comp(t_data *p, double x, double y, t_nbcomp *nbr)
{
	double	half_l;
	double	half_h;

	half_l = (double)WIN_LEN / 2;
	half_h = (double)WIN_HIGH / 2;
	if (x >= half_l)
		nbr->r = ((x - half_l) / half_l * p->complx.real_max) + p->off_x;
	else
		nbr->r = ((half_l - x) / half_l * p->complx.real_min) + p->off_x;
	if (y <= half_h)
		nbr->i = ((half_h - y) / half_h * p->complx.imag_max) + p->off_y;
	else
		nbr->i = ((y - half_h) / half_h * p->complx.imag_min) + p->off_y;
	if (x == 0.0 && y == 0.0)
	{
		nbr->r = p->complx.real_min + p->off_x;
		nbr->i = p->complx.imag_max + p->off_y;
	}
	else if (x == 0.0)
		nbr->r = p->complx.real_min + p->off_x;
	else if (y == 0.0)
		nbr->i = p->complx.imag_max + p->off_y;
}

double	ft_norme_complex(t_nbcomp *nbr)
{
	double	res;

	res = (nbr->r * nbr->r) + (nbr->i * nbr->i);
	return (res);
}

int	ft_iter_v2(t_nbcomp *n1, t_nbcomp *n2, double i, int max_iter)
{
	double		tmp;
	t_nbcomp	tmp1;
	t_nbcomp	tmp2;

	tmp1 = *n1;
	tmp2 = *n2;
	while (i <= max_iter)
	{
		tmp = (tmp1.r * tmp1.r) - (tmp1.i * tmp1.i);
		tmp1.i = ((2 * tmp1.r) * tmp1.i) + tmp2.i;
		tmp1.r = tmp + tmp2.r;
		if (ft_norme_complex(&tmp1) > 4)
			break ;
		i++;
	}
	return (i);
}

void	calcul_real_and_im(t_data *p, t_nbcomp *nbr)
{
	double		i;
	int			max_iter;

	i = 0;
	max_iter = 70;
	pixel_to_comp(p, p->pos.x, p->pos.y, nbr);
	if (ft_strcmp(p->type, FR1) == 0)
		i = ft_iter_v2(nbr, &p->c, i, max_iter);
	else if (ft_strcmp(p->type, FR2) == 0)
		i = ft_iter_v2(&p->c1, nbr, i, max_iter);
	if (i >= max_iter)
		my_mlx_pixel_put(p, p->pos.x, p->pos.y, encode_rgb(0, 0, 0));
	else
		my_mlx_pixel_put(p, p->pos.x, p->pos.y, \
			encode_rgb(0, 0, (255 / max_iter) * i * i));
}
