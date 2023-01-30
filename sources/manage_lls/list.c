/*
** EPITECH PROJECT, 2023
** wJson
** File description:
** list
*/

#include "wjson.h"
#include <unistd.h>

void wjson_display_list(wl_t *_main)
{
    wlist_element_t *_ptr = _main->begin;

    while (_ptr != NULL) {
        wputstr(_ptr->data.value);
        _ptr = _ptr->_next_element;
    }
}

void wjson_list_add_node(wl_t *_main, char *_value_add)
{
    wlist_element_t *_ptr = _main->begin;

    while (_ptr != NULL)
        _ptr = _ptr->_next_element;
    _ptr = malloc(sizeof(wlist_element_t));
    _ptr->data.value = _value_add;
    _ptr->_next_element = NULL;
}

wjson_list_t *wjson_list_create(void)
{
    wjson_list_t *_ret = malloc(sizeof(wjson_list_t));

    _ret->prototype = NULL;
    _ret->begin = NULL;
    _ret->size = 0;
    return _ret;
}