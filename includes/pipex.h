/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjupy <gjupy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 21:57:07 by gjupy             #+#    #+#             */
/*   Updated: 2022/08/12 19:19:16 by gjupy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>
# include <stdbool.h>
# include <errno.h>
# include "../libs/libft/libft.h"
# include "../get_next_line/get_next_line.h"

typedef struct s_pipex
{
	int		fd[2];
	pid_t	*pids;
	int		childs;
	int		**pipes;
	int		nbr_of_pipes;
	int		pipe_read;
	int		pipe_write;
	int		infile;
	int		outfile;
	char	*path;
	char	**pathnames;
	char	**cmd_args;
	char	*command;
	char	*delimiter;
	int		status;
	bool	here_doc;
}	t_pipex;

enum	e_file {in, out};
void	find_path_line_and_split(char **env, t_pipex *pipex);
int		get_cmd(t_pipex *pipex);
void	close_files_and_pipes(t_pipex *pipex);
int		close_pipes(t_pipex *pipex, int child_nbr);
void	open_file(char **argv, t_pipex *pipex, int file);
void	close_files(t_pipex *pipex);

void	free_arr(int **arr, int len);
void	free_pipes(int ***arr, int len);
void	free_pathnames(t_pipex *pipex);
void	free_cmd_args(t_pipex *pipex);

void	create_pipes_arr(t_pipex *pipex);

void	create_child_prcs(t_pipex *pipex, char **argv, char **env);

void	child_wait_pid(t_pipex *pipex);

bool	is_space(char c);
bool	str_of_spaces(char *argv);
bool	is_here_doc(t_pipex *pipex, char **argv);
int		check_cmd_strs(char **s, t_pipex *pipex);
void	input_err_check(t_pipex *pipex, int argc, char **argv);
void	cmd_err(t_pipex *pipex);
void	input_err(char *msg);
void	malloc_err(void);
void	malloc_err2(t_pipex *pipex);
void	malloc_err3(t_pipex *pipex);
void	malloc_err4(t_pipex *pipex);
void	err(char *msg);
void	fork_err(t_pipex *pipex);
void	dup2_err(t_pipex *pipex);
void	execve_err(t_pipex *pipex);
void	file_err(t_pipex *pipex, int file);

#endif