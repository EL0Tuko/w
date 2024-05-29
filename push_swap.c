/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youtakhs <youtakhs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 00:46:50 by youtakhs          #+#    #+#             */
/*   Updated: 2024/05/29 03:44:54 by youtakhs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_5(t_list **stack_a, t_list **stack_b, int size)
{
	if (size == 5)
	{
		force_small_top(&(*stack_a), &(*stack_b));
		force_small_top(&(*stack_a), &(*stack_b));
		sort_3(&(*stack_a));
		if ((*stack_b)->content < (*stack_b)->next->content)
			s(&(*stack_b));
		push_a(&(*stack_a), &(*stack_b));
		push_a(&(*stack_a), &(*stack_b));
	}
	else if (size == 4)
	{
		force_small_top(&(*stack_a), &(*stack_b));
		sort_3(&(*stack_a));
		push_a(&(*stack_a), &(*stack_b));
	}
	else
		sort_3(&(*stack_a));
}

void	sort_3(t_list **stack_a)
{
	if (list_sizecheck((*stack_a)) == 2)
	{
		if ((*stack_a)->content > (*stack_a)->next->content)
			swap_a(&(*stack_a));
	}
	else
		sort_3_p2(&(*stack_a));
}

void	sort_3_p2(t_list **stack_a)
{
	if ((*stack_a)->content > (*stack_a)->next->content 
		&& (*stack_a)->content > (*stack_a)->next->next->content)
	{
		swap_a(&(*stack_a));
		rv_rt(&(*stack_a));
	}
	else if ((*stack_a)->content > (*stack_a)->next->content 
		&& (*stack_a)->content < (*stack_a)->next->next->content)
	{
		swap_a(&(*stack_a));
	}
	else if ((*stack_a)->content < (*stack_a)->next->content 
		&& (*stack_a)->content > (*stack_a)->next->next->content)
	{
		rotate_a(&(*stack_a));
		rotate_a(&(*stack_a));
	}
	else if ((*stack_a)->content < (*stack_a)->next->content 
		&& (*stack_a)->next->content > (*stack_a)->next->next->content)
	{
		swap_a(&(*stack_a));
		rotate_a(&(*stack_a));
	}
}

int	main(int ac, char **av)
{
	t_list	*valid_list;
	t_list	*stack_b;
	int		size;

	if (!av[1])
		exit(0);
	stack_b = NULL;
	valid_list = input_check(ac, av, (ac - 1), 0);
	check_list(valid_list);
	size = list_sizecheck(valid_list);
	maped_list(&valid_list);
	if (size <= 5)
		sort_5(&valid_list, &stack_b, size);
	else if (size > 5 && size <= 100)
		sort(&valid_list, &stack_b, 0, 15);
	else if (size > 100)
		sort(&valid_list, &stack_b, 2, 34);
	ft_lstclear(&valid_list);
}
