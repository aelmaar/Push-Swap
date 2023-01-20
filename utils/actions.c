/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:11:42 by ael-maar          #+#    #+#             */
/*   Updated: 2023/01/20 13:12:58 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

void	push(t_list **stack_one, t_list **stack_two)
{
	t_list	*temp;

	if (*stack_one)
	{
		temp = *stack_one;
		*stack_one = (*stack_one)->next;
		ft_lstadd_front(stack_two, ft_lstnew(temp->content));
		ft_lstdelone(temp);
	}
}

void	rotate(t_list **stack, int repeat)
{
	t_list	*reserve_top;
	t_list	*temp;

	reserve_top = NULL;
	temp = NULL;
	while (repeat > 0)
	{
		if (*stack)
		{
			push(stack, &reserve_top);
			while (*stack)
				push(stack, &temp);
			push(&reserve_top, stack);
			while (temp)
				push(&temp, stack);
		}
		repeat--;
	}
}

void	rev_rotate(t_list **stack, int repeat)
{
	t_list	*reserve_last;
	t_list	*temp;

	reserve_last = NULL;
	temp = NULL;
	while (repeat > 0)
	{
		if (*stack)
		{
			while ((*stack)->next)
				push(stack, &temp);
			push(stack, &reserve_last);
			while (temp)
				push(&temp, stack);
			push(&reserve_last, stack);
		}
		repeat--;
	}
}

void	swap(t_list	**stack)
{
	t_list	*first_top_element;
	t_list	*second_top_element;

	first_top_element = NULL;
	second_top_element = NULL;
	if (*stack)
	{
		if ((*stack)->next)
		{
			push(stack, &first_top_element);
			push(stack, &second_top_element);
			push(&first_top_element, stack);
			push(&second_top_element, stack);
		}
	}
}
