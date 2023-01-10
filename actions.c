/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:11:42 by ael-maar          #+#    #+#             */
/*   Updated: 2023/01/10 22:46:28 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

void	ra(t_list *stack_a)
{
	t_list	*new;
	t_list	*temp;
	int		reserve_top;

	temp = stack_a;
	if (temp)
	{
		new = NULL;
		reserve_top = stack_a->content;
		temp = temp->next;
		while (temp)
		{
			ft_lstadd_back(&new, ft_lstnew(temp->content));
			temp = temp->next;
		}
		temp = new;
		while(temp)
		{
			stack_a->content = temp->content;
			stack_a = stack_a->next;
			temp = temp->next;
		}
		stack_a->content = reserve_top;
		ft_lstclear(&new);
	}
}

void	rra(t_list *stack_a)
{
	t_list	*new;
	t_list	*temp;
	int		reserve_last;

	temp = stack_a;
	if (temp)
	{
		new = NULL;
		reserve_last = ft_lstlast(stack_a)->content;
		while (temp->next)
		{
			ft_lstadd_back(&new, ft_lstnew(temp->content));
			temp = temp->next;
		}
		temp = new;
		stack_a->content = reserve_last;
		while(temp)
		{
			stack_a = stack_a->next;
			stack_a->content = temp->content;
			temp = temp->next;
		}
		ft_lstclear(&new);
	}
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if (*stack_a)
	{
		temp = *stack_a;
		*stack_a = (*stack_a)->next;
		ft_lstadd_front(stack_b, ft_lstnew(temp->content));
		ft_lstdelone(temp);
	}
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if (*stack_b)
	{
		temp = *stack_b;
		*stack_b = (*stack_b)->next;
		ft_lstadd_front(stack_a, ft_lstnew(temp->content));
		ft_lstdelone(temp);
	}
}
