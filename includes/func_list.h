/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_list.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 10:31:41 by zsmith            #+#    #+#             */
/*   Updated: 2016/11/15 18:41:30 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNC_LIST_H
# define FUNC_LIST_H


void	s_func(conv_obj obj, va_list args);
// g_func_arr[0] = {"s", &s_func};

f_list	g_func_arr[15] = {
	{"s", &s_func}
}

#endif