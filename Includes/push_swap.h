/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:21:18 by ael-maar          #+#    #+#             */
/*   Updated: 2023/01/18 16:29:45 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "error.h"
# include "actions.h"
# include "libft.h"

typedef struct enumeration
{
	int	index;
	int	value;
}	t_enumeration;

void			push_swap(t_list **stack_a, t_list **stack_b);
t_list			*calc_positions(t_list *stack_a, t_list *stack_b, \
								t_enumeration i_vone, t_enumeration i_vtwo);
t_list			*calc_positions_b(t_list *stack_a, t_list *stack_b, \
									t_enumeration max_v, t_enumeration min_v);
void			to_position(t_list **stack, int *index, int index_stack);
int				smart_calc_rotate(int index_a, int index_b);
int				smart_calc_revrotate(int index_a, int index_b, \
										int size_a, int size_b);
int				normal_calc_rotation(int index_a, int index_b, \
										int size_a, int size_b);
void			perfect_position(t_list *positions, \
									t_list **stack_a, t_list **stack_b);
void			perfect_position_b(t_list *positions, \
									t_list **stack_a, t_list **stack_b);
void			smart_rotate(int index_a, int index_b, \
								t_list	**stack_a, t_list **stack_b);
void			smart_rev_rotate(int index_a, int index_b, \
									t_list	**stack_a, t_list **stack_b);
void			normal_rotation(int index_a, int index_b, \
								t_list **stack_a, t_list **stack_b);
void			run_actions_for_push_swap(char *action, t_list **stack_a, t_list **stack_b);
void			three_elements(t_list **stack_a, t_list **stack_b);
t_enumeration	max(t_list *stack_b);
t_enumeration	min(t_list *stack_b);

#endif