#include "../include/push_swap.h"

void	pa(t_stacks *s)
{
	if (s->b_top >= 0)
	{
		s->a[s->a_top + 1] = s->b[s->b_top];
		s->b[s->b_top] = 0;
		s->a_top += 1;
		s->b_top -= 1;
	}
	ft_lstadd_back(&s->lst, ft_lstnew("pa\n"));
}

void	pb(t_stacks *s)
{
	if (s->a_top >= 0)
	{
		s->b[s->b_top + 1] = s->a[s->a_top];
		s->a[s->a_top] = 0;
		s->b_top += 1;
		s->a_top -= 1;
	}
	ft_lstadd_back(&s->lst, ft_lstnew("pb\n"));
}
