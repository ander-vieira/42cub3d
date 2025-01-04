/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <ahiguera@student.42urduliz.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:49:57 by andeviei          #+#    #+#             */
/*   Updated: 2025/01/04 21:07:58 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_MAP_H
# define PARSE_MAP_H

# include "typedefs.h"

# define LINE_BUFFER	1024

t_str get_line(t_fd fd);

/* ************************************************************************** */
/* Module main function                                                       */
/* ************************************************************************** */

void	init_cubed(t_cubed *cubed);
t_bool	parse_map(t_str file, t_cubed *cubed);

void	*ft_memcpy(void *dst, const void *src, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *str);
int		ft_atoi(const char *str);

#endif
