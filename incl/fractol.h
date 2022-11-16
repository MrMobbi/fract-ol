/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:53:14 by mjulliat          #+#    #+#             */
/*   Updated: 2022/11/16 15:02:18 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libmlx/mlx.h"
# include "../ft_printf/ft_printf.h"
# include "keycode.h"
# include <stdlib.h>

# define FR1		"Julia"
# define FR2		"Mandelbrot"
# define FR3		"Bruningship"
# define FR4		"Budhabrot"
# define WIN_LEN	800	
# define WIN_HIGH	600

typedef struct s_cord {
	int		x;
	int		y;
}		t_cord;

typedef struct s_nbcomp {
	double	r;
	double	i;
}			t_nbcomp;

typedef struct s_data {
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_len;
	int			endian;
	void		*mlx;
	void		*win;
	char		*type;
}				t_data;

//		##### MAIN.C #####
int		ft_argerror(int ac, char **av);

//		##### HOOK.C Proto #####
int		fractal_close(t_data *prog);
int		key_hook(int keycode, t_data *prog);

//		##### FRACTAL_INTI.C Proto #####
double	ft_norme_complex(t_nbcomp *nbr);
int		fractal_init(t_data *prog);
int		ft_iter_v2(t_nbcomp *n1, t_nbcomp *n2, double i, int max_iter);
void	calcul_real_and_im(t_data *prog, t_cord *pos, t_nbcomp *nbr);
void	pixel_to_comp(t_cord *pos, t_nbcomp *nbr);

//		##### COLORS.C #####
int		encode_rgb(uint8_t red, uint8_t green, uint8_t blue);

//		##### UTILS.C #####
int		ft_strcmp(const char *s1, const char *s2);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

//		###### SET_FRACTAL.C #####
void	set_fractal(t_data *data, int ac, char **av);

#endif
