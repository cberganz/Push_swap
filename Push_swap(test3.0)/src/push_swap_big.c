/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_big.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 13:49:35 by cberganz          #+#    #+#             */
/*   Updated: 2022/01/09 15:26:58 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static uint8_t	chuncked_in_a(t_stacks **s, int chunck_max)
{
	int	i;

	i = 0;
	while (i <= (*s)->a_top)
	{
		if ((*s)->a[i] <= chunck_max)
			return (1);
		i++;
	}
	return (0);
}

static uint8_t	chuncked_in_b(t_stacks **s, int chunck_min)
{
	int	i;

	i = 0;
	while (i <= (*s)->b_top)
	{
		if ((*s)->b[i] > chunck_min)
			return (1);
		i++;
	}
	return (0);
}

static void	push_one_stack_to_the_other(t_stacks **s, int direction)
{
	if (direction == A_TO_B)
	{
		while (A_IS_NOT_EMPTY != (*s)->a_top)
			pb(*s);
	}
	else if (direction == B_TO_A)
	{
		while (B_IS_NOT_EMPTY != (*s)->b_top)
			pa(*s);
	}
}

void	push_swap_big(t_stacks **s)
{
	if (is_sorted(*s))
		return ;
	while (chuncked_in_a(s, (*s)->size / 2))
		push_best_a_to_b(s, (*s)->size / 2);
	bmv_rotate_b_opti(*s, PUT_HIGHER_ON_TOP);
	push_one_stack_to_the_other(s, A_TO_B);
//	push_swap_little(*s);
	while (chuncked_in_b(s, (*s)->size / 2))
		push_best_b_to_a(s, (*s)->size / 2);
	amv_rotate_a_opti(*s, PUT_LOWER_ON_TOP);
//	bmv_rotate_b_opti(*s, PUT_HIGHER_ON_TOP);
	push_one_stack_to_the_other(s, B_TO_A);
	optimize_list((*s)->lst);
}
