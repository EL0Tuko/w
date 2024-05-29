/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youtakhs <youtakhs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 09:04:10 by youtakhs          #+#    #+#             */
/*   Updated: 2024/05/28 23:50:42 by youtakhs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	maped_list(t_list **list)
{
	t_list	*temp;
	t_list	*temp2;
	int		i;

	i = 0;
	temp = *list;
	temp2 = *list;
	while (temp)
	{
		temp->index = get_index(&temp, *list);
		temp = temp->next;
		i++;
	}
	i = 0;
	while (temp2 && temp2->index == i)
	{
		if (!temp2->next)
		{
			ft_lstclear(&(*list));
			exit(0);
		}
		i++;
		temp2 = temp2->next;
	}
}

void	force_small_top(t_list **stack_a, t_list **stack_b)
{
	small_top(&(*stack_a));
	p(&(*stack_a), &(*stack_b));
	write(1, "pb\n", 3);
}

long	ft_atoi(char *str, int *indecator)
{
	int		i;
	long	result;
	int		sign;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			sign = -1;
		}
		i++;
	}
	while ((str[i] >= '0') && (str[i] <= '9') && (str[i] != '\0'))
		result = result * 10 + (str[i++] - '0');
	if (result > INT_MAX || (sign == -1 && (-result) < INT_MIN))
		*indecator = 1;
	result *= sign;
	return (result);
}

void	rv_rt(t_list **stack_a)
{
	rv(&(*stack_a));
	write(1, "rra\n", 4);
}
