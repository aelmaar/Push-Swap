/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:37:32 by ael-maar          #+#    #+#             */
/*   Updated: 2023/01/16 22:12:07 by ael-maar         ###   ########.fr       */
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
	temp = head;
	free_list = head;
	head = head->next;
	while (temp)
	{
		while (head)
		{
			if (temp->content == head->content)
				print_error_and_clear(free_list);
			head = head->next;
		}
		temp = temp->next;
	}
}

static void	check_if_empty_args(char *argv)
{
	while (*argv)
	{
		if (*argv != ' ')
			return ;
		argv++;
	}
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

static void	check_alpha_args(int argc, char *argv[], t_list **head)
{
	int		i;
	int		j;
	t_list	*new;

	i = 1;
	while (argv[i])
	{
		check_if_empty_args(argv[i]);
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
	check_alpha_args(argc, argv, head);
}