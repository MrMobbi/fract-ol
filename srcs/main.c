/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 11:54:36 by mjulliat          #+#    #+#             */
/*   Updated: 2022/11/02 17:24:23 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

typedef	struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
}			t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bits_per_pixel /8));
	*(unsigned int *)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	int		i;
	int		i1;
	int		j;
	int		j1;
	long long int
	t_data	test;

	i = 0;
	j = 0;
	j1 = 500;
	i1 = 500;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello, PH");
	test.img = mlx_new_image(mlx, 1920, 1080);
	test.addr = mlx_get_data_addr(test.img, &test.bits_per_pixel, &test.line_len,
			&test.endian);
	while (i < 500)
	{
		my_mlx_pixel_put(&test, 1, i, 0x00FF0000);
		my_mlx_pixel_put(&test, j, 1, 0x00FF0000);
		my_mlx_pixel_put(&test, 500, i, 0x00FF0000);
		my_mlx_pixel_put(&test, j, 500, 0x00FF0000);
		j++;
		++i;
		j1--;
		i1--;
	}
	mlx_put_image_to_window(mlx, mlx_win, test.img, 0, 0);
	mlx_loop(mlx);	
}

