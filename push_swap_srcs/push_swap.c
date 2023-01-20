/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 19:17:50 by ael-maar          #+#    #+#             */
/*   Updated: 2023/01/20 18:23:57 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	copy_stack(t_list *stack_a, t_list **cp)
{
	while (stack_a)
	{
		ft_lstadd_back(cp, ft_lstnew(stack_a->content));
		stack_a = stack_a->next;
	}
}

static void	sort_cp_stack(t_list *stack)
{
	t_list	*temp;
	int		temp_swap;

	while (stack)
	{
		temp = stack;
		while (temp)
		{
			if (stack->content > temp->content)
			{
				temp_swap = stack->content;
				stack->content = temp->content;
				temp->content = temp_swap;
			}
			temp = temp->next;
		}
		stack = stack->next;
	}
}

static void	from_a_to_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*cp;

	cp = NULL;
	copy_stack(*stack_a, &cp);
	sort_cp_stack(cp);
	push_to_b(stack_a, stack_b, cp);
	ft_lstclear(&cp);
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
		positions = calc_positions(*stack_a, *stack_b, max_val, min_val);
		perfect_position(positions, stack_a, stack_b);
		ft_lstclear(&positions);
	}
}

void	push_swap(t_list **stack_a, t_list **stack_b)
{
	from_a_to_b(stack_a, stack_b);
	if (ft_lstsize(*stack_a) == 3)
		three_elements(stack_a, stack_b);
	from_b_to_a(stack_a, stack_b);
	small_to_top(stack_a, stack_b);
}
