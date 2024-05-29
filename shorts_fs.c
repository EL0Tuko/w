/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shorts_fs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youtakhs <youtakhs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 18:49:36 by youtakhs          #+#    #+#             */
/*   Updated: 2024/05/29 07:24:34 by youtakhs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_list **stack)
{
	s(&(*stack));
	write(1, "sa\n", 3);
}

void	rotate_a(t_list **stack)
{
	r(&(*stack));
	write(1, "ra\n", 3);
}

void	push_b(t_list **stack_a, t_list **stack_b)
{
	p(&(*stack_a), &(*stack_b));
	write(1, "pb\n", 3);
}

void	error(void)
{
	write(2, "Error\n", 7);
	exit(1);
}

void	iindex(t_list *stack)
{
	int	i;

	i = 1;
	while (stack)
	{
		stack->index = i;
		i++;
		stack = stack->next;
	}
}
