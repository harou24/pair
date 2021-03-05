#ifndef PAIR_H
# define PAIR_H

typedef struct	s_pair {
		void *first;
		void *second;
}		t_pair;

t_pair	*pair_create(void *_first, void *_second);
void	pair_destroy(t_pair *_pair, void (*_ft_delete_first)(void *), void (*_ft_delete_second)(void *));

#endif
