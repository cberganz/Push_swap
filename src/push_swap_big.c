/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_big.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 13:30:13 by cberganz          #+#    #+#             */
/*   Updated: 2022/01/10 15:16:36 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static uint8_t	left_chuncked_in_b(t_stacks **s, int chunck_min)
{
	int	i;

	i = 0;
	while (i <= (*s)->b_top)
	{
		if ((*s)->b[i] > chunck_min)
			return (1);
		i++;
	}
	return (0);
}

static void	push_a_to_b_with_two_chuncks(t_stacks **s)
{
	while ((*s)->a_top > (*s)->size / 2 - 1)
	{
		if ((*s)->a[(*s)->a_top] <= (*s)->size / 2)
			pb(*s);
		else
			ra(*s);
	}
	while (A_IS_NOT_EMPTY != (*s)->a_top)
	{
		if ((*s)->a[(*s)->a_top] <= (*s)->size)
			pb(*s);
		else
			ra(*s);
	}
}

static int	get_cost_to_push_sorted(t_stacks *s, int index_b)
{
	int	cost;
	int	to_get_on_top;
	int	index_a;

	if (index_b > s->b_top / 2)
		cost = s->b_top - index_b;
	else
		cost = index_b + 1;
	if (s->b[index_b] < get_lower(s, STACK_A)
		|| s->b[index_b] > get_higher(s, STACK_A))
		to_get_on_top = get_lower(s, STACK_A);
	else
		to_get_on_top = get_immediatly_above_number(s, s->b[index_b]);
	index_a = get_position(s, to_get_on_top, STACK_A);
	if (index_a > s->a_top / 2)
		cost += s->a_top - index_a;
	else
		cost += index_a + 1;
	cost += 1;
	return (cost);
}

void	push_best_b_to_a(t_stacks **s, int chunck_min)
{
	int	index;
	int	cost_current;
	int	cost_best;
	int	index_best;

	index = (*s)->b_top;
	cost_best = INT_MAX;
	while (index >= 0)
	{
		if ((*s)->b[index] > chunck_min)
		{
			cost_current = get_cost_to_push_sorted(*s, index);
			if (cost_current < cost_best)
			{
				cost_best = cost_current;
				index_best = index;
			}
		}
		index--;
	}
	rotate_b_opti(*s, index_best);
	pa_sorted(*s);
}

void	push_swap_big(t_stacks **s)
{
	if (is_sorted(*s))
		return ;
	push_a_to_b_with_two_chuncks(s);
	while (left_chuncked_in_b(s, (*s)->size / 2))
		push_best_b_to_a(s, (*s)->size / 2);
	while (left_chuncked_in_b(s, 0))
		push_best_b_to_a(s, 0);
	rotate_a_opti(*s, PUT_LOWER_ON_TOP);
	optimize_list((*s)->lst);
}
