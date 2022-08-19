/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjupy <gjupy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 17:32:44 by aiarinov          #+#    #+#             */
/*   Updated: 2022/08/12 21:13:07 by gjupy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

void	input_err_check(t_pipex *pipex, int argc, char **argv)
{
	if (argc > 1)
		is_here_doc(pipex, argv);
	if (argc < 5)
		input_err("HOW TO RUN PIPEX:\
 ./pipex infile 'cmd1 args' 'cmd2 args' ... outfile\n");
	if (pipex->here_doc == true && argc < 6)
		input_err("HOW TO RUN PIPEX WITH HERE_DOC:\
 ./pipex here_doc LIMITER 'cmd1 args' 'cmd2 args' ... outfile\n");
	if (check_cmd_strs(argv, pipex) == -1)
		input_err("argument should not be empty\n");
}

void	cmd_err(t_pipex *pipex)
{
	write(STDERR_FILENO, "\033[31mERROR 🙁\n\033[0m", 21);
	write(STDERR_FILENO, "command not found: ", 20);
	write(STDERR_FILENO, pipex->cmd_args[0], ft_strlen(pipex->cmd_args[0]));
	write(STDERR_FILENO, "\n", 1);
	free_cmd_args(pipex);
	if (pipex->pathnames != NULL)
		free_pathnames(pipex);
	exit(EXIT_FAILURE);
}

void	input_err(char *msg)
{
	write(STDERR_FILENO, "\033[31mERROR 🙁\n\033[0m", 21);
	write(STDERR_FILENO, msg, ft_strlen(msg));
	exit(EXIT_FAILURE);
}

void	err(char *msg)
{
	write(STDERR_FILENO, "\033[31mERROR 🙁\n\033[0m", 21);
	perror(msg);
	exit(EXIT_FAILURE);
}

void	execve_err(t_pipex *pipex)
{
	free_cmd_args(pipex);
	if (pipex->pathnames != NULL)
		free_pathnames(pipex);
	free(pipex->command);
	free_pipes(&pipex->pipes, pipex->nbr_of_pipes - 1);
	write(STDERR_FILENO, "\033[31mERROR 🙁\n\033[0m", 21);
	perror("failed to execute");
	exit(EXIT_FAILURE);
}
