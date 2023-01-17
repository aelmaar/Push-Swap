/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_moves_stack_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 14:35:42 by ael-maar          #+#    #+#             */
/*   Updated: 2023/01/16 21:43:20 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	apply_operation(int index_a, t_list	**stack_a, \
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
	run_actions("pb\n", stack_a, stack_b);
}

static void	find_index(int index_a, t_list **stack_a, \
						t_list **stack_b, int index_b)
{
	t_list	*temp_a;
	t_list	*temp_b;
	int		i;

	temp_a = *stack_a;
	temp_b = *stack_b;
	i = 0;
	to_position(&temp_a, &i, index_a);
	i = 0;
	to_position(&temp_b, &i, index_b);
	while (1)
	{
		while (temp_b)
		{
			if (temp_a->content > temp_b->content)
			{
				apply_operation(index_a, stack_a, stack_b, i);
				return ;
			}
			i++;
			temp_b = temp_b->next;
		}
		i = 0;
		temp_b = *stack_b;
	}
}

static void	apply_position(int index_a, t_list **stack_a, t_list **stack_b)
{
	int				i;
	t_enumeration	max_val;
	t_enumeration	min_val;
	t_list			*temp;

	i = 0;
	max_val = max(*stack_b);
	min_val = min(*stack_b);
	temp = *stack_a;
	while (temp && i != index_a)
	{
		temp = temp->next;
		i++;
	}
	if ((temp->content > max_val.value && temp->content > min_val.value))
		apply_operation(index_a, stack_a, stack_b, max_val.index);
	else if ((temp->content < max_val.value && temp->content < min_val.value))
		apply_operation(index_a, stack_a, stack_b, max_val.index);
	else
		find_index(index_a, stack_a, stack_b, max_val.index);
}

void	perfect_position(t_list *positions, t_list **stack_a, t_list **stack_b)
{
	int			i;
	int			index_a;
	int			min;

	i = 0;
	index_a = i;
	min = positions->content;
	while (positions)
	{
		if (min > positions->content)
		{
			min = positions->content;
			index_a = i;
		}
		positions = positions->next;
		i++;
	}
	apply_position(index_a, stack_a, stack_b);
}
