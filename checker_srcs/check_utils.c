/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:26:05 by ael-maar          #+#    #+#             */
/*   Updated: 2023/01/17 17:51:43 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	check_if_stack_a_sorted(t_list *stack_a, t_list *stack_b)
{
	if (ft_lstsize(stack_b) > 0)
	{
		ft_putstr_fd("KO\n", 1);
		return ;
	}
	while (stack_a)
	{
		if ((stack_a->next && stack_a->content > stack_a->next->content))
		{
			ft_putstr_fd("KO\n", 1);
			return ;
		}
		stack_a = stack_a->next;
	}
	ft_putstr_fd("OK\n", 1);
}
