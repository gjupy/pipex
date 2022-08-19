/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_malloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjupy <gjupy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 18:49:25 by gjupy             #+#    #+#             */
/*   Updated: 2022/08/12 21:12:52 by gjupy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

void	malloc_err(void)
{
	write(STDERR_FILENO, "\033[31mERROR 🙁\n\033[0m", 21);
	perror("failed to allocate mem");
	exit(EXIT_FAILURE);
}

void	malloc_err2(t_pipex *pipex)
{
	free_cmd_args(pipex);
	if (pipex->pathnames != NULL)
		free_pathnames(pipex);
	free_pipes(&pipex->pipes, pipex->nbr_of_pipes - 1);
	write(STDERR_FILENO, "\033[31mERROR 🙁\n\033[0m", 21);
	perror("failed to allocate mem");
	exit(EXIT_FAILURE);
}

void	malloc_err3(t_pipex *pipex)
{
	free_cmd_args(pipex);
	free_pathnames(pipex);
	free_pipes(&pipex->pipes, pipex->nbr_of_pipes - 1);
	write(STDERR_FILENO, "\033[31mERROR 🙁\n\033[0m", 21);
	perror("failed to allocate mem");
	exit(EXIT_FAILURE);
}

void	malloc_err4(t_pipex *pipex)
{
	free_cmd_args(pipex);
	free_pathnames(pipex);
	free_pipes(&pipex->pipes, pipex->nbr_of_pipes - 1);
	write(STDERR_FILENO, "\033[31mERROR 🙁\n\033[0m", 21);
	perror("failed to allocate mem");
	exit(EXIT_FAILURE);
}
