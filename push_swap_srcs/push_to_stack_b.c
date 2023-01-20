/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_stack_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 09:35:57 by ael-maar          #+#    #+#             */
/*   Updated: 2023/01/20 19:18:00 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_from_top_first(t_list **stack_a, t_list **stack_b, t_list *cp)
{
	while (*stack_a && (*stack_a)->content < cp->content)
	{
		run_actions_for_push_swap("pb\n", stack_a, stack_b, 1);
	}
}

static void	check_from_bottom(t_list **stack_a, t_list **stack_b, t_list *cp)
{
	t_list	*temp;

	while (*stack_a)
	{
		temp = *stack_a;
		while (temp->next)
			temp = temp->next;
		if (temp->content < cp->content)
		{
			run_actions_for_push_swap("rra\n", stack_a, stack_b, 1);
			run_actions_for_push_swap("pb\n", stack_a, stack_b, 1);
		}
		else
			return ;
	}
}

static void	check_from_top_again(t_list **stack_a, t_list **stack_b, t_list *cp)
{
	t_list	*temp;
	int		index_a;

	temp = *stack_a;
	index_a = 0;
	while (temp)
	{
		if (temp->content < cp->content)
		{
			run_actions_for_push_swap("ra\n", stack_a, stack_b, index_a);
			run_actions_for_push_swap("pb\n", stack_a, stack_b, 1);
			temp = *stack_a;
			index_a = 0;
			continue ;
		}
		index_a++;
		temp = temp->next;
	}
}

static int	check_if_stack_a_sorted(t_list *stack_a)
{
	while (stack_a)
	{
		if ((stack_a->next && stack_a->content > stack_a->next->content))
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

void	push_to_b(t_list **stack_a, t_list **stack_b, t_list *cp)
{
	int	middle;
	int	i;

	while (ft_lstsize(cp) > 3 && !check_if_stack_a_sorted(*stack_a))
	{
		i = 1;
		middle = ft_lstsize(cp) / 2;
		while (cp && i < middle)
		{
			cp = cp->next;
			i++;
		}
		check_from_top_first(stack_a, stack_b, cp);
		check_from_bottom(stack_a, stack_b, cp);
		check_from_top_again(stack_a, stack_b, cp);
	}
}
