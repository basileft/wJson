/*
** EPITECH PROJECT, 2023
** wJson
** File description:
** dictionary
*/

#include "wjson.h"
#include <stdio.h>

void wjson_display_dictionary(wd_t *_main)
{
    wdictionary_element_t *_ptr = _main->begin;
    wputstr("new dict: \n");

    for (int i = 0; i < _main->size; i++) {
        wputstr(wstrconcat(_ptr->key, " : "));
        if (_ptr->depend_list)
            wjson_display_list(_ptr->depend_list);
        if (_ptr->depend_dictionary)
            wjson_display_dictionary(_ptr->depend_dictionary);
        if (!_ptr->depend_dictionary && !_ptr->depend_list)
            wputstr(wstrconcat(_ptr->data.value, "\n"));
        _ptr = _ptr->_next_element;
    }
}

void wdict_add_list(wd_t *_main, char *_temp_key, wl_t *_to_add)
{
    wdictionary_element_t *_ptr = _main->begin;

    for (int i = 0; i < _main->size; i++)
        _ptr = _ptr->_next_element;
    _main->size++;
    _ptr->key = _temp_key;
    _ptr->depend_dictionary = NULL;
    _ptr->depend_list = _to_add;
    _ptr->data.value = NULL;
    _ptr->_next_element = malloc(sizeof(wdictionary_element_t));
}

void wdict_add_dictionary(wd_t *_main, char *_temp_key, wd_t *_to_add)
{
    wdictionary_element_t *_ptr = _main->begin;

    for (int i = 0; i < _main->size; i++)
        _ptr = _ptr->_next_element;
    _main->size++;
    _ptr->key = _temp_key;
    _ptr->depend_dictionary = _to_add;
    _ptr->depend_list = NULL;
    _ptr->data.value = NULL;
    _ptr->_next_element = malloc(sizeof(wdictionary_element_t));
}

void wjson_dictionary_add_node(wd_t *_main, char *_key_add, char *_value_add)
{
    wdictionary_element_t *_ptr = _main->begin;

    for (int i = 0; i < _main->size; i++)
        _ptr = _ptr->_next_element;
    _main->size++;
    _ptr->key = _key_add;
    _ptr->data.value = _value_add;
    _ptr->depend_dictionary = NULL;
    _ptr->depend_list = NULL;
    _ptr->_next_element = malloc(sizeof(wdictionary_element_t));
}

wjson_dictionary_t *wjson_dictionary_create(void)
{
    wjson_dictionary_t *_ret = malloc(sizeof(wjson_dictionary_t));

    _ret->prototype = NULL;
    _ret->begin = malloc(sizeof(wdictionary_element_t));
    _ret->size = 0;
    return _ret;
}
