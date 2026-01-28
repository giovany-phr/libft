/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:05:37 by gpaupher          #+#    #+#             */
/*   Updated: 2024/01/30 18:34:20 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/get_next_line.h"

char	*ft_strjoin_gnl(char *save, char *buff)
{
	char		*ptr;
	size_t		total;
	size_t		i;
	size_t		j;	

	i = 0;
	j = 0;
	total = ft_strlen(save) + ft_strlen(buff);
	ptr = (char *) malloc(sizeof(char) * (total + 1));
	if (!ptr || !save || !buff)
		return (NULL);
	while (save[i] != 0)
	{
		ptr[i] = save[i];
		i++;
	}
	while (buff[j] != 0)
		ptr[i++] = buff[j++];
	ptr[total] = 0;
	free(save);
	return (ptr);
}
