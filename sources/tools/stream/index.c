/*
** EPITECH PROJECT, 2023
** wJson
** File description:
** index_static
*/

#include "wjson.h"

int wjson_stream_index(wbool ADD)
{
    static int index = -1;

    if (ADD)
        index++;
    return index;
}

wbool _is_in(char _c, char *_PATTERN)
{
    for (int i = 0; _PATTERN[i]; i++) {
        if (_c == _PATTERN[i])
            return WTRUE;
    }
    return WFALSE;
}

void wjson_skip(char * _wjson_buffer, char *_PATTERN)
{
    int _index = GET;
    if (!_is_in(_wjson_buffer[GET], _PATTERN))
        wjson_skip(_wjson_buffer, _PATTERN);
}

void wjson_skip_white_space(char *_wjson_buffer)
{
    char _temp_char = _wjson_buffer[GET];
    if (_temp_char == ' ' || _temp_char == '\t' || _temp_char == '\n')
        wjson_skip_white_space(_wjson_buffer);
}