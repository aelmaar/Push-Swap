/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_run_moves_stack_a.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 14:37:34 by ael-maar          #+#    #+#             */
/*   Updated: 2023/01/16 16:42:51 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	smart_rotate(int index_a, int index_b, \
					t_list **stack_a, t_list **stack_b)
{
	while (index_a > 0 && index_b > 0)
	{
		run_actions("rr\n", stack_a, stack_b);
		index_a--;
		index_b--;
	}
	while (index_a)
	{
		run_actions("ra\n", stack_a, stack_b);
		index_a--;
	}
	while (index_b)
	{
		run_actions("rb\n", stack_a, stack_b);
		index_b--;
	}
}

void	smart_rev_rotate(int index_a, int index_b, \
						t_list **stack_a, t_list **stack_b)
{
	int	stack_a_size;
	int	stack_b_size;

	stack_a_size = ft_lstsize(*stack_a);
	stack_b_size = ft_lstsize(*stack_b);
	while (index_a < stack_a_size && index_b < stack_b_size)
	{
		run_actions("rrr\n", stack_a, stack_b);
		index_a++;
		index_b++;
	}
	while (index_a < stack_a_size)
	{
		run_actions("rra\n", stack_a, stack_b);
		index_a++;
	}
	while (index_b < stack_b_size)
	{
		run_actions("rrb\n", stack_a, stack_b);
		index_b++;
	}
}

static void	normal_rotate(int index, char *action, \
							t_list **stack_a, t_list **stack_b)
{
	while (index > 0)
	{
		run_actions(action, stack_a, stack_b);
		index--;
	}
}

void	normal_rotation(int index_a, int index_b, \
						t_list **stack_a, t_list **stack_b)
{
	int	stack_a_size;
	int	stack_b_size;

	stack_a_size = ft_lstsize(*stack_a);
	stack_b_size = ft_lstsize(*stack_b);
	if (index_a <= (stack_a_size / 2))
		normal_rotate(index_a, "ra\n", stack_a, stack_b);
	else
	{
		while (index_a < stack_a_size)
		{
			run_actions("rra\n", stack_a, stack_b);
			index_a++;
		}
	}
	if (index_b <= (stack_b_size / 2))
		normal_rotate(index_b, "rb\n", stack_a, stack_b);
	else
	{
		while (index_b < stack_b_size)
		{
			run_actions("rrb\n", stack_a, stack_b);
			index_b++;
		}
	}
}
