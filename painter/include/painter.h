/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   painter.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 20:16:18 by sungjpar          #+#    #+#             */
/*   Updated: 2022/09/09 20:51:42 by sungjpar         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAINTER_H
# define PAINTER_H

#include "gl_device.h"
# include "gl_engine.h"

extern t_image	color_picker_img;
extern t_image	painter_img;

/* RENDER FUNCTIONS */
int	render_viewport(t_device *device, t_image *viewport);
int	render_panel(t_device *device, t_image *panel);
int render_layer(t_device *device);

/* COLOR PICKER FUNCTIONS  */
void	put_colors_to_color_picker(t_image *const img);

#endif