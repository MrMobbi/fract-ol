/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 11:54:36 by mjulliat          #+#    #+#             */
/*   Updated: 2022/11/16 15:02:04 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int	main(int ac, char **av)
{
	t_data		prog;

	if (ft_argerror(ac, av) == 1)
		return (0);
	prog.mlx = mlx_init();
	prog.win = mlx_new_window(prog.mlx, WIN_LEN, WIN_HIGH, "TEST");
	prog.img = mlx_new_image(prog.mlx, WIN_LEN, WIN_HIGH);
	prog.addr = mlx_get_data_addr(prog.img, &prog.bits_per_pixel, \
			&prog.line_len, &prog.endian);
	set_fractal(&prog, ac, av);
	mlx_put_image_to_window(prog.mlx, prog.win, prog.img, 0, 0);
	mlx_hook(prog.win, 17, 0, &fractal_close, &prog);
	mlx_hook(prog.win, 2, 0, &key_hook, &prog);
	mlx_loop(prog.mlx);
}

int	ft_argerror(int ac, char **av)
{
	if (ac == 1)
		return (0);
	else if (ac > 2)
	{
		ft_printf("\nNombre d'agument invalide \n");
		return (1);
	}
	if (ft_strcmp(av[1], FR1) == 0)
		return (0);
	else if (ft_strcmp(av[1], FR2) == 0)
		return (0);
	else if (ft_strcmp(av[1], FR3) == 0)
		return (0);
	else if (ft_strcmp(av[1], FR4) == 0)
		return (0);
	else
	{
		ft_printf("\nEnter \"Julia\" \"Mandelbrot\" \"Burningship\" or ");
		ft_printf("\"Budhabrot\" as an argument\n");
		return (1);
	}
}
