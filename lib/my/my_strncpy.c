/*
** EPITECH PROJECT, 2023
** my_strncpy.c
** File description:
** Copies n characters from a string into another. The destination string
** will already have enough memory to contain n characters.
*/

int my_strlen(char const *str);

char *my_strncpy(char *dest, char const *src, unsigned int n)
{
    unsigned int len = my_strlen(src);

    for (unsigned int i = 0; i <= len && i < n; i++)
        dest[i] = src[i];
    return dest;
}
