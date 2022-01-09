/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimized_a_movements.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 14:18:59 by cberganz          #+#    #+#             */
/*   Updated: 2022/01/09 15:26:57 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	amv_rotate_b_opti(t_stacks *s, int index)
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

void	amv_rotate_a_opti(t_stacks *s, int we_need_to)
{
	int	i;
	int	to_match;

	i = 0;
	to_match = 0; // remove ?
	if (we_need_to == PUT_LOWER_ON_TOP)
		to_match = get_lower(s->a, s->a_top + 1);
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
		if (s->b[s->b_top] < get_lower(s->a, s->a_top + 1)
				|| s->b[s->b_top] > get_higher(s->a, s->a_top + 1))
			amv_rotate_a_opti(s, PUT_LOWER_ON_TOP);
		else
			amv_rotate_a_opti(s, PREPARE_FOR_PA);
		pa(s);
	}
}

void	push_best_b_to_a(t_stacks **s, int chunck_min)
{
	int	index;
	t_stacks	*best;
	t_stacks	*s_cpy;

	best = NULL;
	index = (*s)->b_top;
	while (index >= 0)
	{
		if ((*s)->b[index] > chunck_min)
		{
			s_cpy = stacks_cpy(s);
			ft_lstclear(&s_cpy->lst);
			amv_rotate_b_opti(s_cpy, index);
			pa_sorted(s_cpy);
			optimize_list(s_cpy->lst);
			if (best == NULL)
				best = s_cpy;
			else if (ft_lstsize(s_cpy->lst) < ft_lstsize(best->lst))
			{
				free_stacks(&best, CLEAR_LIST);
				best = s_cpy;
			}
			else
				free_stacks(&s_cpy, CLEAR_LIST);
		}
		index--;
	}
	if ((*s)->lst && best)
	{
		ft_lstlast((*s)->lst)->next = best->lst;
		best->lst = (*s)->lst;
	}
	if (best)
	{
		free_stacks(s, DO_NOT_CLEAR_LIST);
		*s = best;
	}
}
