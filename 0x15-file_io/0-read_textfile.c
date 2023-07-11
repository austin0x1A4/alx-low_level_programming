#include "main.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * read_textfile- Read text file print to STDOUT.
 * @filename: text file being read
 * @letters: number of letters to be read
 * Return: w- actual number of bytes read and printed
 *        0 when function fails or filename is NULL.
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
    int fd;              /* File descriptor */
    char *buf;           /* Buffer for reading file content */
    ssize_t bytesRead;   /* Number of bytes read */
    ssize_t bytesWritten; /* Number of bytes written */

    if (filename == NULL)
        return 0; /* If filename is NULL, return 0 indicating an error */

    fd = open(filename, O_RDONLY);
    if (fd == -1)
        return 0; /* If opening the file fails, return 0 indicating an error */

    buf = malloc(sizeof(char) * (letters + 1)); /* Allocate memory for the buffer */
    if (buf == NULL)
    {
        close(fd);
        return 0; /* If memory allocation fails, return 0 indicating an error */
    }

    bytesRead = read(fd, buf, letters); /* Read up to 'letters' bytes from the file into the buffer */
    if (bytesRead == -1)
    {
        close(fd);
        free(buf);
        return 0; /* If reading the file fails, return 0 indicating an error */
    }

    bytesWritten = write(STDOUT_FILENO, buf, bytesRead); /* Write the content of the buffer to STDOUT */
    if (bytesWritten == -1 || bytesWritten != bytesRead)
    {
        close(fd);
        free(buf);
        return 0; /* If writing to stdout fails or doesn't write expected bytes, return 0 indicating an error */
    }

    close(fd); /* Close the file descriptor */
    free(buf); /* Free the buffer memory */
    return bytesRead; /* Return the number of bytes read */
}

