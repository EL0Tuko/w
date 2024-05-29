/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers_ps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youtakhs <youtakhs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 00:46:55 by youtakhs          #+#    #+#             */
/*   Updated: 2024/05/25 03:50:37 by youtakhs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*input_check(int ac, char **input, int j, int n)
{
	t_list	*unchecked_list;
	int		i;
	char	**args;

	unchecked_list = NULL;
	i = 1;
	is_valid(ac, input, n);
	while (j-- > 0)
	{
		args = ft_split(input[i++], ' ');
		if (!args)
			error();
		n = 0;
		while (args != NULL && args[n] != NULL)
		{
			input_check_p2(&unchecked_list, args[n]);
			n++;
		}
		free_arr(args, n);
	}
	return (unchecked_list);
}

void	input_check_p2(t_list **unchecked_list, char *args)
{
	long	nbr;
	int		indecator;

	indecator = 0;
	nbr = ft_atoi(args, &indecator);
	if (indecator > 0)
	{
		ft_lstclear(&(*unchecked_list));
		error();
	}
	ft_lstadd_back(&(*unchecked_list), ft_lstnew(nbr, 0));
}

void	sort(t_list **stack_a, t_list **stack_b, int min, int max)
{
	while ((*stack_a))
	{
		if ((*stack_a)->index >= min && (*stack_a)->index <= max)
		{
			p(&(*stack_a), &(*stack_b));
			write(1, "pb\n", 3);
			min++;
			max++;
		}
		else if ((*stack_a)->index < min)
		{
			p(&(*stack_a), &(*stack_b));
			write(1, "pb\n", 3);
			r(&(*stack_b));
			write(1, "rb\n", 3);
			min++;
			max++;
		}
		else
		{
			r(&(*stack_a));
			write(1, "ra\n", 3);
		}
	}
	back_to_a(&(*stack_a), &(*stack_b));
}

void	back_to_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*top_number;
	int		i;

	i = list_sizecheck(*stack_b);
	while ((*stack_b))
	{
		iindex(*stack_b);
		top_number = big_htr((*stack_b));
		if ((*stack_b) == top_number)
		{
			push_a(&(*stack_a), &(*stack_b));
			i--;
		}
		else if ((*stack_b) != top_number && top_number->index <= (i / 2))
		{
			r(&(*stack_b));
			write(1, "rb\n", 3);
		}
		else
		{
			rv(&(*stack_b));
			write(1, "rrb\n", 4);
		}
	}
}

t_list	*big_htr(t_list *stack)
{
	t_list	*head;
	t_list	*the_big;
	int		i;

	the_big = stack;
	head = stack;
	i = stack->content;
	while (head)
	{
		if (head->content > i)
		{
			the_big = head;
			i = head->content;
		}
		head = head->next;
	}
	return (the_big);
}
