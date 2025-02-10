/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_another_one.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhtoo-h <juhtoo-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:55:49 by juhtoo-h          #+#    #+#             */
/*   Updated: 2025/02/05 13:13:02 by juhtoo-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_largest_position(t_list *stack, int size)
{
	int		i;
	t_list	*tmp;
	t_list	*compare;

	i = 0;
	tmp = stack;
	compare = stack->next;
	while (tmp && i < size - 1)
	{
		if (tmp->content < compare->content)
			tmp = compare;
		i++;
		compare = compare->next;
	}
	return (tmp->current_pos);
}

int	ft_largest_index(t_list *stack, int size)
{
	int		i;
	t_list	*tmp;
	t_list	*compare;

	i = 0;
	tmp = stack;
	compare = stack->next;
	while (tmp && i < size - 1)
	{
		if (tmp->content < compare->content)
			tmp = compare;
		i++;
		compare = compare->next;
	}
	return (tmp->index);
}
