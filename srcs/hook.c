/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:27:30 by mjulliat          #+#    #+#             */
/*   Updated: 2022/11/09 11:54:08 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close(t_prog *prog)
{
	mlx_destroy_image(prog->mlx, prog->win);
	mlx_destroy_window(prog->mlx, prog->win);
	exit(0);
	return (0);
}

int	key_hook(int keycode, t_prog *prog)
{
	if (keycode == KEY_ESC)
		mlx_hook(prog->win, 2, 0, close, &prog);
	return (0);
}
