/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrittan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 14:25:27 by gbrittan          #+#    #+#             */
/*   Updated: 2020/11/07 17:19:01 by gbrittan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
    if (s == NULL)
        return (NULL);
    while (*s != '\0' && *s != (char)c)
        s++;
    if (*s == c)
        return ((char*)s);
    return (NULL);
}
