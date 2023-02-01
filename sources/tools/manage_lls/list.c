/*
** EPITECH PROJECT, 2023
** wJson
** File description:
** list
*/

#include "wjson.h"
#include <unistd.h>
#include <stdio.h>

void wjson_display_list(wl_t *_main)
{
    wlist_element_t *_ptr = _main->begin;
    wputstr("new list: \n");

    for (int i = 0; i < _main->size; i++) {
        if (_ptr->depend_list)
            wjson_display_list(_ptr->depend_list);
        if (_ptr->depend_dictionary)
            wjson_display_dictionary(_ptr->depend_dictionary);
        if (!_ptr->depend_dictionary && !_ptr->depend_list)
            wputstr(wstrconcat(_ptr->data.value, "\n"));
        _ptr = _ptr->_next_element;
    }
}

void wlist_add_node(wl_t *_main, char *_value_add)
{
    wlist_element_t *_ptr = _main->begin;

    for (int i = 0; i < _main->size; i++)
        _ptr = _ptr->_next_element;
    _main->size++;
    _ptr->data.value = _value_add;
    _ptr->depend_dictionary = NULL;
    _ptr->depend_list = NULL;
    _ptr->_next_element = malloc(sizeof(wlist_element_t));
}

void wlist_add_list(wl_t *_main, wl_t *_to_add)
{
    wlist_element_t *_ptr = _main->begin;

    for (int i = 0; i < _main->size; i++)
        _ptr = _ptr->_next_element;
    _main->size++;
    _ptr->data.value = NULL;
    _ptr->depend_dictionary = NULL;
    _ptr->depend_list = _to_add;
    _ptr->_next_element = malloc(sizeof(wlist_element_t));
}

void wlist_add_dictionary(wl_t *_main, wd_t *_to_add)
{
    wlist_element_t *_ptr = _main->begin;

    for (int i = 0; i < _main->size; i++)
        _ptr = _ptr->_next_element;
    _main->size++;
    _ptr->data.value = NULL;
    _ptr->depend_dictionary = _to_add;
    _ptr->depend_list = NULL;
    _ptr->_next_element = malloc(sizeof(wlist_element_t));
}

wjson_list_t *wjson_list_create(void)
{
    wjson_list_t *_ret = malloc(sizeof(wjson_list_t));

    _ret->prototype = NULL;
    _ret->begin = malloc(sizeof(wlist_element_t));
    _ret->size = 0;
    return _ret;
}
