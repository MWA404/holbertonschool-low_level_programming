#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * error_exit - prints error and exits
 * @code: exit code
 * @msg: error message format
 * @arg: argument for message
 */
void error_exit(int code, char *msg, char *arg)
{
	dprintf(STDERR_FILENO, msg, arg);
	exit(code);
}

/**
 * close_fd - closes a fd and exits on failure
 * @fd: file descriptor to close
 */
void close_fd(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * copy_content - reads from fd_from and writes to fd_to
 * @fd_from: source file descriptor
 * @fd_to: destination file descriptor
 * @av: argument vector for error messages
 */
void copy_content(int fd_from, int fd_to, char **av)
{
	int rd, wr;
	char buf[1024];

	while ((rd = read(fd_from, buf, 1024)) > 0)
	{
		wr = write(fd_to, buf, rd);
		if (wr == -1)
		{
			close(fd_from);
			close(fd_to);
			error_exit(99, "Error: Can't write to %s\n", av[2]);
		}
	}
	if (rd == -1)
	{
		close(fd_from);
		close(fd_to);
		error_exit(98, "Error: Can't read from file %s\n", av[1]);
	}
}

/**
 * main - copies content of a file to another
 * @ac: argument count
 * @av: argument vector
 * Return: 0 on success
 */
int main(int ac, char **av)
{
	int fd_from, fd_to;

	if (ac != 3)
		error_exit(97, "Usage: cp file_from file_to\n", "");

	fd_from = open(av[1], O_RDONLY);
	if (fd_from == -1)
		error_exit(98, "Error: Can't read from file %s\n", av[1]);

	fd_to = open(av[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		close(fd_from);
		error_exit(99, "Error: Can't write to %s\n", av[2]);
	}

	copy_content(fd_from, fd_to, av);
	close_fd(fd_from);
	close_fd(fd_to);

	return (0);
}
