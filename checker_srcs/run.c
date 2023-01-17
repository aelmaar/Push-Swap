/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:59:37 by ael-maar          #+#    #+#             */
/*   Updated: 2023/01/17 17:29:30 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "checker.h"

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;

	check_errors(argc, argv, &stack_a);
	checker(&stack_a, &stack_b);
	check_if_stack_a_sorted(stack_a, stack_b);
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
}
