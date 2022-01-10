/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 03:54:10 by cberganz          #+#    #+#             */
/*   Updated: 2022/01/10 15:25:10 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	*s;

	if (argc < 2)
		exit(EXIT_FAILURE);
	s = input_treatment(argc, argv);
	if (!s)
		exit(EXIT_FAILURE);
	if (s->size <= 5)
		push_swap_little(s);
	else
		push_swap_big(&s);
	ft_lstprint(s->lst);
	free_stacks(&s, CLEAR_LIST);
	exit(EXIT_SUCCESS);
}
