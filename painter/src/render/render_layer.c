/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_layer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 20:18:44 by sungjpar          #+#    #+#             */
/*   Updated: 2022/09/10 02:58:19 by sungjpar         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "gl_color.h"
#include "gl_device.h"
#include "gl_draw.h"
#include "gl_input.h"
#include "gl_vec2.h"
#include "mlx_macos.h"
#include "painter.h"

static void draw_render_time(t_device *device, int _x, int _y, int argb)
{
	char	*str;

	mlx_string_put(device->mlx, device->win, _x, _y, argb, "Last render(ms)");
	mlx_string_put(device->mlx, device->win, _x, _y + 20, argb, ":");
	str = ft_itoa(device->render_time);
	mlx_string_put(device->mlx, device->win, _x + 12, _y + 20, argb, str);
	free(str);
}

static void draw_color_info(t_device *device, int _x, int _y, int argb)
{
	char	*r, *g, *b;
	int		color;
	t_vec2	mouse_pos;

	mouse_pos = input_get_mouse_pos(device);
	color = *gl_get_pixel_addr(&device->viewport, mouse_pos.x, mouse_pos.y);
	r = ft_itoa(gl_color_get_red(color));
	g = ft_itoa(gl_color_get_green(color));
	b = ft_itoa(gl_color_get_blue(color));
	mlx_string_put(device->mlx, device->win, _x + 6, _y + 60, argb, "R");
	mlx_string_put(device->mlx, device->win, _x + 22, _y + 60, argb, r);
	mlx_string_put(device->mlx, device->win, _x + 6, _y + 80, argb, "G");
	mlx_string_put(device->mlx, device->win, _x + 22, _y + 80, argb, g);
	mlx_string_put(device->mlx, device->win, _x + 6, _y + 100, argb, "B");
	mlx_string_put(device->mlx, device->win, _x + 22, _y + 100, argb, b);
	mlx_string_put(device->mlx, device->win, _x + 6, _y + 40, color, "COLOR");
	free(r);
	free(g);
	free(b);
}

int render_layer(t_device *device)
{
	long long	render_start_time;
	long long	render_end_time;

	/** (4) checking rendering time performance(in ms) */
	render_start_time = get_time_ms();
	if (device->viewport.width > 0)
	{
		render_viewport(device, &device->viewport);
		engine_push_image(device, &device->viewport, 0, 0);
	}
	render_end_time = get_time_ms();
	device->render_time = render_end_time - render_start_time;
	if (device->panel.width > 0)
	{
		render_panel(device, &device->panel);
		engine_push_image(device, &device->panel, device->viewport.width, 0);
		draw_render_time(device, device->viewport.width + 15, 20, GRAY);
		draw_color_info(device, device->viewport.width + 15, 20, GRAY);
	}
	return (0);
}