/*
** EPITECH PROJECT, 2023
** wJson
** File description:
** test
*/

#include "wjson.h"
#include <stdio.h>

#define A(_C, _A) _C = _A

int main(int ac, char **av)
{
    wjson_parse(av[1]);
}