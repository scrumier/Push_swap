/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   targets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scrumier <scrumier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 17:50:00 by scrumier          #+#    #+#             */
/*   Updated: 2026/09/09 17:50:00 by scrumier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*stack_min(t_list *stack)
{
	t_list	*min;

	if (!stack)
		return (NULL);
	min = stack;
	while (stack)
	{
		if (stack->index < min->index)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

t_list	*stack_max(t_list *stack)
{
	t_list	*max;

	if (!stack)
		return (NULL);
	max = stack;
	while (stack)
	{
		if (stack->index > max->index)
			max = stack;
		stack = stack->next;
	}
	return (max);
}

/*
** B is kept circularly sorted in descending order: the target of a
** value is the greatest element below it, or the maximum of B when
** the value leaves the current range.
*/
t_list	*target_in_b(t_list *b, int index)
{
	t_list	*target;
	t_list	*it;

	target = NULL;
	it = b;
	while (it)
	{
		if (it->index < index && (!target || it->index > target->index))
			target = it;
		it = it->next;
	}
	if (!target)
		target = stack_max(b);
	return (target);
}

/*
** A ends up circularly sorted in ascending order: the target of a
** value is the smallest element above it, or the minimum of A when
** the value is greater than everything.
*/
t_list	*target_in_a(t_list *a, int index)
{
	t_list	*target;
	t_list	*it;

	target = NULL;
	it = a;
	while (it)
	{
		if (it->index > index && (!target || it->index < target->index))
			target = it;
		it = it->next;
	}
	if (!target)
		target = stack_min(a);
	return (target);
}
