/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 19:23:47 by alex              #+#    #+#             */
/*   Updated: 2025/01/18 15:13:15 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

static size_t	str_len_line(t_str str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0' && str[len] != '\n')
		len++;
	if (str[len] == '\n')
		len++;
	return (len);
}

static t_str	add_line(t_str line_old, t_str buf)
{
	char	*line_new;
	size_t	line_len;
	size_t	buf_len;

	line_len = str_len(line_old);
	buf_len = str_len_line(buf);
	line_new = (t_str)malloc(line_len + buf_len + 1);
	if (line_new != NULL)
	{
		str_copy(line_new, line_old, line_len);
		str_copy(line_new + line_len, buf, buf_len);
		line_new[line_len + buf_len] = '\0';
	}
	free(line_old);
	return (line_new);
}

static void	prep_buffer(t_str buf)
{
	size_t	buf_len;
	size_t	rest_len;

	buf_len = str_len_line(buf);
	rest_len = str_len(buf + buf_len);
	str_copy(buf, buf + buf_len, rest_len);
	buf[rest_len] = '\0';
}

static t_bool	has_newline(t_str line)
{
	size_t	i;

	if (line == NULL)
		return (FALSE);
	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '\n')
			return (TRUE);
		i++;
	}
	return (FALSE);
}

t_str	get_line(t_fd fd)
{
	static char	buf[LINE_BUFFER];
	char		*line;
	ssize_t		read_bytes;

	line = add_line(NULL, buf);
	while (!has_newline(line))
	{
		read_bytes = read(fd, buf, LINE_BUFFER);
		if (read_bytes == 0 && str_len(line) != 0)
			break ;
		else if (read_bytes == 0)
			return (free(line), NULL);
		else if (read_bytes == -1)
			return (print_error(NULL), free(line), buf[0] = '\0', NULL);
		buf[read_bytes] = '\0';
		line = add_line(line, buf);
	}
	prep_buffer(buf);
	return (line);
}
