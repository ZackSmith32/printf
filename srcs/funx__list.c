/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funx__list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 15:32:09 by zsmith            #+#    #+#             */
/*   Updated: 2016/12/13 19:51:34 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_conv_obj	*new_conv_obj(void)
{
	t_conv_obj	*newnew;

	newnew = (t_conv_obj *)ft_memalloc(sizeof(t_conv_obj));
	newnew->len_f = (char *)ft_memalloc(2);
	newnew->prec = -1;
	newnew->str = ft_strdup("*");
	return (newnew);
}

void		ft_lstadd_end(t_conv_obj *start, t_conv_obj *new)
{
	t_conv_obj	*holder;

	if (start == new)
		return ;
	holder = start;
	while (holder->next != NULL)
		holder = holder->next;
	holder->next = new;
}

int			ft_putobj(t_conv_obj *t)
{
	int			j;
	t_conv_obj	*k;

	j = 0;
	while (t)
	{
		if (t->extra == 1 && t->minus == 1)
		{
			ft_putchar('\0');
			j++;
		}
		ft_putstr(t->str);
		j += ft_strlen(t->str);
		if (t->extra == 1 && t->minus == 0)
		{
			ft_putchar('\0');
			j++;
		}
		k = t;
		free(t->len_f);
		free(t->str);
		t = t->next;
		free(k);
	}
	free(t);
	return (j);
}
