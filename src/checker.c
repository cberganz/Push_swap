/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:15:32 by cberganz          #+#    #+#             */
/*   Updated: 2022/01/10 15:59:10 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_checker.h"

static int	exec_operations(t_stacks *s)
{
	t_list	*lst;

	lst = s->lst;
	while (lst)
	{
		if (ft_strcmp(lst->content, "sa\n") == 0)
			sa(s);
		else if (ft_strcmp(lst->content, "sb\n") == 0)
			sb(s);
		else if (ft_strcmp(lst->content, "ss\n") == 0)
			ss(s);
		else if (ft_strcmp(lst->content, "pa\n") == 0)
			pa(s);
		else if (ft_strcmp(lst->content, "pb\n") == 0)
			pb(s);
		else if (ft_strcmp(lst->content, "ra\n") == 0)
			ra(s);
		else if (ft_strcmp(lst->content, "rb\n") == 0)
			rb(s);
		else if (ft_strcmp(lst->content, "rr\n") == 0)
			rr(s);
		else if (ft_strcmp(lst->content, "rra\n") == 0)
			rra(s);
		else if (ft_strcmp(lst->content, "rrb\n") == 0)
			rrb(s);
		else if (ft_strcmp(lst->content, "rrr\n") == 0)
			rrr(s);
		else
			return (ERROR);
		lst = lst->next;
	}
	return (SUCCESS);
}

void	main(int argc, char **argv)
{
	t_stacks	*s;

	if (argc < 2)
		write(2, "Error\n", 6);
	else
	{
		s = input_treatment(argc, argv);
		if (!s)
			exit(EXIT_FAILURE);
		read_operations(s);
		if (!exec_operations(s))
			write(1, "Error\n", 6);
		else if (is_sorted(s))
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
		free_stacks(&s, CLEAR_LIST);
	}
	exit(EXIT_SUCCESS);
}
