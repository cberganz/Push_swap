/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_little.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 07:35:58 by cberganz          #+#    #+#             */
/*   Updated: 2021/12/11 08:01:29 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	size_2(t_stacks *s)
{
	if (s->a[1] > s->a[0])
		sa(s);
}

static void	size_3(t_stacks *s)
{
	if (s->a[1] > s->a[0] && s->a[0] > s->a[2])
	{
		sa(s);
		ra(s);
	}
	else if (s->a[0] > s->a[2] && s->a[2] > s->a[1])
		sa(s);
	else if (s->a[2] > s->a[0] && s->a[0] > s->a[1])
		ra(s);
	else if (s->a[1] > s->a[2] && s->a[2] > s->a[0])
		rra(s);
	else if (s->a[2] > s->a[1] && s->a[1] > s->a[0])
	{
		sa(s);
		rra(s);
	}
}

static void	size_4(t_stacks *s)
{
	if (is_sorted(s))
		return ;
	pb(s);
	size_3(s);
	while (s->a[s->a_top] != s->b[s->b_top] + 1)
		ra(s);
	pa(s);
	while (!is_sorted(s))
		ra(s);
}

static void	size_5(t_stacks *s)
{
	if (is_sorted(s))
		return ;
	while (s->a_top != 2)
	{
		while (s->a[s->a_top] > get_lower(s, STACK_A))
			ra(s);
		pb(s);
	}
	if (s->b[s->b_top] < s->b[s->b_top - 1])
		sb(s);
	size_3(s);
	pa(s);
	pa(s);
}

void	push_swap_little(t_stacks *s)
{
	if (s->a_top == 1)
		size_2(s);
	else if (s->a_top == 2)
		size_3(s);
	else if (s->a_top == 3)
		size_4(s);
	else if (s->a_top == 4)
		size_5(s);
}
