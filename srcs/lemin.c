/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rretta <rretta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 16:54:04 by erodd             #+#    #+#             */
/*   Updated: 2020/03/11 15:49:58 by rretta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/lem_in.h"

void		ft_arrclr(char **arr)
{
	char **tmp;

	if (!arr)
		return ;
	tmp = arr;
	while (*arr)
	{
		free(*arr);
		arr++;
	}
	free(tmp);
}

int		main(void)
{
	t_lemin *lem;
	t_room	room;
	char	**split;
	int		i;

	lem->rooms = &room;
	
	split = ft_file_parse(split);
	ft_putstr("split\n");
	// i = 0;
	// while (split[i] != 0)
	// {
	// 	ft_putstr(split[i]);
	// 	ft_putchar('\n');
	// 	i++;
	// }

	ft_file_checker(split);
	ft_putstr("check\n");
	//ft_putstr(split[0]);
	// lem_init(&lem);
	// ants_parse(&lem);
	ft_arrclr(split);
	//perror("TUPO GAME OVER");
	exit (0);
}

int		lem_init(t_lemin *lem)
{
	lem->ants = 0;
	lem->start = 0;
	lem->end = 0;
	lem->pipes = NULL;
	lem->rooms = NULL;

	return (EXIT_SUCCESS);
}