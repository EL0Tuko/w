/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions_4.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youtakhs <youtakhs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 09:12:57 by youtakhs          #+#    #+#             */
/*   Updated: 2024/05/29 16:57:48 by youtakhs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int content, int index)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->index = index;
	node->next = NULL;
	return (node);
}

void	check_if_sorted(t_list *stack)
{
	while (stack)
	{
		if (stack)
		{
			if(!stack->next)
				break ;
			else if (stack->content < stack->next->content)
				stack = stack->next;
			else
				break ;
		}
		else
		{
			ft_lstclear(&stack);
			exit(0);
		}
	}
}

void	check_list(t_list *lst)
{
	t_list	*temp2;
	t_list	*temp;
	int		count;

	check_if_sorted(lst);
	count = 0;
	temp2 = lst;
	temp = lst;
	while (temp)
	{
		temp2 = lst;
		while (temp2)
		{
			if (temp->content == temp2->content)
				count++;
			temp2 = temp2->next;
		}
		if (count > 1)
		{
			ft_lstclear(&lst);
			error();
		}
		count = 0;
		temp = temp->next;
	}
}

void	push_a(t_list **stack_a, t_list **stack_b)
{
	p(&(*stack_b), &(*stack_a));
	write(1, "pa\n", 3);
}
