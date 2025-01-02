/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 19:27:38 by alex              #+#    #+#             */
/*   Updated: 2025/01/02 20:37:26 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

size_t	str_len(t_str str) {
	size_t	len;

	if (str == NULL)
		return (0);
	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

void	str_copy(t_str dest, t_str src, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
}
