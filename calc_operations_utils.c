/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_operations_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 14:50:38 by ael-maar          #+#    #+#             */
/*   Updated: 2023/01/16 21:45:58 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	smart_calc_rotate(int index_a, int index_b)
{
	int	ope;

	ope = 0;
	while (index_a > 0 || index_b > 0)
	{
		ope++;
		index_a--;
		index_b--;
	}
	return (ope);
}

int	smart_calc_revrotate(int index_a, int index_b, int size_a, int size_b)
{
	int	ope;

	ope = 0;
	while (index_a < size_a || index_b < size_b)
	{
		ope++;
		index_a++;
		index_b++;
	}
	return (ope);
}

int	normal_calc_rotation(int index_a, int index_b, int size_a, int size_b)
{
	int	ope;

	ope = 0;
	if (index_a <= (size_a / 2))
		ope += index_a;
	else
		ope += (size_a - index_a);
	if (index_b <= (size_b / 2))
		ope += index_b;
	else
		ope += (size_b - index_b);
	return (ope);
}
