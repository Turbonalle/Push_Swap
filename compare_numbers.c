/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_numbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbagger <jbagger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:08:29 by jbagger           #+#    #+#             */
/*   Updated: 2023/01/05 12:47:16 by jbagger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	smallest(int n, ...)
{
	int		min;
	int		current;
	va_list	ptr;

	va_start(ptr, n);
	min = INT_MAX;
	while (n-- > 0)
	{
		current = va_arg(ptr, int);
		if (min > current)
			min = current;
	}
	va_end(ptr);
	return (min);
}

int	smaller(int a, int b)
{
	if (a <= b)
		return (a);
	return (b);
}

int	bigger(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}
