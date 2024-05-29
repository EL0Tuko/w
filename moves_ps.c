/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_ps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youtakhs <youtakhs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 00:47:06 by youtakhs          #+#    #+#             */
/*   Updated: 2024/05/25 03:49:33 by youtakhs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	p(t_list **lst, t_list **lst2)
{
	t_list	*temp;

	if ((*lst) == NULL)
		exit(1);
	if (!(*lst2))
	{
		(*lst2) = ft_lstnew((*lst)->content, (*lst)->index);
		temp = (*lst);
		(*lst) = (*lst)->next;
	}
	else
	{
		ft_lstadd_front(&(*lst2), ft_lstnew((*lst)->content, (*lst)->index));
		temp = (*lst);
		(*lst) = (*lst)->next;
	}
	free(temp);
}

void	s(t_list **lst)
{
	t_list	*first;
	t_list	*second;
	t_list	*temp;

	if (*lst == NULL || (*lst)->next == NULL )
		return ;
	first = *lst;
	second = (*lst)->next;
	temp = second->next;
	second->next = first;
	first->next = temp;
	*lst = second;
}

void	r(t_list **lst)
{
	t_list	*first;
	t_list	*temp;

	if (*lst == NULL || (*lst)->next == NULL )
		return ;
	first = *lst;
	temp = *lst;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = first;
	*lst = (*lst)->next;
	first->next = NULL;
}

void	rv(t_list **lst)
{
	t_list	*last;
	t_list	*second_last;

	if (*lst == NULL || (*lst)->next == NULL)
		exit(1);
	last = *lst;
	second_last = *lst;
	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}
	last->next = *lst;
	second_last->next = NULL;
	*lst = last;
}

void	small_top_p2(t_list **stack, t_list *the_small, int distince)
{
	while ((*stack) != the_small)
	{
		if (distince < (list_sizecheck((*stack)) / 2))
		{
			r(&(*stack));
			write(1, "ra\n", 3);
		}
		else
		{
			rv(&(*stack));
			write(1, "rra\n", 4);
		}
	}
}
