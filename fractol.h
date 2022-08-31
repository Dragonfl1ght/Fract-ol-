/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkory <hkory@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:01:37 by hkory             #+#    #+#             */
/*   Updated: 2022/05/30 19:22:54 by hkory            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <mlx.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>

# define W 500

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	int			x;
	int			y;
	int			color;
	char		*fractolname;
	float		side;
	float		scale;
	float		left;
	float		top;
	long double	zx;
	long double	zy;
	long double	cx;
	long double	cy;
	long double	tempx;
	t_data		*data;
}	t_vars;

int			ft_close(int keycode, t_vars *vars);
void		my_mlx_pixel_put(t_vars *vars, int x, int y, int color);
int			create_trgb(int t, int r, int g, int b);
int			mouse_hook(int keycode, int x, int y, t_vars *vars);
int			motion(int keycode, t_vars *vars);
int			zoom(int keycode, t_vars *vars);
void		mandelbrotcalc(t_vars *vars, int count);
void		burningshipcalc(t_vars *vars, int count);
void		juliacalc(t_vars *vars, int count);
void		fractolreciever(t_vars *vars);
void		color_keys(int keycode, t_vars *vars);
long int	color(int it, int color);
int			ft_strcmp(char *s1, char *s2);
void		input_error(void);
void		julia_init1(t_vars *vars);
void		julia_init2(t_vars *vars);
void		julia_init3(t_vars *vars);
void		juliarec(t_vars *vars);
void		ft_putstr(char *s);

#endif