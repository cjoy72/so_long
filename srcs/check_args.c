/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaroi <cbaroi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:17:46 by cbaroi            #+#    #+#             */
/*   Updated: 2024/05/01 21:11:24 by cbaroi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	ft_error(char *str, int status)
{
	printf("%s", str);
	exit(status);
}

void	ft_file_check(char *file)
{
	int	fd;

	if (open(argv, __O_DIRECTORY) >= 0)
		ft_error("Error\nInvalid file, probably a folder given\n", 1);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error("Error\nInvalid file, cannot read\n", 1);
	close(fd);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while ((*s1 == *s2) && n - 1 > 0 && *s1 != '\0' && *s2 != '\0')
	{
		s1++;
		s2++;
		n--;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	return (i);
}

void	check_args(int argc, char **argv)
{
	if (argc != 2)
		ft_error("Error\nInvalid number of arguments\n", 1);
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4))
		ft_error("Error\nInvalid file extension\n", 1);
	ft_file_check(argv[1]);
}
