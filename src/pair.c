#include "pair.h"
#include <stdlib.h>

t_pair	*pair_create(void *_first, void *_second)
{
	t_pair *pair;

	pair = malloc(sizeof(t_pair));
	if (!pair || !_first || !_second)
		return (NULL);
	pair->first = _first;
	pair->second = _second;
	return (pair);
}

void pair_destroy(t_pair *_pair, void (*_ft_delete_first)(void *), void (*_ft_delete_second)(void *))
{
	_ft_delete_first(_pair->first);
	_ft_delete_second(_pair->second);
	free(_pair);
}
