/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:51:43 by ael-maar          #+#    #+#             */
/*   Updated: 2023/01/20 20:12:05 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTIONS_H
# define ACTIONS_H

# include "libft.h"

void	rotate(t_list **stack, int repeat);
void	rev_rotate(t_list **stack, int repeat);
void	swap(t_list	**stack);
void	push(t_list **stack_one, t_list **stack_two);

#endif