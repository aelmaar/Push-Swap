/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:11:42 by ael-maar          #+#    #+#             */
/*   Updated: 2023/01/15 15:53:08 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

void	rotate(t_list *stack)
{
	t_list	*new;
	t_list	*temp;
	int		reserve_top;

	temp = stack;
	if (temp)
	{
		new = NULL;
		reserve_top = stack->content;
		temp = temp->next;
		while (temp)
		{
			ft_lstadd_back(&new, ft_lstnew(temp->content));
			temp = temp->next;
		}
		temp = new;
		while(temp)
		{
			stack->content = temp->content;
			stack = stack->next;
			temp = temp->next;
		}
		stack->content = reserve_top;
		ft_lstclear(&new);
	}
}

void	rev_rotate(t_list *stack)
{
	t_list	*new;
	t_list	*temp;
	int		reserve_last;

	temp = stack;
	if (temp)
	{
		new = NULL;
		reserve_last = ft_lstlast(stack)->content;
		while (temp->next)
		{
			ft_lstadd_back(&new, ft_lstnew(temp->content));
			temp = temp->next;
		}
		temp = new;
		stack->content = reserve_last;
		while(temp)
		{
			stack = stack->next;
			stack->content = temp->content;
			temp = temp->next;
		}
		ft_lstclear(&new);
	}
}

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

void	swap(t_list	*stack)
{
	int	temp;

	if (stack)
	{
		if (stack->next)
		{
			temp = stack->content;
			stack->content = stack->next->content;
			stack->next->content = temp;
		}
	}
}