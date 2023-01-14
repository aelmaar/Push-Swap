/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:09:47 by ael-maar          #+#    #+#             */
/*   Updated: 2023/01/10 23:57:09 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "push_swap.h"
#include <stdio.h>

static void	print_list(t_list *head)
{
	while (head)
	{
		printf("%d\n", head->content);
		head = head->next;
	}
}

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	check_errors(argc, argv, &stack_a);
	push_swap(stack_a, stack_b);
	ft_lstclear(&stack_a);
}
