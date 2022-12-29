/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:37:32 by ael-maar          #+#    #+#             */
/*   Updated: 2022/12/29 20:26:00 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include <stdio.h>

static void	print_list(t_list *head)
{
	while (head)
	{
		printf("%d\n", head->content);
		head = head->next;
	}
}

static void	print_error_and_clear(t_list *head)
{
	ft_lstclear(&head);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

static void	check_duplicates(t_list *head)
{
	t_list	*temp;

	if (!head)
		return ;
	temp = head;
	head = head->next;
	while (temp)
	{
		while (head)
		{
			if (temp->content == head->content)
				print_error_and_clear(head);
			head = head->next;
		}
		temp = temp->next;
	}
}

static void	check_alpha_args(int argc, char *argv[], t_list **head)
{
	int		i;
	int		j;
	t_list	*new;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			while (argv[i][j] == ' ')
				j++;
			if (argv[i][j])
			{
				new = ft_lstnew(ft_atoi(&argv[i][j], *head));
				ft_lstadd_front(head, new);
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
	print_list(*head);
}
