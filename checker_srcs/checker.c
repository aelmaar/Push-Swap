/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:59:57 by ael-maar          #+#    #+#             */
/*   Updated: 2023/01/17 17:48:38 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "actions.h"
#include "get_next_line.h"

void	checker(t_list	**stack_a, t_list **stack_b)
{
	int		rd;
	char	*action;

	while ((action = get_next_line(0)) != NULL)
	{
		run_actions_for_checker(action, stack_a, stack_b);
	}
}