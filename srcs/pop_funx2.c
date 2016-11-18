/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_funx2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 21:00:51 by zsmith            #+#    #+#             */
/*   Updated: 2016/11/17 12:15:49 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	pop_con(conv_obj *obj, char **sentinel)
{
	int		i;

	i = 0;
	while (i < 15)
	{
		if (g_func_arr[i].f_nm == **sentinel)
		{
			obj->con_typ = **sentinel;
			obj->f = g_func_arr[i].f;
			(*sentinel)++;
			break ;
		}
		i++;
	}
}

void	pop_data(conv_obj *obj, va_list args)
{
	if (obj->w_star)
		obj->data_w_star = (int)va_arg(args, void *);
	if (obj->p_star)
		obj->data_p_star = (int)va_arg(args, void *);
	obj->data = va_arg(args, void *); 
}