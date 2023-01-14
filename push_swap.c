/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 19:17:50 by ael-maar          #+#    #+#             */
/*   Updated: 2023/01/11 22:39:39 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static enumeration  max(t_list *stack_b)
{
	int			i;
    enumeration val_ind;

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

static enumeration  min(t_list *stack_b)
{
	int			i;
    enumeration val_ind;

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

static int	calc_operations(int index, t_list *stack_a, t_list *stack_b, enumeration max_val)
{
	int ope;
	int	stack_a_size;
	int	stack_b_size;

	stack_a_size = ft_lstsize(stack_a);
	stack_b_size = ft_lstsize(stack_b);
	ope = 0;
	if (index <= (stack_a_size / 2) && max_val.index <= (stack_b_size / 2))
	{
		while (index > 0 || max_val.index > 0)
		{
			ope++;
			index--;
			max_val.index--;
		}
	}
	else if (index >= (stack_a_size / 2) && max_val.index >= (stack_b_size / 2))
	{
		while (index < stack_a_size || max_val.index < stack_b_size)
		{
			ope++;
			index++;
			max_val.index++;
		}
	}
	else
	{
		if (index <= (stack_a_size / 2))
			ope += index;
		else
			ope += (stack_a_size - index);
		if (max_val.index <= (stack_b_size / 2))
			ope += max_val.index;
		else
			ope += (stack_b_size - max_val.index);
	}
	return (ope);
}

static t_list	*calc_positions(t_list *stack_a, t_list *stack_b)
{
	enumeration	max_value;
	enumeration	min_value;
	t_list		*head;
	int			i;

	head = NULL;
	max_value = max(stack_b);
	min_value = min(stack_b);
	i = 0;
	while (stack_a)
	{
		if ((stack_a->content > max_value.value && stack_a->content > min_value.value))
			
	}
}

void	push_swap(t_list *stack_a, t_list *stack_b)
{
	pb(&stack_a, &stack_b);
    pb(&stack_a, &stack_b);
    
}