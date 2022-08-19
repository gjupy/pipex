/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjupy <gjupy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 18:52:14 by gjupy             #+#    #+#             */
/*   Updated: 2022/08/12 21:12:46 by gjupy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

void	fork_err(t_pipex *pipex)
{
	write(STDERR_FILENO, "\033[31mERROR 🙁\n\033[0m", 21);
	free(pipex->pids);
	perror("failed to create child process");
	exit(EXIT_FAILURE);
}

void	file_err(t_pipex *pipex, int file)
{
	if (file == in)
		err("failed to open infile");
	else if (file == out)
		err("failed to open outile");
	free_pipes(&pipex->pipes, pipex->nbr_of_pipes - 1);
}
