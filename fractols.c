/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractols.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkory <hkory@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:01:43 by hkory             #+#    #+#             */
/*   Updated: 2022/05/30 18:25:43 by hkory            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	dst = vars->data->addr + (y * vars->data->line_length + x \
		* (vars->data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

long int	color(int it, int color)
{
	int	colors[8];

	colors[0] = 0x330000;
	colors[1] = 0x4D004D;
	colors[2] = 0x1A6600;
	colors[3] = 0xCCCC00;
	colors[4] = 0xE600E6;
	colors[5] = 0x00004D;
	colors[6] = 0xFF9900;
	colors[7] = 0x4DFF4D;
	return (colors[color] * (it % 6));
}

void	mandelbrotcalc(t_vars *vars, int count)
{
	vars->scale = vars->side / W;
	vars->y = 0;
	while (++vars->y <= W - 1)
	{
		vars->x = 0;
		while (++vars->x <= W - 1)
		{
			vars->cx = (vars->x - W / 2) * vars->scale + vars->left;
			vars->cy = (vars->y - W / 2) * vars->scale + vars->top;
			vars->zx = 0;
			vars->zy = 0;
			count = 0;
			while ((vars->zx * vars->zx + vars->zy * vars->zy < 4)
				&& (count < 150))
			{
				vars->tempx = vars->zx * vars->zx - vars->zy
					* vars->zy + vars->cx;
				vars->zy = 2 * vars->zx * vars->zy + vars->cy;
				vars->zx = vars->tempx;
				count = count + 1;
			}
			my_mlx_pixel_put(vars, vars->x, vars->y, color(count, vars->color));
		}
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->data->img, 0, 0);
}

void	burningshipcalc(t_vars *vars, int count)
{
	vars->scale = vars->side / W;
	vars->y = 0;
	while (++vars->y <= W - 1)
	{
		vars->x = 0;
		while (++vars->x <= W - 1)
		{
			vars->cx = (vars->x - W / 2) * vars->scale + vars->left;
			vars->cy = (vars->y - W / 2) * vars->scale + vars->top;
			vars->zx = 0;
			vars->zy = 0;
			count = 0;
			while ((vars->zx * vars->zx + vars->zy * vars->zy < 4)
				&& (count < 150))
			{
				vars->tempx = vars->zx * vars->zx - vars->zy
					* vars->zy + vars->cx;
				vars->zy = fabsl(2 * vars->zx * vars->zy + vars->cy);
				vars->zx = fabsl(vars->tempx);
				count = count + 1;
			}
			my_mlx_pixel_put(vars, vars->x, vars->y, color(count, vars->color));
		}
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->data->img, 0, 0);
}

void	juliacalc(t_vars *vars, int count)
{
	vars->scale = vars->side / W;
	vars->y = 0;
	while (++vars->y <= W - 1)
	{
		vars->x = 0;
		while (++vars->x <= W - 1)
		{
			vars->zx = (vars->x - W / 2) * vars->scale + vars->left;
			vars->zy = (vars->y - W / 2) * vars->scale + vars->top;
			count = 0;
			while ((vars->zx * vars->zx + vars->zy * vars->zy < 4)
				&& (count < 500))
			{
				vars->tempx = vars->zx * vars->zx - vars->zy
					* vars->zy + vars->cx;
				vars->zy = 2 * vars->zx * vars->zy + vars->cy;
				vars->zx = vars->tempx;
				count = count + 1;
			}
			my_mlx_pixel_put(vars, vars->x, vars->y, color(count, vars->color));
		}
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->data->img, 0, 0);
}
