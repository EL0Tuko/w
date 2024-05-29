/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions_4.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youtakhs <youtakhs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 09:12:57 by youtakhs          #+#    #+#             */
/*   Updated: 2024/05/25 00:48:28 by youtakhs         ###   ########.fr       */
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

void	check_if_sorted(t_list *checker)
{
	int	current_nbr;
	int	next_nbr;
	int	size;
	int	indecator;

	size = 0;
	indecator = 0; 
	while (checker)
	{
		current_nbr = checker->content;
		size++;
		if (checker->next)
		{
			next_nbr = checker->next->content;
			if (current_nbr < next_nbr)
				indecator++;
		}
		checker = checker->next;
	}
	if ((size + 1) == indecator || size == 1)
	{
		ft_lstclear(&checker);
		exit(0);
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
