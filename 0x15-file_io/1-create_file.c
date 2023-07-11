#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

/**
 * create_file - Creates a file.
 * @filename: A pointer that points to the name of the file to create.
 * @text_content: A pointer to a string to write to the file.
 *
 * Return: If the function fails, return -1.
 *         Otherwise return 1.
 */

int create_file(const char *filename, char *text_content)
{
    int fd;                /* File descriptor */
    ssize_t bytesWritten;  /* Number of bytes written */

    if (filename == NULL)
        return -1; /* If filename is NULL, return -1 indicating an error */

    fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
    if (fd == -1)
        return -1; /* If opening or creating the file fails, return -1 indicating an error */

    if (text_content != NULL)
    {
        bytesWritten = write(fd, text_content, strlen(text_content));
        if (bytesWritten == -1)
        {
            close(fd);
            return -1; /* If writing to the file fails, return -1 indicating an error */
        }
    }

    close(fd);
    return 1; /* Return 1 on success */
}

