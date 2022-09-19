/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 04:13:09 by alopez-g          #+#    #+#             */
/*   Updated: 2022/09/17 11:13:50 by al7aro-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define FT_LITTLE_ENDIAN 0
# define FT_BIG_ENDIAN 1
# define IX0 -1200.0
# define IY0 -600.0

# define IY1 600.0
# define MIN_ZOOM 100.0
# define X2K 2048
# define Y2K 1080
# define FUNC_N 3
# define RAN_N 6
# define DIVERGENCE 2 

# include "ft_math.h"
# include "temp.h"

typedef t_vec2	(*t_func)(t_vec2, t_vec2, int);
typedef enum e_fractal
{
	JULIA,
	MANDELBROT,
	KO
}		t_fractal;

typedef struct s_img
{
	char	*buffer;
	void	*img;
	int		bpp;
	int		line_size;
	int		endi;
	t_vec2	pos;
	t_vec2	res;
	double	aspect;
}		t_img;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	t_vec2	res;
}		t_mlx;

typedef struct s_ran
{
	int	ran[16];
	int	size;
}				t_ran;

typedef struct s_fract
{
	t_mlx		*mlx;
	t_img		*img;
	t_img		*menu;
	t_ran		ran[RAN_N];
	char		ran_sel;
	char		menu_toggle;
	t_vec2		center;
	t_vec2		prev_center;
	t_vec2		mouse_pos;
	char		moving_julia;
	double		world[4];
	double		prev_zoom;
	double		zoom;
	double		szoom;
	t_fractal	type;
	t_func		func[FUNC_N];
	char		func_sel;
	double		it;
	int			exp;
	t_vec2		julia_init;
	int			render_factor;
}				t_fract;

t_vec2	znc(t_vec2 z, t_vec2 c, int exp);
t_vec2	zninvc(t_vec2 z, t_vec2 c, int exp);
t_vec2	ncorn(t_vec2 z, t_vec2 c, int exp);
t_vec2	bship(t_vec2 z, t_vec2 c, int exp);
int		diverges(t_fract f, void *z, void *c);

#endif
