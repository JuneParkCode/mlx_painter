/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_colors_to_color_picker.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 20:41:46 by sungjpar          #+#    #+#             */
/*   Updated: 2022/09/10 02:39:15 by sungjpar         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "gl_color.h"
#include "painter.h"
#include <stdio.h>

static int	control_bright_color(int r, int g, int b, int bright)
{
	int	r_res;
	int	g_res;
	int	b_res;

	if (bright < 0)
	{
		r_res = r + (r) * bright / 255;
		g_res = g + (g) * bright / 255;
		b_res = b + (b) * bright / 255;
	}
	else
	{
		r_res = r + (255 - r) * bright / 255;
		g_res = g + (255 - g) * bright / 255;
		b_res = b + (255 - b) * bright / 255;
	}
	return (gl_color(BLACK, r_res, g_res, b_res));
}

static void	get_rgb(int *r, int *g, int *b)
{
	if (*r > 0 && *b <= 0)
	{
		--*r;
		++*g;
		*b = 0;
	}
	else if (*g > 0 && *r <= 0)
	{
		*r = 0;
		--*g;
		++*b;
	}
	else if (*b > 0 && *g <= 0)
	{
		++*r;
		*g = 0;
		--*b;
	}
	else
	{
		*r = 255;
		*g = 0;
		*b = 0;
	}
}

void	put_colors_to_color_picker(t_image *const img)
{
	int	color, bright;
	int	x, y;
	int	r, g, b;

	r = 255, g = 0, b = 0;
	x = 0;
	while (x < img->width)
	{
		y = 0;
		while (y < img->height)
		{
			if (y == 0)
				get_rgb(&r, &g, &b);
			if (y < img->height / 2)
				bright = round(255.0 / (img->height / 2.0f) * (img->height / 2.0f - y));
			else if (y > img->height / 2)
				bright = round(-255.0 / (img->height / 2.0f) * (y - img->height / 2.0f));
			else
				bright = 0;
			color = control_bright_color(r, g, b, bright);
			gl_draw_pixel(img, x, y, color);	
			++y;
		}
		++x;
	}
}