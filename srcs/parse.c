/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rretta <rretta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 17:35:22 by erodd             #+#    #+#             */
/*   Updated: 2020/03/11 18:17:18 by rretta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

char	**ft_file_parse(char **split)
{
	char	tmp[4097];
	char	*str;
	char	*str2;
	int i;

	str = "";
	str2 = "";
	ft_memset(tmp, '\0', 4096);
	while ((read(STDIN_FILENO, tmp, 4096)) > 0)
	{
		tmp[4096] = '\0';
		str2 = ft_strjoin(str, tmp);
		if (*str != '\0')
			free(str);
		str = str2;
		ft_memset(tmp, '\0', 4096);
	}
	if (ft_intstrstr(str2, "\n\n") == 1)
	{
		perror("ERROR: EMPTY LINE");
		exit (EXIT_FAILURE);
	}
	split = ft_strsplit(str2, '\n');
	ft_strdel(&str2);
	return (split);
}

int		ft_file_checker(char **split)
{
	ft_val_ant(split[0]);
	ft_putstr("start\n");
	ft_val_bond(split);
	ft_putstr("bond\n");
	ft_val_room(split);
	ft_putstr("val_room\n");
	return(0);
}

int		ft_val_ant(char *split)
{
	int	ant_num;
	int	i;

	i = 0;
	while (ft_isdigit(split[i]))
		i++;
	if (split[i])
	{
		perror("ERROR: INCORRECT INPUT OF ANTS\n");
		exit (1);
	}
	ant_num = ft_atoi(split);
	if (ant_num < 1 || ant_num > INT32_MAX)
	{
		perror("ERROR: INCORRECT QUANTITY OF ANTS\n");
		exit (1);
	}
	ft_putnbr(ant_num);
	ft_putchar('\n');
	return (1);
}

int		ft_val_bond(char **split)
{
	int		start;
	int		end;

	start = 0;
	end = 0;

	while (*split != 0)
	{
		if (ft_strstr(*split, "##start\0") != 0)
			start++;
		if (ft_strstr(*split, "##end\0") != 0)
			end++;
		split++;
	}
	if (start == 1 && end == 1)
		return (EXIT_SUCCESS);
	else
	{
		perror("ERROR: THERE SHOULD BE ONLY ONE ENTERANCE AND EXIT");
		exit (EXIT_FAILURE);
	}
	
}

int		ft_val_room(char **split)
{
	char	**str;
	int		i;
	int		room_num;

	i = 1;
	room_num = 0;
	int j = 0;

	ft_putstr("init\n");
	while ((ft_word_counter(split[i], ' ') != 1 && ft_word_counter(split[i], '-') != 2) || split[i][0] == '#') 
	{
		if ((ft_word_counter(split[i], ' ') == 3 || split[i][0] == '#') && split[i][0] != '\n')
		{
			if (split[i][0] == 'L')
			{
				perror("ERROR: SHITTY ROOM NAME");
				exit (EXIT_FAILURE);
			}
			else if (split[i][0] == '#')
				i++;
			else
			{
				i++;
				room_num++;
			}
		}
		else 
		{
			perror("ERROR: SHITTY ROOM INPUT");
			exit (EXIT_FAILURE);
		}
		// ft_arrclr(str);
		// i++;
	}
	ft_putnbr(room_num);
	ft_putchar('\n');
	ft_val_links(split, i); //TO MOVE TO FT_FILE_CHECKER FUNC (MAYBE)
	return (room_num);
}

int		ft_val_links(char **split, int i)
{
	int	links_num;

	links_num = 0;
	while (split[i])
	{
		if (ft_word_counter(split[i], ' ') == 1 && ft_word_counter(split[i], '-') == 2 )
		{
			links_num++;
			i++;
		}
		else if (split[i][0] == '#')
			i++;
		else
		{
			perror("ERROR: SHITTY LINK INPUT");
			exit (EXIT_FAILURE);
		}
	}
	ft_putnbr(links_num);
	ft_putchar('\n');
	return (0);
}

// int		ants_parse(t_lemin *lem)
// {
// 	char *line;
// 	get_next_line(0, &line);
// 	tmp = line;
// 	while (ft_isdigit(*tmp))
// 		tmp++;
// 	if (*tmp)
// 	{
// 		ft_putstr("ERROR: NEED MORE ANTS TO PROCEED\n");
// 		exit (1);
// 	}
// 	lem->ants = ft_atoi(line);
// 	free(line);
// 	// rooms_parse(lem);
// 	ft_putnbr(lem->ants);
// 	return (1);
// }

// int		rooms_parse(t_lemin *lem)
// {
// 	char	*line;
// 	char	**tmp;
	
// 	while (get_next_line(0, &line))
// 	{
// 		tmp = ft_strsplit(line, ' ');
// 		if (tmp[1] != NULL || tmp[0][0] == '#' && tmp[0][1] == '#')
// 		{
// 			lem->rooms->name = tmp[0];
// 		}
// 		while ((tmp[2] = ft_strsplit(line, 32)) != 0)
// 		{
// 			ft_putstr(line);
// 			ft_putchar('\n');
// 		}
// 	}

// 	return (1);
// }