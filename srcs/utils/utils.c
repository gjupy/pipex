/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjupy <gjupy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 18:49:06 by gjupy             #+#    #+#             */
/*   Updated: 2022/08/13 18:03:38 by gjupy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

/*
opens in or out file, depending on the file var parameter
and if there is here-doc
*/
void	open_file(char **argv, t_pipex *pipex, int file)
{
	if (file == in)
	{
		pipex->fd[0] = open(argv[1], O_RDONLY);
		if (pipex->fd[0] == -1)
			file_err(pipex, in);
	}
	else if (file == out)
	{
		if (pipex->here_doc == false)
			pipex->fd[1] = open(argv[pipex->childs + 2],
					O_WRONLY | O_CREAT | O_TRUNC, 0777);
		else if (pipex->here_doc == true)
			pipex->fd[1] = open(argv[pipex->childs + 2],
						O_WRONLY | O_CREAT | O_APPEND, 0777);
		if (pipex->fd[1] == -1)
			file_err(pipex, out);
	}
}

char	*find_path_str(char **env)
{
	int	i;

	i = 0;
	if (env[i] == NULL)
		return (NULL);
	while (env[i] && ft_strncmp("PATH", env[i], 4))
		i++;
	if (env[i] == NULL)
		return (NULL);
	return (env[i] + 5);
}

void	find_path_line_and_split(char **env, t_pipex *pipex)
{
	pipex->path = find_path_str(env);
	if (pipex->path == NULL)
		pipex->pathnames = NULL;
	else
	{
		pipex->pathnames = ft_split(pipex->path, ':');
		if (pipex->pathnames == NULL)
			malloc_err();
	}
}

/*
checks if user entered the command pathname.
returns true if command exists
*/
bool	check_for_input_with_path(t_pipex *pipex)
{
	if (pipex->cmd_args[0][0] == '/')
	{
		if (access(*pipex->cmd_args, F_OK) == 0)
		{
			pipex->command = *pipex->cmd_args;
			return (true);
		}
		cmd_err(pipex);
	}
	return (false);
}

int	get_cmd(t_pipex *pipex)
{
	char	*tmp;
	int		i;

	i = 0;
	if (check_for_input_with_path(pipex) == true)
		return (0);
	while (pipex->pathnames && pipex->pathnames[i])
	{
		tmp = ft_strjoin(pipex->pathnames[i], "/");
		if (pipex->pathnames != NULL && tmp == NULL)
			malloc_err3(pipex);
		pipex->command = ft_strjoin(tmp, pipex->cmd_args[0]);
		free(tmp);
		if (pipex->pathnames != NULL && pipex->command == NULL)
			malloc_err3(pipex);
		if (access(pipex->command, F_OK) == 0)
			return (0);
		free(pipex->command);
		i++;
	}
	cmd_err(pipex);
	return (0);
}
