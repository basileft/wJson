/*
** EPITECH PROJECT, 2023
** wJson
** File description:
** wjson_macros
*/

#pragma once

#include "wjson_types.h"
#include "wjson.h"

/* STREAM MANAGEMENT */
int wjson_stream_index(wbool ADD);
void wjson_skip(char * _wjson_buffer, char *_PATTERN);
void wjson_skip_white_space(char *_wjson_buffer);
#define GET wjson_stream_index(WTRUE)
#define GET_TMP wjson_stream_index(WFALSE)
#define _STREAM(__buff__) (__buff__[GET])
#define _SKIP(__buff__, _PATTERN) (wjson_skip(__buff__, _PATTERN))
#define _SKIPWS(__buff__) (wjson_skip_white_space(__buff__))
/*  ________________________ */


wjson_buffer_t *wjson_buffer_add_char(wjson_buffer_t *_previous, char _c);
#define WBUFFER_ADD(_self, _char) _self = wjson_buffer_add_char(_self, _char);

wbool is_digit(char _c);
#define WTRUE ((wbool)1)
#define WFALSE ((wbool)0)
#define DIGIT(_C) (is_digit(_C))
#define STRING(_C) (_C == '"' ? WTRUE : WFALSE)

#define NONE ((int)-1)
#define WBEGIN_ELEMENT "{["

