/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:21:18 by ael-maar          #+#    #+#             */
/*   Updated: 2023/01/11 18:53:02 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "error.h"
# include "actions.h"

typedef struct enumeration
{
	int	index;
	int	value;
} enumeration ;

void	push_swap(t_list *stack_a, t_list *stack_b);

#endif