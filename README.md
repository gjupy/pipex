# pipex
---
### pipex 42 cursus
- Result: 125%

This is a project to reproduce the shell behavior of redirecting STDIN and STDOUT to files and emulating pipes.

#### How to run?
Execute command make and type the command listed below. The arguments will be processed as same as < infile cmd1 | cmd2 | cmd3 | ... cmdn > outfile on the shell.

> ./pipex infile cmd1 cmd2 cmd3 ... cmdn outfile

The programm also supports « and » when the first argument is "here_doc". This will work similarly to a sequence of commands executed in the shell, for example: cmd << STOP | cmd1 | cmd2 | cmd3 | ... cmdn >> outfile.
For this, the first argument must be set here_doc, as in the example below.

> ./pipex here_doc DELIMITER cmd1 cmd2 cmd3 ... cmdn outfile

[![forthebadge](https://forthebadge.com/images/badges/made-with-c.svg)](https://forthebadge.com)
