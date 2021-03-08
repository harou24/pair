#ifndef PAIR_H
# define PAIR_H

typedef struct	s_pair {
		union
		{
			void *first;
			char *key;
		}f;
		union
		{
			void *second;
			void *value;
		}s;
}		t_pair;

t_pair	*pair_create(void *_first, void *_second);
void	pair_destroy(t_pair *_pair);

#endif
