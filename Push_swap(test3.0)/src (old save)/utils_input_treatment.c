/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_input_treatment.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 03:55:50 by cberganz          #+#    #+#             */
/*   Updated: 2021/12/11 10:49:03 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_sort_int_tab(int *tab, int size)
{
	int	tmp;
	int	i1;
	int	i2;

	i1 = 0;
	while (i1 < size)
	{	
		i2 = i1 + 1;
		while (i2 < size)
		{
			if (tab[i2] < tab[i1])
			{
				tmp = tab[i1];
				tab[i1] = tab[i2];
				tab[i2] = tmp;
			}
			i2++;
		}
		i1++;
	}
}

int	ft_atoi(const char *s)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	while (*s == ' ' || (*s >= '\t' && *s <= '\r'))
		s++;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		result = (result * 10) + (*s - '0');
		s++;
	}
	return (result * sign);
}

uint8_t	not_int(char *s)
{
	long long	result;
	int			sign;

	result = 0;
	sign = 1;
	while (*s == ' ' || (*s >= '\t' && *s <= '\r'))
		s++;
	if (*s == '\0')
		return (1);
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		result = (result * 10) + (*s - '0');
		s++;
	}
	if ((result * sign) < INT_MIN || (result * sign) > INT_MAX
			|| *s != '\0')
		return (1);
	else
		return (0);
}

uint8_t	is_double(t_stacks *s, int to_check, int size)
{
	int	i;

	if (size == 0)
		return (0);
	i = 0;
	while (i < size)
	{
		if (s->a[i] == to_check)
			return (1);
		i++;
	}
	return (0);
}
