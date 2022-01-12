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

#include "../include/push_swap.h"

static void	ft_exit(t_stacks **s, t_list **lst, int exit_code)
{
	if (exit_code == EXIT_SUCCESS)
		free_stacks(s, CLEAR_LIST);
//	if (exit_code == EXIT_FAILURE)
//		write(2, "Error\n", 6);
	ft_lstclear(lst);
	exit(exit_code);
}

static int8_t	exec_operations(t_stacks **s, t_list *lst)
{
	char	*op[12] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "rrr", NULL};
	void (*func_ptr[11])(t_stacks *) = { sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr };
	int i;

	while (lst)
	{
		i = 0;
		while (op[i] != NULL && ft_strcmp(lst->content, op[i]))
			i++;
		if (op[i] != NULL)
			func_ptr[i](*s);
		else
			return (0);
		lst = lst->next;
	}
	return (1);
}

static uint8_t	init_operations_list(t_list **lst)
{
	int		ret;
	int		count;
	char	c;
	char	op[4];

	count = 0;
	while ((ret = read(STDIN_FILENO, &c, 1)) > 0)
	{
		if (c != '\n' && count < 3)
		{
			op[count] = c;
			count++;
		}
		else if (c == '\n')
		{
			op[count] = '\0';
			ft_lstadd_back(lst, ft_lstnew(ft_strdup(op)));
			count = 0;
		}
		else
			return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stacks	*s;
	t_list		*lst;

	lst = NULL;
	if (argc < 2)
		return (EXIT_SUCCESS);
	if (!init_operations_list(&lst))
		ft_exit(&s, &lst, EXIT_SUCCESS);
	s = input_treatment(argc, argv);
	if (!s)
		ft_exit(&s, &lst, EXIT_FAILURE);
	if (!exec_operations(&s, lst))
	{
		write(2, "Error\n", 6);
		ft_exit(&s, &lst, EXIT_SUCCESS);
	}
	else if (is_sorted(s))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_exit(&s, &lst, EXIT_SUCCESS);
}
