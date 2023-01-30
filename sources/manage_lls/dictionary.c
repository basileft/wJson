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

    for (int i = 0; i < _main->size; i++) {
        printf("cc\n");
        wputstr(wstrconcat(_ptr->key, " : "));
        wputstr(_ptr->data.value);
        _ptr = _ptr->_next_element;
    }
}

void wjson_dictionary_add_node(wd_t *_main, char *_key_add, char *_value_add)
{
    wdictionary_element_t *_ptr = _main->begin;

    for (int i = 0; i < _main->size; i++)
        _ptr = _ptr->_next_element;
    printf("ff\n");
    _main->size++;
    _ptr = malloc(sizeof(wlist_element_t));
    _ptr->key = _key_add;
    _ptr->data.value = _value_add;
    _ptr->_next_element = NULL;
}

wjson_dictionary_t *wjson_dictionary_create(void)
{
    wjson_dictionary_t *_ret = malloc(sizeof(wjson_dictionary_t));

    _ret->prototype = NULL;
    _ret->begin = NULL;
    _ret->size = 0;
    return _ret;
}