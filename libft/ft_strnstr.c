/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 10:12:44 by hajeong           #+#    #+#             */
/*   Updated: 2023/01/16 17:01:19 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	haystack_size;
	size_t	needle_size;

	i = 0;
	(void)haystack_size;
	haystack_size = ft_strlen(haystack);
	needle_size = ft_strlen(needle);
	if (needle_size == 0)
		return ((char *)haystack);
	while (haystack[i] != 0 && i + needle_size <= len)
	{
		if (ft_strncmp(haystack + i, needle, needle_size) == 0)
			return ((char *)haystack + i);
		i++;
	}
	return (0);
}
