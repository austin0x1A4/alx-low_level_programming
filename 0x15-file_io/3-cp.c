#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

/**
 * error_exit - Print an error message and exit with the specified code.
 * @message: The error message to print.
 * @exit_code: The exit code.
 */
void error_exit(const char *message, int exit_code)
{
    dprintf(2, "%s\n", message);
    exit(exit_code);
}

/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of strings containing the command-line arguments.
 *
 * Return: 0 on success, or the appropriate error code.
 */
int main(int argc, char **argv)
{
    int file_from, file_to;
    ssize_t bytesRead, bytesWritten;
    char buffer[BUFFER_SIZE];

    if (argc != 3)
        error_exit("Usage: cp file_from file_to", 97);

    /* Open the source file for reading */
    file_from = open(argv[1], O_RDONLY);
    if (file_from == -1)
        error_exit("Error: Can't read from file", 98);

    /* Open the destination file for writing */
    file_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
    if (file_to == -1)
        error_exit("Error: Can't write to file", 99);

    /* Read from source file and write to destination file */
    while ((bytesRead = read(file_from, buffer, BUFFER_SIZE)) > 0)
    {
        bytesWritten = write(file_to, buffer, bytesRead);
        if (bytesWritten == -1)
            error_exit("Error: Can't write to file", 99);
    }

    if (bytesRead == -1)
        error_exit("Error: Can't read from file", 98);

    /* Close the file descriptors */
    if (close(file_from) == -1)
        error_exit("Error: Can't close file descriptor", 100);

    if (close(file_to) == -1)
        error_exit("Error: Can't close file descriptor", 100);

    return 0;
}

