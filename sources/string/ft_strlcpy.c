/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 11:07:24 by fialexan          #+#    #+#             */
/*   Updated: 2023/04/04 19:29:43 by fialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	ret;
	size_t	len;

	ret = ft_strlen(src);
	if (size != 0)
	{
		if (ret >= size)
			len = size - 1;
		else
			len = ret;
		ft_memcpy(dest, src, len);
		dest[len] = '\0';
	}
	return (ret);
}
