/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 13:32:40 by cberganz          #+#    #+#             */
/*   Updated: 2022/01/10 15:16:06 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_sorted(t_stacks *s)
{
	int	i;

	i = 0;
	while (i < s->size - 1)
	{
		if (s->a[i] < s->a[i + 1])
			return (0);
		i++;
	}
	i = 0;
	while (i < s->size)
	{
		if (s->b[i] != 0)
			return (0);
		i++;
	}
	return (1);
}

void	print_stacks(t_stacks *s)
{
	int	i;

	i = s->a_top;
	printf("\n");
	while (i >= 0)
	{
		printf(" %d	%d\n", s->a[i], s->b[i]);
		i--;
	}
	printf("---	---\n");
	printf(" A	B\n");
	printf("\n");
}
