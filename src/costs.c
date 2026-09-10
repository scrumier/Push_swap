/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scrumier <scrumier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 17:50:00 by scrumier          #+#    #+#             */
/*   Updated: 2026/09/09 17:50:00 by scrumier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	max2(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

static int	pos_of(t_list *stack, t_list *node)
{
	int	pos;

	pos = 0;
	while (stack && stack != node)
	{
		pos++;
		stack = stack->next;
	}
	return (pos);
}

static void	fill_move(t_move *mv, int mode, int p[2], int s[2])
{
	mv->ra = 0;
	mv->rb = 0;
	mv->rra = 0;
	mv->rrb = 0;
	if (mode == 0)
	{
		mv->ra = p[0];
		mv->rb = p[1];
	}
	else if (mode == 1)
	{
		mv->rra = s[0] - p[0];
		mv->rrb = s[1] - p[1];
	}
	else if (mode == 2)
	{
		mv->ra = p[0];
		mv->rrb = s[1] - p[1];
	}
	else
	{
		mv->rra = s[0] - p[0];
		mv->rb = p[1];
	}
}

/*
** Four ways to bring a node and its target to the top of each
** stack: rotations in the same direction share rr/rrr, the two
** others trade combined moves for plain ones. The cheapest wins.
*/
int	best_move(t_list *a, t_list *b, t_list *node, t_move *mv)
{
	int		p[2];
	int		s[2];
	int		cost[4];
	int		mode;

	p[0] = pos_of(a, node);
	p[1] = pos_of(b, target_in_b(b, node->index));
	s[0] = ft_lstsize(a);
	s[1] = ft_lstsize(b);
	cost[0] = max2(p[0], p[1]);
	cost[1] = max2(s[0] - p[0], s[1] - p[1]);
	cost[2] = p[0] + s[1] - p[1];
	cost[3] = s[0] - p[0] + p[1];
	mode = 0;
	if (cost[1] < cost[mode])
		mode = 1;
	if (cost[2] < cost[mode])
		mode = 2;
	if (cost[3] < cost[mode])
		mode = 3;
	fill_move(mv, mode, p, s);
	return (cost[mode]);
}

void	pick_move(t_list *a, t_list *b, t_move *mv)
{
	t_move	tmp;
	t_list	*it;
	int		cost;
	int		best_cost;

	best_cost = -1;
	it = a;
	while (it)
	{
		cost = best_move(a, b, it, &tmp);
		if (best_cost < 0 || cost < best_cost)
		{
			best_cost = cost;
			*mv = tmp;
		}
		it = it->next;
	}
}
