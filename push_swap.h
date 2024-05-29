/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youtakhs <youtakhs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 00:46:42 by youtakhs          #+#    #+#             */
/*   Updated: 2024/05/29 16:55:59 by youtakhs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
	int				index;
}					t_list;

t_list				*input_check(int ac, char **input, int j, int n);
void				sort(t_list **stack_a, t_list **stack_b, int min,
						int max);
char				**ft_split(char const *s, char c);
long				ft_atoi(char *str, int *indecator);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstclear(t_list **lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstadd_front(t_list **lst, t_list *new);
t_list				*ft_lstnew(int content, int index);
void				maped_list(t_list **list);
int					get_index(t_list **lst, t_list *tmp);
void				iindex(t_list *stack);
void				is_valid(int ac, char **input, int n);
void				small_top(t_list **stack);
void				small_top_p2(t_list **stack, 
						t_list *the_small, int distince);
t_list				*big_htr(t_list *stack);
int					list_sizecheck(t_list *list);
void				check_list(t_list *lst);
void				check_if_sorted(t_list *checker);
void				sort_3(t_list **stack_a);
void				sort_3_p2(t_list **stack_a);
void				sort_5(t_list **stack_a, t_list **stack_b, int size);
void				force_small_top(t_list **stack_a, t_list **stack_b);
void				p(t_list **lst, t_list **lst2);
void				s(t_list **lst);
void				r(t_list **lst);
void				rv(t_list **lst);
void				is_valid2(char *word);
void				back_to_a(t_list **stack_a, t_list **stack_b);
char				**free_arr(char **arr, int i);
void				rotate_a(t_list **stack);
void				swap_a(t_list **stack);
void				error(void);
void				push_a(t_list **stack_a, t_list **stack_b);
void				input_check_p2(t_list **unchecked_list, char *args);
void				push_b(t_list **stack_b, t_list **stack_a);
void				rv_rt(t_list **stack_a);

#endif