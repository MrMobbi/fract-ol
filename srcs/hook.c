/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:27:30 by mjulliat          #+#    #+#             */
/*   Updated: 2022/11/15 17:24:50 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	fractal_close(t_data *prog)
{
	(void) prog;
	exit(0);
}

int	key_hook(int keycode, t_data *prog)
{
	if (keycode == KEY_ESC)
		mlx_hook(prog->win, 2, 0, &fractal_close, &prog);
	return (0);
}
