/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_push_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 13:26:54 by cberganz          #+#    #+#             */
/*   Updated: 2022/01/10 15:33:17 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
