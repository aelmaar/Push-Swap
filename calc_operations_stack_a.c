/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_operations_stack_a.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 14:17:37 by ael-maar          #+#    #+#             */
/*   Updated: 2023/01/16 17:26:04 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	calc_operations(int index_a, t_list *stack_a, \
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

static int	findindex(int index_a, t_list *stack_a, \
							t_list *stack_b, int index_b)
{
	t_list	*temp_a;
	t_list	*temp_b;
	int		i;

	temp_a = stack_a;
	temp_b = stack_b;
	i = 0;
	to_position(&stack_a, &i, index_a);
	i = 0;
	to_position(&stack_b, &i, index_b);
	while (1)
	{
		while (stack_b)
		{
			if (stack_a->content > stack_b->content)
				return (calc_operations(index_a, temp_a, temp_b, i));
			i++;
			stack_b = stack_b->next;
		}
		i = 0;
		stack_b = temp_b;
	}
}

t_list	*calc_positions(t_list *stack_a, t_list *stack_b, \
						enumeration mx_v, enumeration mn_v)
{
	t_list		*temp_a;
	t_list		*head;
	int			ope;
	int			i;

	head = NULL;
	temp_a = stack_a;
	i = 0;
	while (stack_a)
	{
		if ((stack_a->content > mx_v.value && stack_a->content > mn_v.value)
			|| (stack_a->content < mx_v.value && stack_a->content < mn_v.value))
		{
			ope = calc_operations(i, temp_a, stack_b, mx_v.index);
			ft_lstadd_back(&head, ft_lstnew(ope));
		}
		else
		{
			ope = findindex(i, temp_a, stack_b, mx_v.index);
			ft_lstadd_back(&head, ft_lstnew(ope));
		}
		i++;
		stack_a = stack_a->next;
	}
	return (head);
}
