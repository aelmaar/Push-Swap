/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:59:57 by ael-maar          #+#    #+#             */
/*   Updated: 2023/01/20 18:21:08 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "actions.h"
#include "get_next_line.h"

void	checker(t_list	**stack_a, t_list **stack_b)
{
	char	*action;

	action = get_next_line(0);
	while (action != NULL)
	{
		run_actions_for_checker(action, stack_a, stack_b, 1);
		free(action);
		action = get_next_line(0);
	}
	check_if_stack_a_sorted(*stack_a);
	check_if_stack_b_empty(*stack_b);
}
