/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions_ps.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youtakhs <youtakhs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 00:47:01 by youtakhs          #+#    #+#             */
/*   Updated: 2024/05/29 07:34:36 by youtakhs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	is_valid(int ac, char **input, int n)
{
	int	i;
	int	s;

	i = 0;
	s = 0;
	while (i++ < ac && input[i] != NULL)
	{
		s = 0;
		n = 0;
		while (input[i])
		{
			while (input[i][s++] != '\0')
			{
				if (input[i][s] == '-' || input[i][s] == '+')
				{
					if ((input[i][s + 1] >= '0') && (input[i][s + 1] <= '9'))
						s++;
					else
						error();
				}
			}
			is_valid2(input[i]);
			i++;
		}
	}
}

void	is_valid2(char *word)
{
	int	i;
	int	ictr;

	i = 0;
	ictr = 0;
	while (word[i] != '\0')
	{
		if (word[i] >= '0' && word[i] <= '9')
		{
			ictr = 1;
			if (word[i + 1] == '-' || word[i + 1] == '+')
				error();
		}
		if (word[i] == ' ' || (word[i] >= 9 && word[i] <= 12))
			ictr = 1;
		if ((word[i] == '-' || word[i] == '+') && word[i + 1] != '\0')
			ictr = 1;
		if (ictr == 0)
			error();
		ictr = 0;
		i++;
	}
}

int	list_sizecheck(t_list *list)
{
	int	size;

	if (!list)
		error();
	size = 0;
	while (list)
	{
		size++;
		list = list->next;
	}
	return (size);
}

int	get_index(t_list **lst, t_list *tmp)
{
	int	i;

	i = 0;
	while (tmp)
	{
		if ((*lst)->content > tmp->content)
			i++;
		tmp = tmp->next;
	}
	return (i);
}

void	small_top(t_list **stack)
{
	t_list	*head;
	int		i;
	t_list	*the_small;
	int		distince;

	distince = 0;
	i = INT_MAX;
	head = (*stack);
	while (head)
	{
		if (head && head->index < i)
		{
			the_small = head;
			i = head->index;
		}
		distince++;
		head = head->next;
	}
	small_top_p2(&(*stack), the_small, distince);
}
