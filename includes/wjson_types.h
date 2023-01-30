/*
** EPITECH PROJECT, 2023
** wJson
** File description:
** wjson
*/

#ifndef WJSON_TYPES_H_
    #define WJSON_TYPES_H_

    #include <stdlib.h>

    struct list_element {
        struct list_element *_next_element;
        union {
            char *value;
            struct list *depend_list;
            struct dictionary *depend_dictionary;
        } data;
    };

    struct dictionary_element {
        struct dictionary_element *_next_element;
        char *key;
        union {
            char *value;
            struct list *depend_list;
            struct dictionary *depedn_dictionary;
        } data;
    };

    struct list_methods {
        char *(*encode_prototype)(void *);
        void (*destroy_prototype)(void *);
    };

    struct dictionary_methods {
        char *(*encode_prototype_keys)(void *);
        char *(*encoade_prototype_values)(void *);
        void (*destroy_prototype)(void *);
    };

    struct list {
        struct list_element *begin;
        size_t size;
        void *prototype;
        struct list_methods methods;
    };

    struct dictionary {
        struct dictionary_element *begin;
        size_t size;
        void *prototype;
        struct dictionary_methods methods;
    };

    typedef struct list_element wlist_element_t;
    typedef struct list_element wle_t;
    typedef struct dictionary_element wdictionary_element_t;
    typedef struct dictionary_element wde_t;
    typedef struct list wjson_list_t;
    typedef struct list wl_t;
    typedef struct dictionary wjson_dictionary_t;
    typedef struct dictionary wd_t;
    // typedef void *wjson_t;
    typedef int wbool;

#endif /* !WJSON_TYPES_H_ */
