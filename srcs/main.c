/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 11:54:36 by mjulliat          #+#    #+#             */
/*   Updated: 2022/11/24 14:54:58 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	t_data	p;

	if (ft_argerror(&p, ac, av) == 1)
		return (0);
	ft_init_offset(&p);
	p.mlx = mlx_init();
	p.win = mlx_new_window(p.mlx, WIN_LEN, WIN_HIGH, p.type);
	p.img = mlx_new_image(p.mlx, WIN_LEN, WIN_HIGH);
	p.addr = mlx_get_data_addr(p.img, &p.bits_per_pixel, \
			&p.line_len, &p.endian);
	mlx_hook(p.win, ON_DESTROY, 0, &fractal_close, &p);
	mlx_hook(p.win, ON_KEYDOWN, 0, &key_hook, &p);
	mlx_mouse_hook(p.win, mouse_hook, &p);
	mlx_loop_hook(p.mlx, render_next_frame, &p);
	mlx_loop(p.mlx);
}

int	ft_argerror(t_data *p, int ac, char **av)
{
	if (ac > 2 || ac < 2)
	{
		ft_printf("---------------------\n");
		ft_printf("Enter \"./fractal\" with \"Julia\" or \"Mandelbrot\"\n");
		ft_printf("---------------------\n");
		return (1);
	}
	if (ft_strcmp(av[1], FR1) == 0)
		p->type = FR1;
	else if (ft_strcmp(av[1], FR2) == 0)
		p->type = FR2;
	else
	{
		ft_printf("---------------------\n");
		ft_printf("Enter \"Julia\" or \"Mandelbrot\" as an argument\n");
		ft_printf("---------------------\n");
		return (1);
	}
	return (0);
}
