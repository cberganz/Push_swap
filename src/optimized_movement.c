/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimized_movement.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 13:30:38 by cberganz          #+#    #+#             */
/*   Updated: 2022/01/10 15:16:34 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rotate_b_opti(t_stacks *s, int index)
{
	int	to_match;

	to_match = s->b[index];
	while (s->b[s->b_top] != to_match)
	{
		if (index > s->b_top / 2)
			rb(s);
		else
			rrb(s);
	}
}

void	rotate_a_opti(t_stacks *s, int we_need_to)
{
	int	i;
	int	to_match;

	i = 0;
	if (we_need_to == PUT_LOWER_ON_TOP)
		to_match = get_lower(s, STACK_A);
	else if (we_need_to == PREPARE_FOR_PA)
		to_match = s->b[s->b_top];
	while (i <= s->a_top
		&& !(s->a[i] > to_match && s->a[i + 1] < to_match)
		&& s->a[i] != to_match)
		i++;
	while (!(s->a[s->a_top] > to_match && s->a[0] < to_match)
		&& s->a[s->a_top] != to_match)
	{
		if (i > s->a_top / 2)
			ra(s);
		else
			rra(s);
	}
}

void	pa_sorted(t_stacks *s)
{
	if (s->a_top == -1)
		pa(s);
	else if (s->a_top == 0)
	{
		pa(s);
		if (s->a[s->a_top] > s->a[s->a_top - 1])
			sa(s);
	}
	else
	{
		if (s->b[s->b_top] < get_lower(s, STACK_A)
			|| s->b[s->b_top] > get_higher(s, STACK_A))
			rotate_a_opti(s, PUT_LOWER_ON_TOP);
		else
			rotate_a_opti(s, PREPARE_FOR_PA);
		pa(s);
	}
}
