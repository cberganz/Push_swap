#include "../include/push_swap.h"

void	rotate_a_opti(t_stacks *s, int index)
{
	int	to_match;

	to_match = s->a[index];
	while (s->a[s->a_top] != to_match)
	{
		if (index > s->a_top / 2)
			ra(s);
		else
			rra(s);
	}
}

void	rotate_b_opti(t_stacks *s, int we_need_to)
{
	int	i;
	int	to_match;

	i = 0;
	to_match = 0;
	if (we_need_to == PUT_HIGHER_ON_TOP)
		to_match = get_higher(s->b, s->b_top + 1);
	else if (we_need_to == PREPARE_FOR_PB)
		to_match = s->a[s->a_top];
	while (i <= s->b_top
	&& !(s->b[i] < to_match && s->b[i + 1] > to_match)
	&& s->b[i] != to_match)
		i++;
	while (!(s->b[s->b_top] < to_match && s->b[0] > to_match)
			&& s->b[s->b_top] != to_match)
	{
		if (i > s->b_top / 2)
			rb(s);
		else
			rrb(s);
	}
}

void	pb_sorted(t_stacks *s)
{
	if (s->b_top == -1)
		pb(s);
	else if (s->b_top == 0)
	{
		pb(s);
		if (s->b[s->b_top] < s->b[s->b_top - 1])
			sb(s);
	}
	else
	{
		if (s->a[s->a_top] < get_lower(s->b, s->b_top + 1)
				|| s->a[s->a_top] > get_higher(s->b, s->b_top + 1))
			rotate_b_opti(s, PUT_HIGHER_ON_TOP);
		else
			rotate_b_opti(s, PREPARE_FOR_PB);
		pb(s);
	}
}
