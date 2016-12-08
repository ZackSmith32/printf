/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funx__flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 12:59:38 by zsmith            #+#    #+#             */
/*   Updated: 2016/12/08 13:21:30 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"


void	plus_func(conv_obj *obj)
{
	char	*new_str;
	char	a;
	int		i;

	if (obj->plus == 0)
		return ;
	i = 0;
	if (ft_strchr(obj->str, '-'))
		return ;
	else
		a = '+';
	new_str = ft_memalloc(ft_strlen(obj->str) + 2);
	new_str[0] = a;
	ft_strcat(new_str, obj->str);
	free(obj->str);
	obj->str = new_str;
}

void	space_flag(conv_obj *obj)
{
	char	*new_str;

	if (obj->space == 0)
		return ;
	if (ft_strchr(obj->str, '-'))
		return ;
	new_str = ft_memalloc(ft_strlen(obj->str) + 2);
	new_str[0] = ' ';
	ft_strcat(new_str, obj->str);
	free(obj->str);
	obj->str = new_str;
}

void	star_args(conv_obj *obj, va_list args)
{
	if (obj->p_star)
		obj->prec = va_arg(args, int);
	if (obj->w_star)
		obj->width = va_arg(args, int);
}

int			ft_strc(char *str, char c)
{
	int		i;
	if (str == 0)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}