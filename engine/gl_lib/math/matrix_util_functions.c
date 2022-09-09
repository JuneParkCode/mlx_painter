/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_util_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 23:12:19 by minkyeki          #+#    #+#             */
/*   Updated: 2022/09/06 17:13:25 by sungjpar         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "gl_matrix.h"

float	gl_get_radian(float degree)
{
	return (degree / 180.0f * 3.141592f);
}