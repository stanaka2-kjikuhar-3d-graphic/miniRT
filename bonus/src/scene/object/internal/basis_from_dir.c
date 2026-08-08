/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basis_from_dir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 01:11:55 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/08/07 01:22:10 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "object.h"
#include "vector.h"

#include "../object_private.h"

/*
  w = dir, u and v are any orthonormal pair around it.

           Z_AXIS = w = dir
              |
              |____ Y_AXIS = v
             /
        X_AXIS = u
*/
t_mat3	basis_from_dir(t_vec3 dir)
{
	t_mat3	basis;
	t_vec3	u;
	t_vec3	v;

	calc_onb(dir, &u, &v);
	basis.m[0][X_AXIS] = u.x;
	basis.m[1][X_AXIS] = u.y;
	basis.m[2][X_AXIS] = u.z;
	basis.m[0][Y_AXIS] = v.x;
	basis.m[1][Y_AXIS] = v.y;
	basis.m[2][Y_AXIS] = v.z;
	basis.m[0][Z_AXIS] = dir.x;
	basis.m[1][Z_AXIS] = dir.y;
	basis.m[2][Z_AXIS] = dir.z;
	return (basis);
}
