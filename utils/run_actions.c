/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_actions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 15:32:41 by ael-maar          #+#    #+#             */
/*   Updated: 2023/01/20 18:16:48 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

static void	rr(t_list **stack_a, t_list **stack_b, int repeat)
{
	rotate(stack_a, repeat);
	rotate(stack_b, repeat);
}

static void	rrr(t_list **stack_a, t_list **stack_b, int repeat)
{
	rev_rotate(stack_a, repeat);
	rev_rotate(stack_b, repeat);
}

void	run_actions_for_push_swap(char *action, t_list **stack_a, \
									t_list **stack_b, int repeat)
{
	if (!ft_strncmp(action, "sa\n", ft_strlen(action)))
		swap(stack_a);
	else if (!ft_strncmp(action, "sb\n", ft_strlen(action)))
		swap(stack_b);
	else if (!ft_strncmp(action, "ra\n", ft_strlen(action)))
		rotate(stack_a, repeat);
	else if (!ft_strncmp(action, "rb\n", ft_strlen(action)))
		rotate(stack_b, repeat);
	else if (!ft_strncmp(action, "rra\n", ft_strlen(action)))
		rev_rotate(stack_a, repeat);
	else if (!ft_strncmp(action, "rrb\n", ft_strlen(action)))
		rev_rotate(stack_b, repeat);
	else if (!ft_strncmp(action, "rr\n", ft_strlen(action)))
		rr(stack_a, stack_b, repeat);
	else if (!ft_strncmp(action, "rrr\n", ft_strlen(action)))
		rrr(stack_a, stack_b, repeat);
	else if (!ft_strncmp(action, "pa\n", ft_strlen(action)))
		push(stack_b, stack_a);
	else if (!ft_strncmp(action, "pb\n", ft_strlen(action)))
		push(stack_a, stack_b);
	while (repeat > 0)
	{
		ft_putstr_fd(action, 1);
		repeat--;
	}
}

static void	check_if_other_action(char *action, \
									t_list **stack_a, t_list **stack_b)
{
	ft_lstclear(stack_a);
	ft_lstclear(stack_b);
	free(action);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	run_actions_for_checker(char *action, \
								t_list **stack_a, t_list **stack_b, int repeat)
{
	if (!ft_strncmp(action, "sa\n", ft_strlen(action)))
		swap(stack_a);
	else if (!ft_strncmp(action, "sb\n", ft_strlen(action)))
		swap(stack_b);
	else if (!ft_strncmp(action, "ra\n", ft_strlen(action)))
		rotate(stack_a, repeat);
	else if (!ft_strncmp(action, "rb\n", ft_strlen(action)))
		rotate(stack_b, repeat);
	else if (!ft_strncmp(action, "rra\n", ft_strlen(action)))
		rev_rotate(stack_a, repeat);
	else if (!ft_strncmp(action, "rrb\n", ft_strlen(action)))
		rev_rotate(stack_b, repeat);
	else if (!ft_strncmp(action, "rr\n", ft_strlen(action)))
		rr(stack_a, stack_b, repeat);
	else if (!ft_strncmp(action, "rrr\n", ft_strlen(action)))
		rrr(stack_a, stack_b, repeat);
	else if (!ft_strncmp(action, "pa\n", ft_strlen(action)))
		push(stack_b, stack_a);
	else if (!ft_strncmp(action, "pb\n", ft_strlen(action)))
		push(stack_a, stack_b);
	else
		check_if_other_action(action, stack_a, stack_b);
}
