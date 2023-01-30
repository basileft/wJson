/*
** EPITECH PROJECT, 2023
** B-CPE-110-LYN-1-1-antman-vivien.boitard
** File description:
** get_file_content
*/

#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include "wjson.h"

char *get_file_content(char *path)
{
    struct stat st;
    char *buffer = NULL;
    int file = 0;

    if (stat(path, &st) == NONE)
        return NULL;
    buffer = malloc(sizeof(char) * st.st_size);
    if ((file = open(path, O_RDONLY)) == NONE)
        return NULL;
    if (read(file, buffer, st.st_size) == NONE)
        return NULL;
    return buffer;
}
