/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:53:14 by mjulliat          #+#    #+#             */
/*   Updated: 2022/11/24 14:58:07 by mjulliat         ###   ########.fr       */
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
# define WIN_LEN	800	
# define WIN_HIGH	600

typedef struct s_cord {
	double	x;
	double	y;
}			t_cord;

typedef struct s_nbcomp {
	double	r;
	double	i;
}			t_nbcomp;

typedef struct s_complx {
	double	imag_max;
	double	imag_min;
	double	imag_l;
	double	real_max;
	double	real_min;
	double	real_l;
}			t_complx;

typedef struct s_data {
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_len;
	int			endian;
	void		*mlx;
	void		*win;
	char		*type;
	t_nbcomp	c;
	t_nbcomp	c1;
	t_cord		pos;
	t_complx	complx;
	double		off_x;
	double		off_y;
}				t_data;

//		##### MAIN.C #####
int		ft_argerror(t_data *p, int ac, char **av);

//		##### HOOK.C Proto #####
int		key_hook(int keycode, t_data *p);
int		mouse_hook(int bouton, int x, int y, t_data *p);

//		##### FRACTAL_INTI.C Proto #####
double	ft_norme_complex(t_nbcomp *nbr);
int		fractal_init(t_data *p);
int		ft_iter_v2(t_nbcomp *n1, t_nbcomp *n2, double i, int max_iter);
void	calcul_real_and_im(t_data *prog, t_nbcomp *nbr);
void	pixel_to_comp(t_data *p, double x, double y, t_nbcomp *nbr);

//		##### COLORS.C #####
int		encode_rgb(uint8_t red, uint8_t green, uint8_t blue);

//		##### UTILS.C #####
int		ft_strcmp(const char *s1, const char *s2);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

//		###### SET_FRACTAL.C #####
void	set_complex(t_data *p);
int		render_next_frame(t_data *p);
void	ft_init_offset(t_data *p);
int		fractal_close(t_data *p);

#endif
