#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
/**
 * append_text_to_file - Appends text at the end of a file.
 * @filename: A pointer that points to the name of the file.
 * @text_content: A pointer to a string to append to the file.
 *
 * Return: 1 on success, -1 on failure.
 */
int append_text_to_file(const char *filename, char *text_content)
{
    int fd;                /* File descriptor */
    ssize_t bytesWritten;  /* Number of bytes written */

    if (filename == NULL)
        return -1; /* If filename is NULL, return -1 indicating an error */

    fd = open(filename, O_WRONLY | O_APPEND);
    if (fd == -1)
        return -1; /* If opening the file fails, return -1 indicating an error */

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

