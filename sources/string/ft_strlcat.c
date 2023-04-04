/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipe <filipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 11:05:07 by fialexan          #+#    #+#             */
/*   Updated: 2023/04/04 22:59:28 by filipe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t src_len;
	size_t dst_len;
	size_t len;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dest);
	len = src_len + dst_len;
	size -= dst_len;
	if (src_len >= size)
		src_len = size - 1;
	dest += dst_len;
	ft_memcpy(dest, src, src_len);
	dest[src_len] = '\0';
	return (len);
}
