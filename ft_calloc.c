/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:31:50 by arturhar          #+#    #+#             */
/*   Updated: 2024/01/29 11:21:24 by arturhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	*ft_calloc(size_t items, size_t size)
{
	void	*ptr;

	ptr = malloc(items * size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, items * size);
	return (ptr);
}

// int main() {
// 	size_t count = 5;
// 	size_t size = sizeof(int);

// 	int *arr = (int *)ft_calloc(count, size);
// 	int *arr1 = (int *)calloc(count, size);
// 	for (size_t i = 0; i < count; i++)
// 	{
// 		printf("ft - %d \n", arr[i]);
// 	}
// 	for (size_t i = 0; i < count; i++)
// 	{
// 		printf("lib - %d \n", arr1[i]);
// 	}

// }
