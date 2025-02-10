/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhtoo-h <juhtoo-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:54:24 by juhtoo-h          #+#    #+#             */
/*   Updated: 2025/02/05 15:27:17 by juhtoo-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_sorted(t_list **stack, int size)
{
	int		i;
	t_list	*temp;

	i = 0;
	temp = *stack;
	while (temp->next && i++ < size - 1)
	{
		if (temp->content > temp->next->content)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	ft_isnumber(char *numb)
{
	int	i;

	i = 0;
	if (ft_strlen(numb) == 1 && (numb[i] == '+'
			|| numb[i] == '-'))
		return (0);
	while (numb[i] == ' ')
		i++;
	if (numb[i] == '-' || numb[i] == '+')
		i++;
	while (numb[i])
	{
		if (ft_isdigit(numb[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	is_duplicate(t_list **list, int numb)
{
	t_list	*temp;

	temp = *list;
	while (temp)
	{
		if (temp->content == numb)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	ft_parsing(t_list **list, int argc, char **argv)
{
	int		i;
	int		j;
	long	num;
	char	**splits;

	i = 1;
	while (i < argc)
	{
		j = 0;
		splits = ft_split(argv[i++], ' ');
		if (!splits[0])
		{
			ft_free_splits(splits);
			return (0);
		}
		while (splits[j])
		{
			if (ft_isnumber(splits[j]) == 0)
				ft_error_message(list);
			num = ft_atoi(splits[j++]);
			if (num > 2147483647 || num < -2147483648)
				ft_error_message(list);
			if (is_duplicate(list, (int)num) == 0)
				ft_error_message(list);
			ft_lstadd_back(list, ft_lstnew((int)num));
		}
		ft_free_splits(splits);
	}
	index_init(list);
	return (1);
}
