/*
** EPITECH PROJECT, 2023
** wJson
** File description:
** manage_buffers
*/

#include "wjson.h"
#include <stdlib.h>

wjson_buffer_t *wjson_buffer_create(void)
{
    wjson_buffer_t *_ret = malloc(sizeof(wjson_buffer_t));
    _ret->_c = '\0';
}

wjson_buffer_t *wjson_buffer_add_char(wjson_buffer_t *_previous, char _c)
{
    wjson_buffer_t *_ret = malloc(sizeof(wjson_buffer_t));
    _ret->_c = _c;
    _ret->_next_element = _previous;
    return _ret;
}

char *wjson_get_buffer(wjson_buffer_t *_buffer)
{
    wjson_buffer_t *_ptr = _buffer;
    size_t _size = 0;
    char *_ret = NULL;

    for (; _ptr->_c; _size++)
        _ptr = _ptr->_next_element;
    if (_size == 0)
        return NULL;
    _ret = malloc(sizeof(char) * _size);
    for (int i = _size - 1; i >= 0; i--) {
        _ptr = _buffer;
        _ret[i] = _buffer->_c;
        _buffer = _buffer->_next_element;
        free(_ptr);
    }
    return _ret;
}