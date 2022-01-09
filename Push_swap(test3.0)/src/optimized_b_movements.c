/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimized_b_movements.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 13:49:20 by cberganz          #+#    #+#             */
/*   Updated: 2022/01/09 15:26:55 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	bmv_rotate_a_opti(t_stacks *s, int index)
{
	int	to_match;

	to_match = s->a[index];
	while (s->a[s->a_top] != to_match)
	{
		if (index > s->a_top / 2)
			ra(s);
		else
			rra(s);
	}
}

void	bmv_rotate_b_opti(t_stacks *s, int we_need_to)
{
	int	i;
	int	to_match;

	i = 0;
	to_match = 0;
	if (we_need_to == PUT_HIGHER_ON_TOP)
		to_match = get_higher(s->b, s->b_top + 1);
	else if (we_need_to == PREPARE_FOR_PB)
		to_match = s->a[s->a_top];
	while (i <= s->b_top
			&& !(s->b[i] < to_match && s->b[i + 1] > to_match)
			&& s->b[i] != to_match)
		i++;
	while (!(s->b[s->b_top] < to_match && s->b[0] > to_match)
			&& s->b[s->b_top] != to_match)
	{
		if (i > s->b_top / 2)
			rb(s);
		else
			rrb(s);
	}
}

void	pb_sorted(t_stacks *s)
{
	if (s->b_top == -1)
		pb(s);
	else if (s->b_top == 0)
	{
		pb(s);
		if (s->b[s->b_top] < s->b[s->b_top - 1])
			sb(s);
	}
	else
	{
		if (s->a[s->a_top] < get_lower(s->b, s->b_top + 1)
				|| s->a[s->a_top] > get_higher(s->b, s->b_top + 1))
			bmv_rotate_b_opti(s, PUT_HIGHER_ON_TOP);
		else
			bmv_rotate_b_opti(s, PREPARE_FOR_PB);
		pb(s);
	}
}

void	push_best_a_to_b(t_stacks **s, int chunck_max)
{
	int	index;
	t_stacks	*best;
	t_stacks	*s_cpy;

	best = NULL;
	index = (*s)->a_top;
	while (index >= 0)
	{
		if ((*s)->a[index] <= chunck_max)
		{
			s_cpy = stacks_cpy(s);
			ft_lstclear(&s_cpy->lst);
			bmv_rotate_a_opti(s_cpy, index);
			pb_sorted(s_cpy);
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
	if ((*s)->lst)
	{
		ft_lstlast((*s)->lst)->next = best->lst;
		best->lst = (*s)->lst;
	}
	free_stacks(s, DO_NOT_CLEAR_LIST);
	*s = best;
}
