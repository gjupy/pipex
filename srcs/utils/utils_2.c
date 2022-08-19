/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjupy <gjupy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 17:18:29 by gjupy             #+#    #+#             */
/*   Updated: 2022/08/12 21:12:31 by gjupy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

void	child_wait_pid(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->childs)
	{
		waitpid(pipex->pids[i], &pipex->status, 0);
		i++;
	}
	pipex->status = pipex->status >> 8;
	pipex->status = pipex->status & 0x000000ff;
}

void	close_files(t_pipex *pipex)
{
	close(pipex->outfile);
	close(pipex->infile);
}
