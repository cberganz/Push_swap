#include "../include/push_swap.h"

int	get_higher(t_stacks *s, int which_stack)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = 0;
	if (which_stack == STACK_A)
	{
		while (i <= s->a_top)
		{
			if (s->a[i] > tmp)
				tmp = s->a[i];
			i++;
		}
	}
	if (which_stack == STACK_B)
	{
		while (i <= s->b_top)
		{
			if (s->b[i] > tmp)
				tmp = s->b[i];
			i++;
		}
	}
	return (tmp);
}

int	get_lower(t_stacks *s, int which_stack)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = INT_MAX;
	if (which_stack == STACK_A)
	{
		while (i <= s->a_top)
		{
			if (s->a[i] < tmp)
				tmp = s->a[i];
			i++;
		}
	}
	if (which_stack == STACK_B)
	{
		while (i <= s->b_top)
		{
			if (s->b[i] < tmp)
				tmp = s->b[i];
			i++;
		}
	}
	return (tmp);
}

int	get_position(t_stacks *s, int nbr_to_find, int find_in)
{
	int	i;

	i = 0;
	if (find_in == STACK_A)
	{
		if (A_IS_EMPTY == s->a_top)
			return (-1);
		while (s->a[i] != nbr_to_find && i <= s->a_top)
			i++;
	}
	else if (find_in == STACK_B)
	{
		if (B_IS_EMPTY == s->b_top)
			return (-1);
		while (s->a[i] != nbr_to_find && i <= s->b_top)
			i++;
	}
	return (i);
}

int	get_immediatly_above_number(t_stacks *s, int to_match)
{
	int	above;
	int	gap;
	int	i;

	i = 0;
	gap = INT_MAX;
	while (i <= s->a_top)
	{
		if (s->a[i] > to_match && (s->a[i] - to_match) < gap)
		{
			above = s->a[i];
			gap = s->a[i] - to_match;
		}
		i++;
	}
	return (above);
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
