/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:37:32 by ael-maar          #+#    #+#             */
/*   Updated: 2023/01/20 19:51:34 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

static void	print_error_and_clear(t_list *head)
{
	ft_lstclear(&head);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

static void	check_duplicates(t_list *head)
{
	t_list	*temp;
	t_list	*free_list;

	if (!head)
		return ;
	free_list = head;
	while (head)
	{
		temp = head->next;
		while (temp)
		{
			if (head->content == temp->content)
				print_error_and_clear(free_list);
			temp = temp->next;
		}
		head = head->next;
	}
}

static void	check_if_empty_args(char *argv, t_list *stack_a)
{
	while (*argv)
	{
		if (*argv != ' ')
			return ;
		argv++;
	}
	print_error_and_clear(stack_a);
}

static void	check_alpha_args(char *argv[], t_list **head)
{
	int		i;
	int		j;
	t_list	*new;

	i = 1;
	while (argv[i])
	{
		check_if_empty_args(argv[i], *head);
		j = 0;
		while (argv[i][j])
		{
			while (argv[i][j] == ' ')
				j++;
			if (argv[i][j])
			{
				new = ft_lstnew(ft_atoi(&argv[i][j], *head));
				ft_lstadd_back(head, new);
				check_duplicates(*head);
			}
			while (argv[i][j] && argv[i][j] != ' ')
				j++;
		}
		i++;
	}
}

void	check_errors(int argc, char *argv[], t_list **head)
{
	if (argc > 1)
		check_alpha_args(argv, head);
}
