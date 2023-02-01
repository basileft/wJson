/*
** EPITECH PROJECT, 2023
** wJson
** File description:
** wjson_get_list
*/

#include "wjson.h"
#include <stdio.h>

wjson_list_t *wjson_get_list(char *_wjson_buffer)
{
    wjson_list_t *_ret = wjson_list_create();

    do {
        ADD_SKIP(_wjson_buffer);
        if (DIGIT(_wjson_buffer[INDEX]) || _wjson_buffer[INDEX] == '"')
            wlist_add_node(_ret, wget_v(_wjson_buffer));
        if (_wjson_buffer[INDEX] == '{')
            wlist_add_dictionary(_ret, wjson_get_dictionary(_wjson_buffer));
        if (_wjson_buffer[INDEX] == '[')
            wlist_add_list(_ret, wjson_get_list(_wjson_buffer));
        ADD_SKIP(_wjson_buffer);
    } while (_wjson_buffer[INDEX] == ',');
    printf("list stop ->%c", _wjson_buffer[INDEX]);
    ADD_SKIP(_wjson_buffer);
    return _ret;
}
