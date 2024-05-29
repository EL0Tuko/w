/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youtakhs <youtakhs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 18:55:06 by youtakhs          #+#    #+#             */
/*   Updated: 2024/05/25 03:55:17 by youtakhs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**free_arr(char **arr, int i)
{
	while (i >= 0)
	{
		free(arr[i]);
		i--;
	}
	free(arr);
	arr = NULL;
	return (arr);
}

int	wordscount(const char *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	if (count == 0)
	{
		write(1, "invalid input\n", 14);
		exit(1);
	}
	return (count);
}

char	**words_allocator(char **arr, const char *s, char c, int w_count)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	while (s[i])
	{
		count = 0;
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
		{
			i++;
			count++;
		}
		if (j < w_count)
		{
			arr[j] = (char *)malloc((count + 1) * sizeof(char));
			if (!arr[j])
				return (free_arr(arr, --j));
			j++;
		}
	}
	return (arr);
}

char	**array_filler(char **arr, const char *s, char c, int ct)
{
	int	i;
	int	j;
	int	b;

	i = 0;
	j = 0;
	b = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
		{
			arr[j][b++] = s[i];
			i++;
		}
		if (j < ct)
		{
			arr[j][b] = '\0';
			j++;
			b = 0;
		}
	}
	arr[j] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	int		ct;
	char	**arr;

	if (!s)
		return (NULL);
	ct = wordscount(s, c);
	arr = malloc((ct + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	arr = words_allocator(arr, s, c, ct);
	if (!arr)
		return (NULL);
	arr = array_filler(arr, s, c, ct);
	if (!arr)
	{
		write(2, "error\n", 6);
		error();
	}
	return (arr);
}
