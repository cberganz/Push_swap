#include "../include/push_swap.h"

//static uint8_t	is_not_in_five_highest(t_stacks *s, int index)
//{
//	if (s->a[index] > get_higher(s->a, s->a_top + 1) - 3)
//		return (0);
//	return (1);
//}

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

static uint8_t	no_more_chuncked_in_b(t_stacks **s, int chunck_min)
{
	int	i;

	i = 0;
	while (i <= (*s)->b_top)
	{
		if ((*s)->b[i] > chunck_min)
			return (0);
		i++;
	}
	return (1);
}

static void	push_one_chunck_from_a_to_b(t_stacks **s, int chunck_max)
{
	int	i;

	i = 0;
	while (i < (*s)->size)
	{
		if ((*s)->a[(*s)->a_top] <= chunck_max)
			pb(*s);
		else
			ra(*s);
		i++;
	}
}

void	push_best_b_to_a(t_stacks **s, int chunck_indicator)
{
	int	index;
	t_stacks	*best;
	t_stacks	*s_cpy;

	best = NULL;
	index = (*s)->b_top;
	while (index >= 0)
	{
		if ((*s)->b[index] > chunck_indicator)
		{
			s_cpy = stacks_cpy(s);
			ft_lstclear(&s_cpy->lst);
			rotate_b_opti(s_cpy, index);
			pa_sorted(s_cpy);
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
	if ((*s)->lst && best)
	{
		ft_lstlast((*s)->lst)->next = best->lst;
		best->lst = (*s)->lst;
	}
	if (best)
	{
		free_stacks(s, DO_NOT_CLEAR_LIST);
		*s = best;
	}
}

void	push_swap_big(t_stacks **s)
{
	int	chunck_indicator;

	if (is_sorted(*s))
		return ;
	chunck_indicator = (*s)->size / 2;
	while (chuncked_in_a(s, chunck_indicator))
	{
		push_one_chunck_from_a_to_b(s, chunck_indicator);
		chunck_indicator = (*s)->size - 5;
	}
	push_swap_little(*s);
	chunck_indicator = (*s)->size / 2;
	while (B_IS_NOT_EMPTY != (*s)->b_top)
	{
		push_best_b_to_a(s, chunck_indicator);
		if (no_more_chuncked_in_b(s, chunck_indicator))
				chunck_indicator = 0;
	}
	rotate_a_opti(*s, PUT_LOWER_ON_TOP);
	optimize_list((*s)->lst);
}
