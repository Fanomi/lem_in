#ifndef LEM_IN_H
# define LEM_IN_H

#include <stdint.h>
# include <unistd.h>
#include <stdlib.h> //DELETE THIS
#include <stdio.h> //DELETE THIS
#include "../libft/libft.h"

typedef struct s_pipe {
	char	*start;
	char	*end;
} t_pipe;

typedef struct s_room {
	unsigned short	busy;
	int				level;
	int				x;
	int				y;
	char 			*name;
	struct t_room			*prev;
	struct t_room			*next;
} t_room;

typedef struct s_lemin {
	int			ants;
	uint16_t	start;
	uint16_t	end;
	t_pipe		*pipes; //pipes between rooms
	t_room		*rooms; //arrays of rooms
} t_lemin;

//init functions
int		lem_init(t_lemin *lem);

//parse  functions
int		ants_parse(t_lemin *lem);
int		rooms_parse(t_lemin *lem);
char	**ft_file_parse(char **split);
int		ft_file_checker(char **split);
int		ft_val_ant(char *split);
int		ft_val_bond(char **split);
int		ft_val_room(char **split);
int		ft_val_links(char **split, int i);



void	ft_arrclr(char **arr);

#endif