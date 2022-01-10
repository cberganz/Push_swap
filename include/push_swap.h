/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 03:49:06 by cberganz          #+#    #+#             */
/*   Updated: 2022/01/09 15:36:28 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdint.h>
# include <stdio.h> // TO DELETE

/*
** Defines
*/

# define CLEAR_LIST 1
# define DO_NOT_CLEAR_LIST 0
# define A_IS_NOT_EMPTY -1
# define B_IS_NOT_EMPTY -1
# define A_IS_EMPTY -1
# define B_IS_EMPTY -1
# define PUT_LOWER_ON_TOP 2
# define PREPARE_FOR_PA 1
# define STACK_A 1
# define STACK_B 2

/*
 * Structures definitions
*/

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_stacks
{
	int	*a;
	int	a_top;
	int	*b;
	int	b_top;
	int	size;
	t_list	*lst;
}	t_stacks;

/*
** Fonctions : operations on stacks
*/

void	sa(t_stacks *s);
void	sb(t_stacks *s);
void	ss(t_stacks *s);
void	pa(t_stacks *s);
void	pb(t_stacks *s);
void	ra(t_stacks *s);
void	rb(t_stacks *s);
void	rr(t_stacks *s);
void	rra(t_stacks *s);
void	rrb(t_stacks *s);
void	rrr(t_stacks *s);

/*
** Fonctions from libft
*/

int		ft_atoi(const char *s);
int		ft_strcmp(const char *s1, const char *s2);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstdelone(t_list *lst);
void	ft_lstclear(t_list **lst);
void	ft_lstprint(t_list *lst);
int	ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);

/*
** Main fonctions
*/

int			main(int ac, char **av);
t_stacks	*input_treatment(int argc, char **argv);
void		push_swap_little(t_stacks *s);
void		push_swap_big(t_stacks **s);

/*
** Secondary fonctions
*/

void	push_best_b_to_a(t_stacks **s, int chunck_indicator);
void	rotate_a_opti(t_stacks *s, int index);
void	rotate_b_opti(t_stacks *s, int we_need_to);
void	pa_sorted(t_stacks *s);
void	optimize_list(t_list *lst);

/*
** Tools and memory
*/

uint8_t		not_int(char *s);
uint8_t		is_double(t_stacks *s, int to_check, int size);
void	ft_sort_int_tab(int *tab, int size);
int		get_higher(t_stacks *s, int which_stack);
int		get_lower(t_stacks *s, int which_stack);
int		get_position(t_stacks *s, int nbr_to_find, int find_in);
int		get_immediatly_above_number(t_stacks *s, int to_match);
void	free_stacks(t_stacks **s, int cleanlistornot);
t_stacks	*stacks_cpy(t_stacks **s);

/*
** Debug fonctions
*/

void	print_stacks(t_stacks *s);
int		is_sorted(t_stacks *s);

#endif
