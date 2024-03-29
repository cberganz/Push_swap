/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 08:01:54 by cberganz          #+#    #+#             */
/*   Updated: 2022/01/10 15:16:31 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sa(t_stacks *s)
{
	int	tmp;

	if (s->a_top >= 1)
	{
		tmp = s->a[s->a_top];
		s->a[s->a_top] = s->a[s->a_top - 1];
		s->a[s->a_top - 1] = tmp;
	}		
	ft_lstadd_back(&s->lst, ft_lstnew(ft_strdup("sa\n")));
}

void	sb(t_stacks *s)
{
	int	tmp;

	if (s->b_top >= 1)
	{
		tmp = s->b[s->b_top];
		s->b[s->b_top] = s->b[s->b_top - 1];
		s->b[s->b_top - 1] = tmp;
	}
	ft_lstadd_back(&s->lst, ft_lstnew(ft_strdup("sb\n")));
}

void	ss(t_stacks *s)
{
	int	tmp;

	if (s->a_top >= 1)
	{
		tmp = s->a[s->a_top];
		s->a[s->a_top] = s->a[s->a_top - 1];
		s->a[s->a_top - 1] = tmp;
	}		
	if (s->b_top >= 1)
	{
		tmp = s->b[s->b_top];
		s->b[s->b_top] = s->b[s->b_top - 1];
		s->b[s->b_top - 1] = tmp;
	}
	ft_lstadd_back(&s->lst, ft_lstnew(ft_strdup("ss\n")));
}
