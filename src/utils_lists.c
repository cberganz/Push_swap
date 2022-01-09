#include "push_swap.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*nlst;

	nlst = (t_list *)malloc(sizeof(*nlst));
	if (!nlst)
		return (NULL);
	nlst->content = content;
	nlst->next = NULL;
	return (nlst);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	if (alst)
	{
		if (*alst == NULL)
			*alst = new;
		else
			ft_lstlast(*alst)->next = new;
	}
}

int	ft_lstsize(t_list *lst)
{
	int	size;

	if (!lst)
		return (-1);
	size = 0;
	while (lst->next != NULL)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}

void	ft_lstprint(t_list *lst)
{
	char	*s;
	int		i;

	while (lst != NULL)
	{
		i = 0;
		s = (char *)lst->content;
		while (s[i] != '\0')
		{
			write(1, &s[i], 1);
			i++;
		}
		lst = lst->next;
	}
}
