/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_viewport.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 23:30:53 by minkyeki          #+#    #+#             */
/*   Updated: 2022/09/09 20:59:47 by sungjpar         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "painter.h"

int	render_viewport(t_device *device, t_image *viewport)
{
	/** WARN: Use Static Variable for private data member! */
	(void)device;
	(void)viewport;

	put_colors_to_color_picker(viewport);
	return (0);
}