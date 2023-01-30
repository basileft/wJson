/*
** EPITECH PROJECT, 2023
** wJson
** File description:
** wjson_get_dictionary
*/

#include "wjson.h"
#include <stdio.h>

wjson_dictionary_t *wjson_get_dictionary(char *_wjson_buffer)
{
    wjson_dictionary_t *_ret = wjson_dictionary_create();
    char *_temp_key = NULL;

    do {
        SKIP_TO(_wjson_buffer, '"');
        _temp_key = wjson_get_string(_wjson_buffer);
        SKIP_TO(_wjson_buffer, ':');
        ADD_SKIP(_wjson_buffer);
        if (DIGIT(_wjson_buffer[INDEX]) || _wjson_buffer[INDEX] == '"')
            wjson_dictionary_add_node(_ret, _temp_key, wget_v(_wjson_buffer));
    } while (_wjson_buffer[INDEX] == ',');
    wjson_display_dictionary(_ret);
    return NULL;
}