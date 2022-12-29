/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 11:36:25 by ael-maar          #+#    #+#             */
/*   Updated: 2022/12/29 18:33:17 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print_error_and_clear(t_list *head)
{
	ft_lstclear(&head);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

long	ft_atoi(const char *str, t_list *head)
{
	long	nb;
	long	sign;

	sign = 1;
	nb = 0;
	while (*str == 32)
		str++;
	if (*str == '-')
	{
		sign *= (-1);
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= 48 && *str <= 57)
	{
		nb = (nb * 10) + (*str - 48);
		str++;
	}
	if ((*str != ' ' && *str != '\0')
		|| (nb * sign) > INT_MAX || (nb * sign) < INT_MIN)
		print_error_and_clear(head);
	return (nb * sign);
}
