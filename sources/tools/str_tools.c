/*
** EPITECH PROJECT, 2023
** wJson
** File description:
** str_tools
*/

#include "wjson.h"
#include <unistd.h>

size_t wstrlen(char *_str)
{
    int _ret = 0;
    while (_str[_ret])
        _ret++;
    return _ret;
}

void wputstr(char *_str)
{
    write(1, _str, wstrlen(_str));
}

wbool is_digit(char _c)
{
    if (_c >= 48 && _c <= 58)
        return WTRUE;
    if (_c == '-')
        return WTRUE;
    if (_c == '.')
        return WTRUE;
    return WFALSE;
}

char *wstrconcat(char *_original, char *_to_add)
{
    size_t _size = wstrlen(_original) + wstrlen(_to_add);
    size_t _index = 0;
    char *_ret = malloc(sizeof(char) * _size);
    for (int i = 0; _original[i]; _index++, i++)
        _ret[_index] = _original[i];
    for (int i = 0; _to_add[i]; _index++, i++)
        _ret[_index] = _to_add[i];
    return _ret;
}