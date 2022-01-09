/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 08:34:30 by cberganz          #+#    #+#             */
/*   Updated: 2021/12/11 10:58:40 by cberganz         ###   ########.fr       */
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
	ft_lstadd_back(&s->lst, ft_lstnew("ra\n"));
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
	ft_lstadd_back(&s->lst, ft_lstnew("rb\n"));
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
	ft_lstadd_back(&s->lst, ft_lstnew("rr\n"));
}