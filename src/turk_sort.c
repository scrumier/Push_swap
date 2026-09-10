/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scrumier <scrumier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 17:50:00 by scrumier          #+#    #+#             */
/*   Updated: 2026/09/09 17:50:00 by scrumier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Two starter elements always form a circularly sorted stack in
** descending order. Every pb then inserts the cheapest node of A
** above its target in B, which preserves that order.
*/
static void	fill_b(t_list **a, t_list **b)
{
	t_move	mv;

	pb(a, b);
	pb(a, b);
	while (ft_lstsize(*a) > 3)
	{
		pick_move(*a, *b, &mv);
		apply_move(a, b, &mv);
		pb(a, b);
	}
}

static void	drain_b(t_list **a, t_list **b)
{
	t_list	*target;

	while (*b)
	{
		target = target_in_a(*a, (*b)->index);
		make_top(a, b, get_distance(a, target->index));
		pa(a, b);
	}
}

void	big_sort(t_list **a, t_list **b)
{
	fill_b(a, b);
	sort_3(a, b);
	drain_b(a, b);
	if (is_sorted(a))
		return ;
	make_top(a, b, get_distance(a, stack_min(*a)->index));
}
