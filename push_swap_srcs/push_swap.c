/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 19:17:50 by ael-maar          #+#    #+#             */
/*   Updated: 2023/01/16 21:43:54 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	bigger_to_top(t_list *stack_a, t_list *stack_b)
{
	t_enumeration	min_value;
	int				stack_a_size;

	min_value = min(stack_a);
	stack_a_size = ft_lstsize(stack_a);
	if (min_value.index <= (stack_a_size / 2))
	{
		while (min_value.index > 0)
		{
			run_actions("ra\n", &stack_a, &stack_b);
			min_value.index--;
		}
	}
	else
	{
		while (min_value.index < stack_a_size)
		{
			run_actions("rra\n", &stack_a, &stack_b);
			min_value.index++;
		}
	}
}

static void	from_a_to_b(t_list **stack_a, t_list **stack_b)
{
	t_list			*positions;
	t_enumeration	max_val;
	t_enumeration	min_val;

	positions = NULL;
	while (*stack_a && ft_lstsize(*stack_a) >= 3)
	{
		if (ft_lstsize(*stack_a) == 3)
		{
			three_elements(stack_a, stack_b);
			break ;
		}
		max_val = max(*stack_b);
		min_val = min(*stack_b);
		positions = calc_positions(*stack_a, *stack_b, max_val, min_val);
		perfect_position(positions, stack_a, stack_b);
		ft_lstclear(&positions);
	}
}

static void	from_b_to_a(t_list **stack_a, t_list **stack_b)
{
	t_list			*positions;
	t_enumeration	max_val;
	t_enumeration	min_val;

	positions = NULL;
	while (*stack_b)
	{
		max_val = max(*stack_a);
		min_val = min(*stack_a);
		positions = calc_positions_b(*stack_a, *stack_b, max_val, min_val);
		perfect_position_b(positions, stack_a, stack_b);
		ft_lstclear(&positions);
	}
}

static void	push_swap_run(t_list **stack_a, t_list **stack_b)
{
	t_list		*positions;

	positions = NULL;
	from_a_to_b(stack_a, stack_b);
	from_b_to_a(stack_a, stack_b);
	bigger_to_top(*stack_a, *stack_b);
}

void	push_swap(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) > 3)
	{
		run_actions("pb\n", stack_a, stack_b);
		run_actions("pb\n", stack_a, stack_b);
	}
	push_swap_run(stack_a, stack_b);
}
