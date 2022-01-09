#include "push_swap.h"

void	ft_lstdelone(t_list *lst)
{
	if (lst)
	{
		lst->next = NULL;
		free(lst);
	}
}

void	ft_lstclear(t_list **lst)
{
	t_list	*next;

	while (*lst)
	{
		next = (*lst)->next;
		ft_lstdelone(*lst);
		*lst = next;
	}
	free(*lst);
	*lst = NULL;
}

void	free_stacks(t_stacks **s, int we_want_to)
{
	if (*s)
	{
		if ((*s)->a)
			free((*s)->a);
		if ((*s)->b)
			free((*s)->b);
		if (we_want_to == CLEAR_LIST && (*s)->lst)
			ft_lstclear(&(*s)->lst);
		free(*s);
		*s = NULL;
	}
}
