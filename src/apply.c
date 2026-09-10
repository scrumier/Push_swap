/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scrumier <scrumier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 17:50:00 by scrumier          #+#    #+#             */
/*   Updated: 2026/09/09 17:50:00 by scrumier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	apply_move(t_list **a, t_list **b, t_move *mv)
{
	while (mv->ra > 0 && mv->rb > 0)
	{
		rr(a, b);
		mv->ra--;
		mv->rb--;
	}
	while (mv->rra > 0 && mv->rrb > 0)
	{
		rrr(a, b);
		mv->rra--;
		mv->rrb--;
	}
	while (mv->ra-- > 0)
		ra(a, b);
	while (mv->rb-- > 0)
		rb(a, b);
	while (mv->rra-- > 0)
		rra(a, b);
	while (mv->rrb-- > 0)
		rrb(a, b);
}
