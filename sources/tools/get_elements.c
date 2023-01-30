/*
** EPITECH PROJECT, 2023
** wJson
** File description:
** get_elements
*/

#include "wjson.h"
#include <stdlib.h>

char *wget_v(char *_wjson_buffer)
{
    char *_temp_value = NULL;

    if (DIGIT(_wjson_buffer[INDEX]))
        return wjson_get_int_value(_wjson_buffer);
    if (STRING(_wjson_buffer[INDEX]))
        return wjson_get_string(_wjson_buffer);
    return NULL;
}

char *wjson_get_string(char *_wjson_buffer)
{
    size_t _size = 0;
    char *_ret = NULL;

    ADD(_wjson_buffer);
    while (_wjson_buffer[_size + INDEX] != '"')
        _size++;
    _ret = malloc(sizeof(char) * _size);
    for (int i = 0; i < _size; i++, ADD(_wjson_buffer))
        _ret[i] = _wjson_buffer[INDEX];
    ADD(_wjson_buffer);
    return _ret;
}

char *wjson_get_int_value(char *_wjson_buffer)
{
    size_t _size = 0;
    char *_ret = NULL;

    while (DIGIT(_wjson_buffer[_size + INDEX]))
        _size++;
    _ret = malloc(sizeof(char) * _size);
    for (int i = 0; i < _size; i++, ADD(_wjson_buffer))
        _ret[i] = _wjson_buffer[INDEX];
    ADD(_wjson_buffer);
    return _ret;
}