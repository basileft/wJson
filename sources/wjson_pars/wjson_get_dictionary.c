/*
** EPITECH PROJECT, 2023
** wJson
** File description:
** wjson_get_dictionary
*/

#include "wjson.h"
#include <stdio.h>

char *wjson_get_key(char *_wjson_buffer)
{
    wjson_buffer_t *buffer = wjson_buffer_create();
    WBUFFER_ADD(buffer, 'c');
    WBUFFER_ADD(buffer, 'v');
    printf("%s\n", wjson_get_buffer(buffer));

    return " ";
}

wjson_dictionary_t *wjson_get_dictionary(char *_wjson_buffer)
{
    wjson_dictionary_t *_ret = wjson_dictionary_create();
    char *_tmp_key;

    _SKIPWS(_wjson_buffer);
    _tmp_key = wjson_get_key(_wjson_buffer);
    // printf("%s\n", _tmp_key);
    return _ret;
}
