/*
** EPITECH PROJECT, 2023
** wJson
** File description:
** wjson
*/

#ifndef WJSON_H_
    #define WJSON_H_

    /* [USE] */
    #include "wjson_types.h"
    #include "wjson_tools.h"
    #include "wjson_macros.h"
    /* _____ */

    void *wjson_parse(char *path);
    wjson_dictionary_t *wjson_get_dictionary(char *_wjson_buffer);
    wjson_list_t *wjson_get_list(char *_wjson_buffer);
    char *wjson_get_string(char *_wjson_buffer);
    char *wjson_get_int_value(char *_wjson_buffer);

    wjson_dictionary_t *wjson_dictionary_create(void);
    void wjson_dictionary_add_node(wd_t *_main,char *_key_add, char *_value_add);
    void wjson_display_dictionary(wd_t *_main);
    char *wget_v(char *_wjson_buffer);
    void wjson_display_list(wl_t *_main);
    void wdict_add_dictionary(wd_t *_main, char *_temp_key, wd_t *_to_add);
    wjson_list_t *wjson_get_list(char *_wjson_buffer);
    void wdict_add_list(wd_t *_main, char *_temp_key, wl_t *_to_add);
    void wlist_add_node(wl_t *_main, char *_value_add);
    wjson_list_t *wjson_list_create(void);
    void wlist_add_dictionary(wl_t *_main, wd_t *_to_add);
    void wlist_add_list(wl_t *_main, wl_t *_to_add);


    char *wjson_get_buffer(wjson_buffer_t *_buffer);
    wjson_buffer_t *wjson_buffer_create(void);

#endif /* !WJSON_H_ */
