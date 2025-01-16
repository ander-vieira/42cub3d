/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:52:33 by andeviei          #+#    #+#             */
/*   Updated: 2025/01/16 20:28:19 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

static void	print_string(t_fd fd, t_str str)
{
	size_t	len;

	if (str == NULL)
		str = "(null)";
	len = 0;
	while (str[len] != '\0')
		len++;
	write(fd, str, len);
}

void	print_error(t_str str)
{
	if (str == NULL)
		str = strerror(errno);
	print_string(STDERR_FILENO, "Error\n");
	print_string(STDERR_FILENO, str);
	print_string(STDERR_FILENO, "\n");
}
