/*
** EPITECH PROJECT, 2023
** wJson
** File description:
** wjson_pars_main
*/

#include "wjson.h"
#include <stdio.h>

void *wjson_parse(char *path)
{
    char *_wjson_buffer = NULL;
    char _tmp_c;
    void *_ret_json = NULL;

    if ((_wjson_buffer = get_file_content(path)) == NULL)
        return NULL;
    _SKIPWS(_wjson_buffer);
    _tmp_c = _wjson_buffer[GET_TMP];
    printf("%c\n", _tmp_c);
    if (_tmp_c == '{')
        _ret_json = wjson_get_dictionary(_wjson_buffer);
    if (_tmp_c == '[')
        _ret_json = wjson_get_list(_wjson_buffer);
    return _ret_json;
}