/*
** EPITECH PROJECT, 2023
** wJson
** File description:
** index_static
*/

#include "wjson.h"

wbool is_none(char c)
{
    if (c == '\n')
        return WTRUE;
    if (c == '\t')
        return WTRUE;
    if (c == ' ')
        return WTRUE;
    return WFALSE;
}

int index_static(int _manage_var, char *buffer)
{
    static int index = 0;

    if (_manage_var == ADVANCE_ONE_CHAR) {
        index++;
        return index;
    }
    if (_manage_var == GET)
        return index;
    if (_manage_var == ADVANCE_ALL) {
        while (is_none(buffer[index]))
            index++;
        return index;
    }
    return 0;
}

void skip_index(char *_buffer, char c)
{
    while (_buffer[INDEX] != c)
        ADD(_buffer);
}