/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaroi <cbaroi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 08:32:13 by cbaroi            #+#    #+#             */
/*   Updated: 2024/03/15 09:00:16 by cbaroi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	return(1);
}

int	ft_error(char *str, int exit_code)
{
	if (str)
	{
		write(2, str, ft_strlen(str));
		write(2, "\n", 1);
	}
	else
		perror("ERROR");
	exit(exit_code);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n<= 0)
		return (0);
	while (i < n && s1[i] == s2[i] && (s1[i] || s2[i]))
		i++;
	if (i == n)
		return ((unsigned char)s1[i - 1] - (unsigned char)s2[i - 1]);
	else
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char	*ft_strdup(const char *s)
{
	char	*dst;
	int		i;

	dst = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (dst == NULL)
		return (NULL);
	i = -1;
	while (s[++i])
		dst[i] = s[i];
	dst[i] = '\0';
	return (dst);
}

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = ft_strlen(s);
	while (len >= 0)
	{
		if ((unsigned char)s[len] == (unsigned char)c)
			return ((char *)s + len);
		len--;
	}
	return (NULL);
}