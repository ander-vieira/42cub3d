/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:52:33 by andeviei          #+#    #+#             */
/*   Updated: 2024/10/01 12:57:40 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

static void print_string(t_fd fd, char *str)
{
	size_t	len;

	if (str == NULL)
		str = "(null)";
	len = 0;
	while (str[len] != '\0')
		len++;
	write(fd, str, len);
}

//TODO use strerror when str = NULL
void	print_error(char *str)
{
	if (str == NULL)
		str = strerror(errno);
	print_string(STDERR_FILENO, "Error\n");
	print_string(STDERR_FILENO, str);
	print_string(STDERR_FILENO, "\n");
}