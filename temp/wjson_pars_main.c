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
    char *_wjson_buffer_tmp;
    void *_ret_json = NULL;

    if ((_wjson_buffer = get_file_content(path)) == NULL)
        return NULL;
    SKIP(_wjson_buffer);
    if (_wjson_buffer[INDEX] == '{') {
        if ((_ret_json = wjson_get_dictionary(_wjson_buffer)) == NULL)
            return NULL;
    }
    if (_wjson_buffer[INDEX] == '[') {
        if ((_ret_json = wjson_get_list(_wjson_buffer)) == NULL)
            return NULL;
    }
    return _ret_json;
}