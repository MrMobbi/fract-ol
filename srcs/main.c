/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 11:54:36 by mjulliat          #+#    #+#             */
/*   Updated: 2022/11/10 13:19:04 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>
#include <stdio.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bits_per_pixel /8));
	*(unsigned int *)dst = color;
}

int fractal_init(t_data *prog, t_cord *pos);
void	calcul_real_and_im(t_data *prog, t_cord *pos, t_nbcomp *nbr);
void	pixel_to_comp(t_cord *pos, t_nbcomp *nbr);
double	ft_norme_complex(t_nbcomp *nbr);

int	main(void)
{
	t_data		prog;
	t_cord		pos;

	prog.mlx = mlx_init();
	pos.x = 0;
	pos.y = 0;
	prog.win = mlx_new_window(prog.mlx, WIN_LEN, WIN_HIGH, "Hello, PH");
	prog.img = mlx_new_image(prog.mlx, WIN_LEN, WIN_HIGH);
	prog.addr = mlx_get_data_addr(prog.img, &prog.bits_per_pixel, &prog.line_len,
			&prog.endian);
/*	while (pos.y < WIN_HIGH)
	{
		while (pos.x < WIN_LEN)
		{
			if (pos.x < (WIN_LEN / 2) && pos.y <= (WIN_HIGH / 2))
				my_mlx_pixel_put(&test, pos.x, pos.y, 0x00FF0000); // rouge -> -1 / 1
			else if (pos.x < (WIN_LEN / 2) && pos.y > (WIN_HIGH / 2))
				my_mlx_pixel_put(&test, pos.x, pos.y, 0x0000FF00); // vert -> -1 / -1
			else if (pos.x >= (WIN_LEN / 2) && pos.y <= (WIN_HIGH / 2))
				my_mlx_pixel_put(&test, pos.x, pos.y, 0x000000FF); // bleu -> 1 / 1
			else if (pos.x >= (WIN_LEN / 2) && pos.y > (WIN_HIGH / 2))
				my_mlx_pixel_put(&test, pos.x, pos.y, 0x00FFFF00); // jaune -> 1 / -1
			pos.x++;
		}
		pos.x = 0;
		pos.y++;
	}
	*/
	fractal_init(&prog, &pos);
	mlx_put_image_to_window(prog.mlx, prog.win, prog.img, 0, 0);
	mlx_hook(prog.win, 17, 0, close, &prog);
	mlx_hook(prog.win, 2, 0, key_hook, &prog);
	mlx_loop(prog.mlx);
}

int fractal_init(t_data *prog, t_cord *pos)
{
	t_nbcomp	nbr;

	nbr.r = 0;
	nbr.i = 0;
	while (pos->y < WIN_HIGH)
	{		while (pos->x < WIN_LEN)
		{
			calcul_real_and_im(prog, pos, &nbr);
			pos->x++;
		}
		pos->x = 0;
		pos->y++;
	}
	return (0);
}

void	pixel_to_comp(t_cord *pos, t_nbcomp *nbr)
{
	nbr->r = (2 - -2) * (((2 * pos->x) / (double)WIN_LEN) - 1);
	nbr->i = (1 - -1) * (((-2 * pos->y) / (double)WIN_HIGH) + 1);	
}

double	ft_norme_complex(t_nbcomp *nbr)
{
	double res;

	res = (nbr->r * nbr->r) + (nbr->i * nbr->i);
	return (res);
}

void	ft_iter(t_nbcomp *nbr)
{
	double	tmp;

	tmp = (nbr->r * nbr->r) - (nbr->i * nbr->i);
	nbr->i = (2 * nbr->r) * nbr->i;
	nbr->r = tmp -1;
}

void	calcul_real_and_im(t_data *prog, t_cord *pos, t_nbcomp *nbr)
{
	int		i;
	int		max_iter;

	i = 0;
	max_iter = 200;
	pixel_to_comp(pos, nbr);
	while (i <= max_iter)
	{
		ft_iter(nbr);
		if (ft_norme_complex(nbr) > 4)
			break ;
		i++;
	}
	if (i >= max_iter)
		my_mlx_pixel_put(prog, pos->x, pos->y, 0x00000000); 	
	else
		my_mlx_pixel_put(prog, pos->x, pos->y, 0x0000FF00); 	
}
