/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:21:50 by ael-maar          #+#    #+#             */
/*   Updated: 2023/01/20 18:20:02 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "libft.h"
# include "unistd.h"

void	run_actions_for_checker(char *action, t_list **stack_a, \
									t_list **stack_b, int repeat);
void	checker(t_list	**stack_a, t_list **stack_b);
void	check_if_stack_a_sorted(t_list *stack_a);
void	check_if_stack_b_empty(t_list *stack_b);

#endif