/*
** EPITECH PROJECT, 2023
** wJson
** File description:
** wjson_macros
*/

#ifndef WJSON_MACROS_H_
    #define WJSON_MACROS_H_

    #include "wjson_types.h"

    /* [STATIC INDEX MANAGEMENT]*/
    int index_static(int _manage_var, char *buffer);
    void skip_index(char *_buffer, char c);
    #define ADVANCE_ONE_CHAR ((int)1)
    #define ADVANCE_ALL ((int)0)
    #define ADD(__buff__) (index_static(ADVANCE_ONE_CHAR, __buff__))
    #define SKIP(__buff__) (index_static(ADVANCE_ALL, __buff__))
    #define ADD_SKIP(__buff__) (ADD(__buff__), SKIP(__buff__))
    #define GET ((int)-1)
    #define INDEX (index_static(GET, ""))
    #define SKIP_TO(__buff__, _C) (skip_index(__buff__, _C))
    /*  ________________________ */


    wbool is_digit(char _c);
    #define WTRUE ((wbool)1)
    #define WFALSE ((wbool)0)
    #define DIGIT(_C) (is_digit(_C))
    #define STRING(_C) (_C == '"' ? WTRUE : WFALSE)

    #define NONE ((int)-1)

#endif /* !WJSON_MACROS_H_ */
