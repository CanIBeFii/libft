/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipe <filipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 11:02:50 by fialexan          #+#    #+#             */
/*   Updated: 2023/04/04 22:59:09 by filipe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strdup(const char *s)
{
	size_t size;
	char *str;

	size = ft_strlen(s);
	str = malloc(sizeof(char) + (size + 1));
	if (str == NULL)
		return (NULL);
	return ((char *)ft_memcpy(str, s, size + 1));
}
