/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkory <hkory@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:01:49 by hkory             #+#    #+#             */
/*   Updated: 2022/05/30 19:15:37 by hkory            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_close(int keycode, t_vars *vars)
{
	(void)keycode;
	(void)vars;
	exit(0);
}

int	mouse_hook(int keycode, int x, int y, t_vars *vars)
{
	if (keycode == 4)
		vars->side *= 0.9;
	if (keycode == 5)
		vars->side *= 1.1;
	if (!ft_strcmp(vars->fractolname, "Mandelbrot"))
		mandelbrotcalc(vars, 0);
	if (!ft_strcmp(vars->fractolname, "Burning_ship"))
		burningshipcalc(vars, 0);
	if (!ft_strcmp(vars->fractolname, "Julia1"))
		juliacalc(vars, 0);
	if (!ft_strcmp(vars->fractolname, "Julia2"))
		juliacalc(vars, 0);
	if (!ft_strcmp(vars->fractolname, "Julia3"))
		juliacalc(vars, 0);
	(void)x;
	(void)y;
	return (0);
}

int	motion(int keycode, t_vars *vars)
{
	color_keys(keycode, vars);
	if (keycode == 91)
		vars->top -= 0.1 * vars->side;
	if (keycode == 87)
		vars->top += 0.1 * vars->side;
	if (keycode == 86)
		vars->left -= 0.1 * vars->side;
	if (keycode == 88)
		vars->left += 0.1 * vars->side;
	if (!ft_strcmp(vars->fractolname, "Mandelbrot"))
		mandelbrotcalc(vars, 0);
	if (!ft_strcmp(vars->fractolname, "Burning_ship"))
		burningshipcalc(vars, 0);
	if (!ft_strcmp(vars->fractolname, "Julia1"))
		juliacalc(vars, 0);
	if (!ft_strcmp(vars->fractolname, "Julia2"))
		juliacalc(vars, 0);
	if (!ft_strcmp(vars->fractolname, "Julia3"))
		juliacalc(vars, 0);
	return (0);
}

int	zoom(int keycode, t_vars *vars)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 69)
		vars->side *= 0.9;
	if (keycode == 78)
		vars->side *= 1.1;
	if (!ft_strcmp(vars->fractolname, "Mandelbrot"))
		mandelbrotcalc(vars, 0);
	if (!ft_strcmp(vars->fractolname, "Burning_ship"))
		burningshipcalc(vars, 0);
	if (!ft_strcmp(vars->fractolname, "Julia1"))
		juliacalc(vars, 0);
	if (!ft_strcmp(vars->fractolname, "Julia2"))
		juliacalc(vars, 0);
	if (!ft_strcmp(vars->fractolname, "Julia3"))
		juliacalc(vars, 0);
	motion(keycode, vars);
	return (0);
}
