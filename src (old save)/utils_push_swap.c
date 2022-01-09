#include "../include/push_swap.h"

int	get_higher(int *s, int size)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = 0;
	while (i < size)
	{
		if (s[i] > tmp)
			tmp = s[i];
		i++;
	}
	return (tmp);
}

int	get_lower(int *s, int size)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = INT_MAX;
	while (i < size)
	{
		if (s[i] < tmp)
			tmp = s[i];
		i++;
	}
	return (tmp);
}

int	get_position(t_stacks *s, int nb)
{
	int	i;

	i = 0;
	while (s->a[i] != nb)
		i++;
	return (i);
}

t_stacks	*stacks_cpy(t_stacks **s)
{
	t_stacks	*s_cpy;
	int	i;

	i = 0;
	s_cpy = (t_stacks *)malloc(sizeof(*s_cpy));
	if (!s_cpy)
		return (NULL);
	s_cpy->size = (*s)->size;
	s_cpy->a_top = (*s)->a_top;
	s_cpy->b_top = (*s)->b_top;
	s_cpy->lst = NULL;
	s_cpy->a = (int *)malloc(sizeof(int) * s_cpy->size);
	if (!s_cpy->a)
	{
		free_stacks(&s_cpy, CLEAR_LIST);
		return (NULL);
	}
	while (i < s_cpy->size)
	{
		s_cpy->a[i] = (*s)->a[i];
		i++;
	}
	s_cpy->b = (int *)malloc(sizeof(int) * s_cpy->size);
	if (s_cpy->b == NULL)
	{
		free_stacks(&s_cpy, CLEAR_LIST);
		return (NULL);
	}
	i = 0;
	while (i < s_cpy->size)
	{
		s_cpy->b[i] = (*s)->b[i];
		i++;
	}
	return (s_cpy);
}
