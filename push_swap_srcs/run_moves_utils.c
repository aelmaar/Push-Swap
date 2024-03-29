/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_moves_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 14:37:34 by ael-maar          #+#    #+#             */
/*   Updated: 2023/01/20 18:23:06 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	smart_rotate(int index_a, int index_b, \
					t_list **stack_a, t_list **stack_b)
{
	while (index_a > 0 && index_b > 0)
	{
		run_actions_for_push_swap("rr\n", stack_a, stack_b, 1);
		index_a--;
		index_b--;
	}
	run_actions_for_push_swap("ra\n", stack_a, stack_b, index_a);
	run_actions_for_push_swap("rb\n", stack_a, stack_b, index_b);
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
		run_actions_for_push_swap("rrr\n", stack_a, stack_b, 1);
		index_a++;
		index_b++;
	}
	run_actions_for_push_swap("rra\n", stack_a, stack_b, stack_a_size - index_a);
	run_actions_for_push_swap("rrb\n", stack_a, stack_b, stack_b_size - index_b);
}

void	normal_rotation(int index_a, int index_b, \
						t_list **stack_a, t_list **stack_b)
{
	int	stack_a_size;
	int	stack_b_size;

	stack_a_size = ft_lstsize(*stack_a);
	stack_b_size = ft_lstsize(*stack_b);
	if (index_a <= (stack_a_size / 2))
		run_actions_for_push_swap("ra\n", stack_a, stack_b, index_a);
	else
		run_actions_for_push_swap("rra\n", stack_a, stack_b, \
									stack_a_size - index_a);
	if (index_b <= (stack_b_size / 2))
		run_actions_for_push_swap("rb\n", stack_a, stack_b, index_b);
	else
		run_actions_for_push_swap("rrb\n", stack_a, stack_b, \
									stack_b_size - index_b);
}
