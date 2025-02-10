/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhtoo-h <juhtoo-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:38:39 by juhtoo-h          #+#    #+#             */
/*   Updated: 2025/02/10 12:09:51 by juhtoo-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	get_max_bit(t_list **stack)
{
	int	max;
	int	max_bits;

	max = ft_largest_index(*stack, ft_lstsize(*stack));
	max_bits = 0;
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_list **stack_a, t_list **stack_b)
{
	int	i;
	int	j;
	int	size;
	int	max_bits;

	i = 0;
	size = ft_lstsize(*stack_a);
	max_bits = get_max_bit(stack_a);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			if ((((*stack_a)->index >> i) & 1) == 1)
				rotate_a(stack_a);
			else
				push_b(stack_a, stack_b);
		}
		while ((*stack_b))
			push_a(stack_a, stack_b);
		i++;
	}
}
