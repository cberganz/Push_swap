/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_playback.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 13:32:00 by cberganz          #+#    #+#             */
/*   Updated: 2022/01/10 15:16:19 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	delete_two_actions(t_list **lst)
{
	t_list	*tmp;

	if (*lst)
	{
		tmp = (*lst)->next;
		(*lst)->next = (*lst)->next->next->next;
		ft_lstdelone(tmp->next);
		ft_lstdelone(tmp);
	}
}

static void	make_optimization(t_list **lst, char *s)
{
	t_list	*tmp;
	t_list	*new;

	if (*lst)
	{
		tmp = (*lst)->next;
		new = ft_lstnew(s);
		new->next = (*lst)->next->next->next;
		(*lst)->next = new;
		ft_lstdelone(tmp->next);
		ft_lstdelone(tmp);
	}
}

static void	check_actions_compensation(t_list **lst)
{
	if ((!ft_strcmp((*lst)->next->content, "ss\n")
			&& !ft_strcmp((*lst)->next->next->content, "ss\n"))
		|| (!ft_strcmp((*lst)->next->content, "pa\n")
			&& !ft_strcmp((*lst)->next->next->content, "pb\n"))
		|| (!ft_strcmp((*lst)->next->content, "pb\n")
			&& !ft_strcmp((*lst)->next->next->content, "pa\n"))
		|| (!ft_strcmp((*lst)->next->content, "ra\n")
			&& !ft_strcmp((*lst)->next->next->content, "rra\n"))
		|| (!ft_strcmp((*lst)->next->content, "rra\n")
			&& !ft_strcmp((*lst)->next->next->content, "ra\n"))
		|| (!ft_strcmp((*lst)->next->content, "rb\n")
			&& !ft_strcmp((*lst)->next->next->content, "rrb\n"))
		|| (!ft_strcmp((*lst)->next->content, "rrb\n")
			&& !ft_strcmp((*lst)->next->next->content, "rb\n"))
		|| (!ft_strcmp((*lst)->next->content, "rr\n")
			&& !ft_strcmp((*lst)->next->next->content, "rrr\n"))
		|| (!ft_strcmp((*lst)->next->content, "rrr\n")
			&& !ft_strcmp((*lst)->next->next->content, "rr\n"))
		|| (!ft_strcmp((*lst)->next->content, "rrb\n")
			&& !ft_strcmp((*lst)->next->next->content, "rb\n")))
		delete_two_actions(lst);
}

static void	check_actions_optimization(t_list **lst)
{
	if (!ft_strcmp((*lst)->next->content, "sa\n")
		&& !ft_strcmp((*lst)->next->next->content, "sb\n"))
		make_optimization(lst, "ss\n");
	else if (!ft_strcmp((*lst)->next->content, "sb\n")
		&& !ft_strcmp((*lst)->next->next->content, "sa\n"))
		make_optimization(lst, "ss\n");
	else if (!ft_strcmp((*lst)->next->content, "ra\n")
		&& !ft_strcmp((*lst)->next->next->content, "rb\n"))
		make_optimization(lst, "rr\n");
	else if (!ft_strcmp((*lst)->next->content, "rb\n")
		&& !ft_strcmp((*lst)->next->next->content, "ra\n"))
		make_optimization(lst, "rr\n");
	else if (!ft_strcmp((*lst)->next->content, "rra\n")
		&& !ft_strcmp((*lst)->next->next->content, "rrb\n"))
		make_optimization(lst, "rrr\n");
	else if (!ft_strcmp((*lst)->next->content, "rrb\n")
		&& !ft_strcmp((*lst)->next->next->content, "rra\n"))
		make_optimization(lst, "rrr\n");
}

void	optimize_list(t_list *lst)
{
	int		lst_size_before;
	int		lst_size_after;
	t_list	*lst_begin;

	lst_size_before = 1;
	lst_size_after = 0;
	lst_begin = lst;
	while (lst_size_before - lst_size_after)
	{
		lst_size_before = ft_lstsize(lst);
		while (lst && lst->next && lst->next->next && lst->next->next->next)
		{
			check_actions_compensation(&lst);
			lst = lst->next;
		}
		lst = lst_begin;
		while (lst && lst->next && lst->next->next && lst->next->next->next)
		{
			check_actions_optimization(&lst);
			lst = lst->next;
		}
		lst = lst_begin;
		lst_size_after = ft_lstsize(lst);
	}
}
