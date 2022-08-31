/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proccesing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkory <hkory@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:01:47 by hkory             #+#    #+#             */
/*   Updated: 2022/05/30 19:22:11 by hkory            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	input_error(void)
{
	ft_putstr("Avaliable names:\n\t 1) Mandelbrot\n\t");
	ft_putstr(" 2) Julia1\n\t 3) Julia2\n\t 4) Julia3 \n\t 5)Burning_ship \n");
	exit(0);
}

void	julia_init1(t_vars *vars)
{
	vars->left = 0;
	vars->top = 0;
	vars->cx = 0;
	vars->cy = -0.8;
}

void	julia_init2(t_vars *vars)
{
	vars->left = 0;
	vars->top = 0;
	vars->cx = -0.8;
	vars->cy = 0.156;
}

void	julia_init3(t_vars *vars)
{
	vars->left = 0;
	vars->top = 0;
	vars->cx = -0.999;
	vars->cy = 0.999;
}
