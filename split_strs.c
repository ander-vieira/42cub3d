/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_strs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 20:09:04 by alex              #+#    #+#             */
/*   Updated: 2025/01/21 00:46:00 by andeviei         ###   ########.fr       */
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

void	strl_free(t_strl *strl)
{
	size_t	i;

	i = 0;
	while (i < strl->n)
	{
		free(strl->strs[i]);
		i++;
	}
	free(strl->strs);
	strl->n = 0;
	strl->strs = NULL;
}

t_bool	strl_split(t_strl *strl, t_str str)
{
	size_t	i;
	size_t	j;

	strl->n = count_split(str);
	strl->strs = (t_str *)malloc(sizeof(t_str) * strl->n);
	if (strl->strs == NULL)
		return (print_error(NULL), strl->n = 0, FALSE);
	i = 0;
	j = 0;
	while (i < strl->n)
	{
		strl->strs[i] = next_split(str, &j);
		if (strl->strs[i] == NULL)
			return (print_error(NULL), strl->n = i, strl_free(strl), FALSE);
		i++;
	}
	return (TRUE);
}
