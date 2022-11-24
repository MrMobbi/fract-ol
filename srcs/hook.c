/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:27:30 by mjulliat          #+#    #+#             */
/*   Updated: 2022/11/24 15:16:59 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int	key_hook(int keycode, t_data *p)
{
	if (keycode == KEY_ESC)
		exit(0);
	if (keycode == KEY_SPACE)
		ft_init_offset(p);
	if (keycode == KEY_LEFT)
		p->off_x -= 0.1 * p->complx.real_l;
	if (keycode == KEY_RIGTH)
		p->off_x += 0.1 * p->complx.real_l;
	if (keycode == KEY_UP)
		p->off_y += 0.1 * p->complx.imag_l;
	if (keycode == KEY_DOWN)
		p->off_y -= 0.1 * p->complx.imag_l;
	if (keycode == KEY_M)
		p->type = FR2;
	if (keycode == KEY_J)
		p->type = FR1;
	return (0);
}

void	zoom_out(t_data *p)
{
	double	backup_real;
	double	backup_imag;
	double	delta_real;
	double	delta_imag;

	backup_real = p->complx.real_l;
	backup_imag = p->complx.imag_l;
	p->complx.real_l /= 1.1;
	p->complx.imag_l /= 1.1;
	delta_real = p->complx.real_l - backup_real;
	delta_imag = p->complx.imag_l - backup_imag;
	p->complx.real_min -= delta_real / 2;
	p->complx.real_max += delta_real / 2;
	p->complx.imag_min -= delta_imag / 2;
	p->complx.imag_max += delta_imag / 2;
}

void	zoom_in(t_data *p)
{
	double	backup_real;
	double	backup_imag;
	double	delta_real;
	double	delta_imag;

	backup_real = p->complx.real_l;
	backup_imag = p->complx.imag_l;
	p->complx.real_l *= 1.1;
	p->complx.imag_l *= 1.1;
	delta_real = p->complx.real_l - backup_real;
	delta_imag = p->complx.imag_l - backup_imag;
	p->complx.real_min -= delta_real / 2;
	p->complx.real_max += delta_real / 2;
	p->complx.imag_min -= delta_imag / 2;
	p->complx.imag_max += delta_imag / 2;
}

void	handle_click(t_data *p, int x, int y)
{
	double	half_l;
	double	half_h;

	half_l = (double)WIN_LEN / 2;
	half_h = (double)WIN_HIGH / 2;
	if (x >= half_l)
		p->c.r = ((x - half_l) / half_l * p->complx.real_max) + p->off_x;
	else
		p->c.r = ((half_l - x) / half_l * p->complx.real_min) + p->off_x;
	if (y <= half_h)
		p->c.i = ((half_h - y) / half_h * p->complx.imag_max) + p->off_y;
	else
		p->c.i = ((y - half_h) / half_h * p->complx.imag_min) + p->off_y;
	if (x == 0.0 && y == 0.0)
	{
		p->c.r = p->complx.real_min + p->off_x;
		p->c.i = p->complx.imag_max + p->off_y;
	}
	else if (x == 0.0)
		p->c.r = p->complx.real_min + p->off_x;
	else if (y == 0.0)
		p->c.i = p->complx.imag_max + p->off_y;
}

int	mouse_hook(int bouton, int x, int y, t_data *p)
{
	if (bouton == 4)
		zoom_in(p);
	else if (bouton == 5)
		zoom_out(p);
	else if (bouton == 1)
		handle_click(p, x, y);
	return (0);
}
