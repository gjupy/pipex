/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjupy <gjupy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 18:17:39 by gjupy             #+#    #+#             */
/*   Updated: 2022/08/12 18:40:05 by gjupy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	free_pipes(int ***arr, int len)
{
	while (len >= 0)
	{
		free((*arr)[len]);
		len--;
	}
	free(*arr);
}

void	free_arr(int **arr, int len)
{
	while (len >= 0)
	{
		free(arr[len]);
		len--;
	}
}

void	free_pathnames(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (pipex->pathnames && pipex->pathnames[i])
	{
		free(pipex->pathnames[i]);
		i++;
	}
	free(pipex->pathnames);
}

void	free_cmd_args(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (pipex->cmd_args[i])
	{
		free(pipex->cmd_args[i]);
		i++;
	}
	free(pipex->cmd_args);
}
