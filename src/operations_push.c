/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 13:31:42 by cberganz          #+#    #+#             */
/*   Updated: 2022/01/10 15:36:59 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	pa(t_stacks *s)
{
	if (s->b_top >= 0)
	{
		s->a[s->a_top + 1] = s->b[s->b_top];
		s->b[s->b_top] = 0;
		s->a_top += 1;
		s->b_top -= 1;
	}
	ft_lstadd_back(&s->lst, ft_lstnew(ft_strdup("pa\n")));
}

void	pb(t_stacks *s)
{
	if (s->a_top >= 0)
	{
		s->b[s->b_top + 1] = s->a[s->a_top];
		s->a[s->a_top] = 0;
		s->b_top += 1;
		s->a_top -= 1;
	}
	ft_lstadd_back(&s->lst, ft_lstnew(ft_strdup("pb\n")));
}
