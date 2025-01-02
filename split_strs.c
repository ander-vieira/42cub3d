/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_strs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 20:09:04 by alex              #+#    #+#             */
/*   Updated: 2025/01/02 20:37:20 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

static t_bool	is_space(char c)
{
	return (c == ' ' || c == '\n' || c == '\t'
		|| c == '\r' || c == '\f' || c == '\v');
}

static size_t	count_split(t_str str)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (str[i] != '\0' && is_space(str[i]))
		i++;
	while (str[i] != '\0')
	{
		count++;
		while (str[i] != '\0' && !is_space(str[i]))
			i++;
		while (str[i] != '\0' && is_space(str[i]))
			i++;
	}
	return (count);
}

static t_str	next_split(t_str str, size_t *j)
{
	t_str	next;
	size_t	len;

	while (is_space(str[*j]))
		*j += 1;
	len = 0;
	while (str[*j + len] != '\0' && !is_space(str[*j + len]))
		len++;
	next = (t_str)malloc(len + 1);
	str_copy(next, str + *j, len);
	next[len] = '\0';
	*j += len;
	return (next);
}

t_strl	split_strs(t_str str)
{
	t_strl	strl;
	size_t	i;
	size_t	j;

	strl.n = count_split(str);
	strl.strs = (t_str *)malloc(sizeof(t_str) * strl.n);
	i = 0;
	j = 0;
	while (i < strl.n)
	{
		strl.strs[i] = next_split(str, &j);
		i++;
	}
	return (strl);
}
