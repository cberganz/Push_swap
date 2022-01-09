#include "../include/push_swap.h"

static uint8_t	is_not_in_five_highest(t_stacks *s, int index)
{
	if (s->a[index] > get_higher(s->a, s->a_top + 1) - 3)
		return (0);
	return (1);
}

void	push_best_a_to_b(t_stacks **s, int count)
{
	int	index;
	t_stacks	*best;
	t_stacks	*s_cpy;

	best = NULL;
	index = (*s)->a_top;
	while (index >= 0)
	{
		if (is_not_in_five_highest(*s, index))
		{
			s_cpy = stacks_cpy(s);
			ft_lstclear(&s_cpy->lst);
			rotate_a_opti(s_cpy, index);
			pb_sorted(s_cpy);
			if (count <= 0)
				push_best_a_to_b(&s_cpy, count + 1);
			optimize_list(s_cpy->lst);
			if (best == NULL)
				best = s_cpy;
			else if (ft_lstsize(s_cpy->lst) < ft_lstsize(best->lst))
			{
				free_stacks(&best, CLEAR_LIST);
				best = s_cpy;
			}
			else
				free_stacks(&s_cpy, CLEAR_LIST);
		}
		index--;
	}
	if ((*s)->lst)
	{
		ft_lstlast((*s)->lst)->next = best->lst;
		best->lst = (*s)->lst;
	}
	free_stacks(s, DO_NOT_CLEAR_LIST);
	*s = best;
}

void	push_swap_big(t_stacks **s)
{
	if (is_sorted(*s))
		return ;
	while (A_IS_NOT_EMPTY != (*s)->a_top)
		push_best_a_to_b(s, 1);
	rotate_b_opti(*s, PUT_HIGHER_ON_TOP);
	push_swap_little(*s);
	while (B_IS_NOT_EMPTY != (*s)->b_top)
		pa(*s);
	optimize_list((*s)->lst);
}
