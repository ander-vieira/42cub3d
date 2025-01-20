/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:51:02 by andeviei          #+#    #+#             */
/*   Updated: 2025/01/21 00:49:31 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

int	main(int argc, t_str *argv)
{
	t_cubed	cubed;

	if (argc != 2)
		return (print_error("Wrong number of arguments"), EXIT_FAILURE);
	if (!parse_map(argv[1], &cubed))
		return (EXIT_FAILURE);
	run_window(&cubed);
	return (EXIT_SUCCESS);
}
