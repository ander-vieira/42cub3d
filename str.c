/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 19:27:38 by alex              #+#    #+#             */
/*   Updated: 2025/01/16 19:21:08 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

size_t	str_len(t_str str)
{
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

t_bool	str_cmp(t_str str1, t_str str2)
{
	size_t	i;

	i = 0;
	while (str1[i] != '\0' || str2[i] != '\0')
	{
		if (str1[i] != str2[i])
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*origin;
	char	*dest;

	if (dst == NULL && src == NULL && n != 0)
		return (NULL);
	i = 0;
	origin = (char *)src;
	dest = (char *)dst;
	while (i < n)
	{
		dest[i] = origin[i];
		i++;
	}
	return (dst);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if ((unsigned char) s1[i] != (unsigned char) s2[i])
			return ((unsigned char) s1[i] - (unsigned char) s2[i]);
		i++;
	}
	return (0);
}

size_t	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	len;

	len = ft_strlen(s1);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	ft_memcpy(str, s1, len);
	str[len] = '\0';
	return (str);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	rest;

	sign = 1;
	rest = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		rest = rest * 10 + (str[i] - '0');
		i++;
	}
	return (rest * sign);
}
