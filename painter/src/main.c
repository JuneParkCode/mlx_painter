/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 13:54:43 by minkyeki          #+#    #+#             */
/*   Updated: 2022/09/09 20:58:30 by sungjpar         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "gl_engine.h"
#include "painter.h"

t_image	painter_img;
t_image	color_picker_img;

void	set_images(t_device *_device)
{
	const int	img_width = _device->viewport.width;
	const int	img_height = _device->viewport.height;
	
	painter_img = _device->viewport;
	engine_new_image(&color_picker_img, _device->mlx, img_width, img_height);
	put_colors_to_color_picker(&color_picker_img);
}

int	main(void)
{
	t_device	*device;

	device = engine_init(800, 200, 800, "42GL Engine v.1.0");
	set_images(device);
	device->viewport = color_picker_img;
	engine_start_loop(device, render_layer);
	return (0);
}

