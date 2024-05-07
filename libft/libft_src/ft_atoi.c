/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scrumier <scrumier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:31:46 by scrumier          #+#    #+#             */
/*   Updated: 2024/03/21 13:50:29 by scrumier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

long	ft_atoi(const char *nptr)
{
	long int	result;
	int			sign;

	sign = 1;
	result = 0;
	if (*nptr == '\0')
		return (0);
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == ' ')
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		if (sign == 1 && (result > (LONG_MAX - (*nptr - '0')) / 10))
			return (LONG_MAX);
		if (sign == -1 && (-result < (LONG_MIN + (*nptr - '0')) / 10))
			return (LONG_MIN);
		result = result * 10 + (*nptr - '0');
		nptr++;
	}
	return (result * sign);
}
