/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 08:34:30 by cberganz          #+#    #+#             */
/*   Updated: 2022/01/10 15:16:29 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ra(t_stacks *s)
{
	int	tmp;
	int	i;

	i = s->a_top;
	while (i > 0)
	{
		tmp = s->a[i];
		s->a[i] = s->a[i - 1];
		s->a[i - 1] = tmp;
		i--;
	}
	ft_lstadd_back(&s->lst, ft_lstnew(ft_strdup("ra\n")));
}

void	rb(t_stacks *s)
{
	int	tmp;
	int	i;

	i = s->b_top;
	while (i > 0)
	{
		tmp = s->b[i];
		s->b[i] = s->b[i - 1];
		s->b[i - 1] = tmp;
		i--;
	}
	ft_lstadd_back(&s->lst, ft_lstnew(ft_strdup("rb\n")));
}

void	rr(t_stacks *s)
{
	int	tmp;
	int	i;

	i = s->a_top;
	while (i > 0)
	{
		tmp = s->a[i];
		s->a[i] = s->a[i - 1];
		s->a[i - 1] = tmp;
		i--;
	}
	i = s->b_top;
	while (i > 0)
	{
		tmp = s->b[i];
		s->b[i] = s->b[i - 1];
		s->b[i - 1] = tmp;
		i--;
	}
	ft_lstadd_back(&s->lst, ft_lstnew(ft_strdup("rr\n")));
}
