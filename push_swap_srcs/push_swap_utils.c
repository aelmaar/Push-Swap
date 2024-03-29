/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 15:04:23 by ael-maar          #+#    #+#             */
/*   Updated: 2023/01/20 18:22:39 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_enumeration	max(t_list *stack_b)
{
	int				i;
	t_enumeration	val_ind;

	val_ind.index = -1;
	if (stack_b)
	{
		i = 0;
		val_ind.value = stack_b->content;
		val_ind.index = i;
		while (stack_b)
		{
			if (val_ind.value < stack_b->content)
			{
				val_ind.value = stack_b->content;
				val_ind.index = i;
			}
			i++;
			stack_b = stack_b->next;
		}
	}
	return (val_ind);
}

t_enumeration	min(t_list *stack_b)
{
	int				i;
	t_enumeration	val_ind;

	val_ind.index = -1;
	if (stack_b)
	{
		i = 0;
		val_ind.value = stack_b->content;
		val_ind.index = i;
		while (stack_b)
		{
			if (val_ind.value > stack_b->content)
			{
				val_ind.value = stack_b->content;
				val_ind.index = i;
			}
			i++;
			stack_b = stack_b->next;
		}
	}
	return (val_ind);
}

void	three_elements(t_list **stack_a, t_list **stack_b)
{
	int	num_top;
	int	num_mid;
	int	num_bot;

	num_top = (*stack_a)->content;
	num_mid = (*stack_a)->next->content;
	num_bot = (*stack_a)->next->next->content;
	if (num_bot > num_mid && num_bot < num_top)
		run_actions_for_push_swap("ra\n", stack_a, stack_b, 1);
	else if (num_top > num_mid && num_top < num_bot)
		run_actions_for_push_swap("sa\n", stack_a, stack_b, 1);
	else if (num_mid > num_bot && num_mid < num_top)
	{
		run_actions_for_push_swap("sa\n", stack_a, stack_b, 1);
		run_actions_for_push_swap("rra\n", stack_a, stack_b, 1);
	}
	else if (num_top < num_mid && num_top > num_bot)
		run_actions_for_push_swap("rra\n", stack_a, stack_b, 1);
	else if (num_bot < num_mid && num_bot > num_top)
	{
		run_actions_for_push_swap("sa\n", stack_a, stack_b, 1);
		run_actions_for_push_swap("ra\n", stack_a, stack_b, 1);
	}
}

void	to_position(t_list **stack, int *index, int index_stack)
{
	while (*stack && *index != index_stack)
	{
		*stack = (*stack)->next;
		*index += 1;
	}
}

void	small_to_top(t_list **stack_a, t_list **stack_b)
{
	t_enumeration	min_value;
	int				stack_a_size;

	min_value = min(*stack_a);
	stack_a_size = ft_lstsize(*stack_a);
	if (min_value.index <= (stack_a_size / 2))
		run_actions_for_push_swap("ra\n", stack_a, stack_b, min_value.index);
	else
		run_actions_for_push_swap("rra\n", stack_a, stack_b, \
									stack_a_size - min_value.index);
}
