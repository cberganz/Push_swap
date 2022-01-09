/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_treatment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 00:24:30 by cberganz          #+#    #+#             */
/*   Updated: 2021/12/11 10:45:38 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	init_stacks(int size, char **input, t_stacks *s)
{
	int	i;

	i = 0;
	s->a = (int *)malloc(sizeof(int) * s->size);
	if (s->a == NULL)
		return (-1);
	while (i < s->size)
	{
		if (not_int(input[size])
			|| is_double(s, ft_atoi(input[size]), i))
			return (-2);
		s->a[i] = ft_atoi(input[size]);
		i++;
		size--;
	}
	s->b = (int *)malloc(sizeof(int) * s->size);
	if (s->b == NULL)
	{
		free(s->a);
		return (-1);
	}
	i = -1;
	while (++i < s->size)
		s->b[i] = s->a[i];
	return (i);
}

static void	int_reducer(t_stacks *s)
{
	int	i;
	int	j;

	i = 0;
	ft_sort_int_tab(s->b, s->size);
	while (i < s->size)
	{
		j = 0;
		while (j < s->size)
		{
			if (s->a[i] == s->b[j])
			{
				s->a[i] = j + 1;
				break ;
			}
			j++;
		}
		i++;
	}
	i = 0;
	while (i < s->size)
	{
		s->b[i] = 0;
		i++;
	}
}

t_stacks	*input_treatment(int argc, char **argv)
{	
	t_stacks	*s;

	s = (t_stacks *)malloc(sizeof(*s));
	if (!s)
		return (NULL);
	s->size = argc - 1;
	s->size = init_stacks(s->size, argv, s);
	if (s->size == -1)
	{
		free(s);
		return (NULL);
	}
	if (s->size == -2)
	{
		free(s->a);
		free(s);
		write(2, "Error\n", 6);
		return (NULL);
	}
	s->a_top = s->size - 1;
	s->b_top = -1;
	int_reducer(s);
	s->lst = NULL;
	return (s);
}
