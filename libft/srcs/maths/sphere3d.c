/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 14:01:41 by lburnet           #+#    #+#             */
/*   Updated: 2021/03/26 13:16:07 by lburnet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	on_sphere(t_vec3 *o, float d, t_vec3 *p)
{
	float	eq;

	eq = pow((p->x - o->x), 2) + pow((p->y - o->y), 2) + pow(
			(p->z - o->z), 2) - pow(d * 0.5f, 2);
	return (eq <= 0.001f && eq >= -0.001f);
}