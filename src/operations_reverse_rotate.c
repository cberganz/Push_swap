/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_reverse_rotate.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 10:53:51 by cberganz          #+#    #+#             */
/*   Updated: 2022/01/10 15:16:27 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rra(t_stacks *s)
{
	int	tmp;
	int	i;

	i = 0;
	while (i < s->a_top)
	{
		tmp = s->a[i];
		s->a[i] = s->a[i + 1];
		s->a[i + 1] = tmp;
		i++;
	}
	ft_lstadd_back(&s->lst, ft_lstnew(ft_strdup("rra\n")));
}

void	rrb(t_stacks *s)
{
	int	tmp;
	int	i;

	i = 0;
	while (i < s->b_top)
	{
		tmp = s->b[i];
		s->b[i] = s->b[i + 1];
		s->b[i + 1] = tmp;
		i++;
	}
	ft_lstadd_back(&s->lst, ft_lstnew(ft_strdup("rrb\n")));
}

void	rrr(t_stacks *s)
{
	int	tmp;
	int	i;

	i = 0;
	while (i < s->a_top)
	{
		tmp = s->a[i];
		s->a[i] = s->a[i + 1];
		s->a[i + 1] = tmp;
		i++;
	}
	i = 0;
	while (i < s->b_top)
	{
		tmp = s->b[i];
		s->b[i] = s->b[i + 1];
		s->b[i + 1] = tmp;
		i++;
	}
	ft_lstadd_back(&s->lst, ft_lstnew(ft_strdup("rrr\n")));
}
