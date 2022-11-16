/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:19:53 by mjulliat          #+#    #+#             */
/*   Updated: 2022/11/16 15:02:26 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_fractal(t_data *prog, int ac, char **av)
{
	if (ac < 2)
		prog->type = FR1;
	else if (ft_strcmp(av[1], FR1) == 0)
		prog->type = FR1;
	else if (ft_strcmp(av[1], FR2) == 0)
		prog->type = FR2;
	fractal_init(prog);
}
