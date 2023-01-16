/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_moves_stack_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:37:54 by ael-maar          #+#    #+#             */
/*   Updated: 2023/01/16 20:20:29 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	apply_operation_b(int index_a, t_list **stack_a, \
								t_list **stack_b, int index_b)
{
	int	stack_a_size;
	int	stack_b_size;

	stack_a_size = ft_lstsize(*stack_a);
	stack_b_size = ft_lstsize(*stack_b);
	if (index_a <= (stack_a_size / 2) && index_b <= (stack_b_size / 2))
	{
		smart_rotate(index_a, index_b, stack_a, stack_b);
	}
	else if (index_a >= (stack_a_size / 2) && index_b >= (stack_b_size / 2))
	{
		smart_rev_rotate(index_a, index_b, stack_a, stack_b);
	}
	else
	{
		normal_rotation(index_a, index_b, stack_a, stack_b);
	}
	run_actions("pa\n", stack_a, stack_b);
}

static void	find_index_b(int index_a, t_list **stack_a, \
						t_list **stack_b, int index_b)
{
	t_list	*temp_a;
	t_list	*temp_b;
	int		i;

	temp_a = *stack_a;
	temp_b = *stack_b;
	i = 0;
	to_position(&temp_b, &i, index_b);
	i = 0;
	to_position(&temp_a, &i, index_a);
	while (1)
	{
		while (temp_a)
		{
			if (temp_b->content < temp_a->content)
			{
				apply_operation_b(i, stack_a, stack_b, index_b);
				return ;
			}
			i++;
			temp_a = temp_a->next;
		}
		i = 0;
		temp_a = *stack_a;
	}
}
static void	apply_position_b(int index_b, t_list **stack_a, t_list **stack_b)
{
	int			i;
	enumeration	max_val;
	enumeration	min_val;
	t_list		*temp;

	i = 0;
	max_val = max(*stack_a);
	min_val = min(*stack_a);
	temp = *stack_b;
	to_position(&temp, &i, index_b);
	if ((temp->content > max_val.value && temp->content > min_val.value))
		apply_operation_b(min_val.index, stack_a, stack_b, index_b);
	else if ((temp->content < max_val.value && temp->content < min_val.value))
		apply_operation_b(min_val.index, stack_a, stack_b, index_b);
	else
		find_index_b(min_val.index, stack_a, stack_b, index_b);
}

void	perfect_position_b(t_list *positions, \
							t_list **stack_a, t_list **stack_b)
{
	int			i;
	int			index_b;
	int			min;

	i = 0;
	index_b = i;
	min = positions->content;
	while (positions)
	{
		if (min > positions->content)
		{
			min = positions->content;
			index_b = i;
		}
		positions = positions->next;
		i++;
	}
	apply_position_b(index_b, stack_a, stack_b);
}
