/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_operations_stack_b.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:33:13 by ael-maar          #+#    #+#             */
/*   Updated: 2023/01/16 19:52:00 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	calc_operations_b(int index_a, t_list *stack_a, \
								t_list *stack_b, int index_b)
{
	int	ope;
	int	stack_a_size;
	int	stack_b_size;

	stack_a_size = ft_lstsize(stack_a);
	stack_b_size = ft_lstsize(stack_b);
	ope = 0;
	if (index_a <= (stack_a_size / 2) && index_b <= (stack_b_size / 2))
		ope = smart_calc_rotate(index_a, index_b);
	else if (index_a >= (stack_a_size / 2) && index_b >= (stack_b_size / 2))
		ope = smart_calc_revrotate(index_a, index_b, \
									stack_a_size, stack_b_size);
	else
		ope = normal_calc_rotation(index_a, index_b, \
									stack_a_size, stack_b_size);
	return (ope);
}

static int	findindex_b(int index_a, t_list *stack_a, \
						t_list *stack_b, int index_b)
{
	t_list	*temp_a;
	t_list	*temp_b;
	int		i;

	temp_a = stack_a;
	temp_b = stack_b;
	i = 0;
	to_position(&stack_b, &i, index_b);
	i = 0;
	to_position(&stack_a, &i, index_a);
	while (1)
	{
		while (stack_a)
		{
			if (stack_b->content < stack_a->content)
				return (calc_operations_b(i, temp_a, temp_b, index_b));
			i++;
			stack_a = stack_a->next;
		}
		i = 0;
		stack_a = temp_a;
	}
}

t_list	*calc_positions_b(t_list *stack_a, t_list *stack_b, \
						enumeration mx_v, enumeration mn_v)
{
	t_list		*temp;
	t_list		*head;
	int			ope;
	int			i;

	head = NULL;
	temp = stack_b;
	i = 0;
	while (stack_b)
	{
		if ((stack_b->content > mx_v.value && stack_b->content > mn_v.value)
			|| (stack_b->content < mx_v.value && stack_b->content < mn_v.value))
		{
			ope = calc_operations_b(mn_v.index, stack_a, temp, i);
			ft_lstadd_back(&head, ft_lstnew(ope));
		}
		else
		{
			ope = findindex_b(mn_v.index, stack_a, temp, i);
			ft_lstadd_back(&head, ft_lstnew(ope));
		}
		i++;
		stack_b = stack_b->next;
	}
	return (head);
}
