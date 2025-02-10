/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhtoo-h <juhtoo-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:06:07 by juhtoo-h          #+#    #+#             */
/*   Updated: 2025/02/10 14:26:21 by juhtoo-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	free_all(t_list **stack_a, t_list **stack_b)
{
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
	exit(EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;

	if (argc == 1)
		return (0);
	stack_a = (t_list **)malloc(sizeof(t_list));
	stack_b = (t_list **)malloc(sizeof(t_list));
	*stack_a = NULL;
	*stack_b = NULL;
	if (!ft_parsing(stack_a, stack_b, argc, argv))
		free_all(stack_a, stack_b);
	if (check_sorted(stack_a, ft_lstsize(*stack_a)))
		free_all(stack_a, stack_b);
	if (ft_lstsize(*stack_a) <= 5)
		simple_sort(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
	free_all(stack_a, stack_b);
	return (0);
}
