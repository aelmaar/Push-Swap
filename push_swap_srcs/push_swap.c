/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 19:17:50 by ael-maar          #+#    #+#             */
/*   Updated: 2023/01/19 15:23:26 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	small_to_top(t_list **stack_a, t_list **stack_b)
{
	t_enumeration	min_value;
	int				stack_a_size;

	min_value = min(*stack_a);
	stack_a_size = ft_lstsize(*stack_a);
	if (min_value.index <= (stack_a_size / 2))
	{
		while (min_value.index > 0)
		{
			run_actions_for_push_swap("ra\n", stack_a, stack_b);
			min_value.index--;
		}
	}
	else
	{
		while (min_value.index < stack_a_size)
		{
			run_actions_for_push_swap("rra\n", stack_a, stack_b);
			min_value.index++;
		}
	}
}

// static void	from_a_to_b(t_list **stack_a, t_list **stack_b)
// {
// 	t_list			*positions;
// 	t_enumeration	max_val;
// 	t_enumeration	min_val;

// 	positions = NULL;
// 	while (*stack_a && ft_lstsize(*stack_a) >= 3)
// 	{
// 		if (ft_lstsize(*stack_a) == 3)
// 		{
// 			three_elements(stack_a, stack_b);
// 			break ;
// 		}
// 		max_val = max(*stack_b);
// 		min_val = min(*stack_b);
// 		positions = calc_positions(*stack_a, *stack_b, max_val, min_val);
// 		perfect_position(positions, stack_a, stack_b);
// 		ft_lstclear(&positions);
// 	}
// }

static void	copy_stack(t_list *stack_a, t_list **cp)
{
	while (stack_a)
	{
		ft_lstadd_back(cp, ft_lstnew(stack_a->content));
		stack_a = stack_a->next;
	}
}

static void	sort_stack(t_list *stack)
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

static void	check_from_top_first(t_list **stack_a, t_list **stack_b, t_list *cp)
{
	while (*stack_a && (*stack_a)->content < cp->content)
	{
		run_actions_for_push_swap("pb\n", stack_a, stack_b);
	}
}

static void	check_from_bottom(t_list **stack_a, t_list **stack_b, t_list *cp)
{
	t_list	*temp;

	while (*stack_a)
	{
		temp = *stack_a;
		while (temp->next)
			temp = temp->next;
		if (temp->content < cp->content)
		{
			run_actions_for_push_swap("rra\n", stack_a, stack_b);
			run_actions_for_push_swap("pb\n", stack_a, stack_b);
		}
		else
			return ;
	}
}

static void	check_from_top_again(t_list **stack_a, t_list **stack_b, t_list *cp)
{
	t_list	*temp;
	int		index_a;

	temp = *stack_a;
	index_a = 0;
	while (temp)
	{
		if (temp->content < cp->content)
		{
			while (index_a > 0)
			{
				run_actions_for_push_swap("ra\n", stack_a, stack_b);
				index_a--;
			}
			run_actions_for_push_swap("pb\n", stack_a, stack_b);
			temp = *stack_a;
			continue ;
		}
		index_a++;
		temp = temp->next;
	}
}

static void	push_to_b(t_list **stack_a, t_list **stack_b, t_list *cp)
{
	int	middle;
	int	i;

	while (ft_lstsize(*stack_a) > 3)
	{
		i = 1;
		middle = ft_lstsize(cp) / 2;
		while (cp && i < middle)
		{
			cp = cp->next;
			i++;
		}
		check_from_top_first(stack_a, stack_b, cp);
		check_from_bottom(stack_a, stack_b, cp);
		check_from_top_again(stack_a, stack_b, cp);
	}
}

static void	from_a_to_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*cp;

	cp = NULL;
	copy_stack(*stack_a, &cp);
	sort_stack(cp);
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
		positions = calc_positions_b(*stack_a, *stack_b, max_val, min_val);
		perfect_position_b(positions, stack_a, stack_b);
		ft_lstclear(&positions);
	}
}

// static void	push_swap_run(t_list **stack_a, t_list **stack_b)
// {
// 	from_a_to_b(stack_a, stack_b);
// 	if (ft_lstsize(*stack_a) == 3)
// 		three_elements(stack_a, stack_b);
// 	from_b_to_a(stack_a, stack_b);
// 	small_to_top(stack_a, stack_b);
// }

void	push_swap(t_list **stack_a, t_list **stack_b)
{
	// if (ft_lstsize(*stack_a) > 4)
	// {
	// 	run_actions_for_push_swap("pb\n", stack_a, stack_b);
	// 	run_actions_for_push_swap("pb\n", stack_a, stack_b);
	// }
	// else if (ft_lstsize(*stack_a) > 3)
	// 	run_actions_for_push_swap("pb\n", stack_a, stack_b);
	from_a_to_b(stack_a, stack_b);
	if (ft_lstsize(*stack_a) == 3)
		three_elements(stack_a, stack_b);
	from_b_to_a(stack_a, stack_b);
	small_to_top(stack_a, stack_b);
}
