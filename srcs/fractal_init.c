/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:57:14 by mjulliat          #+#    #+#             */
/*   Updated: 2022/11/16 15:02:14 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	fractal_init(t_data *prog)
{
	t_nbcomp	nbr;
	t_cord		pos;

	pos.x = 0;
	pos.y = 0;
	nbr.r = 0;
	nbr.i = 0;
	while (pos.y < WIN_HIGH)
	{		
		while (pos.x < WIN_LEN)
		{
			calcul_real_and_im(prog, &pos, &nbr);
			pos.x++;
		}
		pos.x = 0;
		pos.y++;
	}
	return (0);
}

void	pixel_to_comp(t_cord *pos, t_nbcomp *nbr)
{
	double	half_len;
	double	half_high;

	half_len = (double)WIN_LEN / 2;
	half_high = (double)WIN_HIGH / 2;
	if (pos->x >= half_len)
		nbr->r = (pos->x - half_len) / half_len * 2;
	else
		nbr->r = ((half_len - pos->x) / half_len) * 2 * -1;
	if (pos->y <= half_high)
		nbr->i = (half_high - pos->y) / half_high * 1.5;
	else
		nbr->i = (pos->y - half_high) / half_high * 1.5 * -1;
	if (pos->x == 0 && pos->y == 0)
	{
		nbr->r = -2;
		nbr->i = 1.5;
	}
	else if (pos->x == 0)
		nbr->r = -2;
	else if (pos->y == 0)
		nbr->i = 1.5;
}

double	ft_norme_complex(t_nbcomp *nbr)
{
	double	res;

	res = (nbr->r * nbr->r) + (nbr->i * nbr->i);
	return (res);
}

int	ft_iter_v2(t_nbcomp *n1, t_nbcomp *n2, double i, int max_iter)
{
	double	tmp;

	while (i <= max_iter)
	{
		tmp = (n1->r * n1->r) - (n1->i * n1->i);
		n1->i = ((2 * n1->r) * n1->i) + n2->i;
		n1->r = tmp + n2->r;
		if (ft_norme_complex(n1) > 4)
			break ;
		i++;
	}
	return (i);
}

void	calcul_real_and_im(t_data *prog, t_cord *pos, t_nbcomp *nbr)
{
	double		i;
	int			max_iter;
	t_nbcomp	c;

	c.r = 0;
	c.i = 0;
	i = 0;
	max_iter = 50;
	pixel_to_comp(pos, nbr);
	if (ft_strcmp(prog->type, FR1) == 0)
		i = ft_iter_v2(nbr, &c, i, max_iter);
	else if (ft_strcmp(prog->type, FR2) == 0)
		i = ft_iter_v2(&c, nbr, i, max_iter);
	if (i >= max_iter)
		my_mlx_pixel_put(prog, pos->x, pos->y, encode_rgb(0, 0, 0));
	else
	{
		if (i * i > 255)
			my_mlx_pixel_put(prog, pos->x, pos->y,
				encode_rgb(0, 0, (255 / max_iter) * i));
		else
			my_mlx_pixel_put(prog, pos->x, pos->y,
				encode_rgb(0, 0, (255 / max_iter) * i * i));
	}
}
