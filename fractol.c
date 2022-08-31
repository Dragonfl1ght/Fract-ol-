/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkory <hkory@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:01:40 by hkory             #+#    #+#             */
/*   Updated: 2022/05/31 15:01:12 by hkory            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	color_keys(int keycode, t_vars *vars)
{
	if (keycode == 18)
		vars->color = 0;
	if (keycode == 19)
		vars->color = 1;
	if (keycode == 20)
		vars->color = 2;
	if (keycode == 21)
		vars->color = 3;
	if (keycode == 22)
		vars->color = 4;
	if (keycode == 23)
		vars->color = 5;
	if (keycode == 24)
		vars->color = 6;
	if (keycode == 25)
		vars->color = 7;
}

void	first_init(t_vars *vars)
{
	vars->left = -0.55;
	vars->top = 0.45;
	vars->side = 4;
	vars->y = 0;
}

int	main(int argc, char **argv)
{
	t_vars	*vars;

	if (argc == 2)
	{
		vars = (t_vars *)(malloc(sizeof(t_vars)));
		vars->data = (t_data *)(malloc(sizeof(t_data)));
		first_init(vars);
		vars->fractolname = argv[1];
		vars->color = 1;
		vars->mlx = mlx_init();
		vars->win = mlx_new_window(vars->mlx, W, W, "fractol");
		vars->data->img = mlx_new_image(vars->mlx, W, W);
		vars->data->addr = mlx_get_data_addr(vars->data->img,
				&vars->data->bits_per_pixel, &vars->data->line_length, \
				&vars->data->endian);
		fractolreciever(vars);
		mlx_mouse_hook(vars->win, mouse_hook, vars);
		mlx_hook(vars->win, 2, 0, ft_close, vars);
		mlx_hook(vars->win, 17, 0, ft_close, vars);
		mlx_hook(vars->win, 2, 0, zoom, vars);
		mlx_loop(vars->mlx);
	}
	else
		input_error();
	return (0);
}

void	juliarec(t_vars *vars)
{
	if (!ft_strcmp(vars->fractolname, "Julia1"))
		julia_init1(vars);
	if (!ft_strcmp(vars->fractolname, "Julia2"))
		julia_init2(vars);
	if (!ft_strcmp(vars->fractolname, "Julia3"))
		julia_init3(vars);
}

void	fractolreciever(t_vars *vars)
{
	if (!ft_strcmp(vars->fractolname, "Mandelbrot"))
		mandelbrotcalc(vars, 0);
	else if (!ft_strcmp(vars->fractolname, "Burning_ship"))
		burningshipcalc(vars, 0);
	else if (!ft_strcmp(vars->fractolname, "Julia1"))
	{
		julia_init1(vars);
		juliacalc(vars, 0);
	}
	else if (!ft_strcmp(vars->fractolname, "Julia2"))
	{
		julia_init2(vars);
		juliacalc(vars, 0);
	}
	else if (!ft_strcmp(vars->fractolname, "Julia3"))
	{
		julia_init3(vars);
		juliacalc(vars, 0);
	}
	else
		input_error();
}
