#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"
/*
void create_file(const char *filename, const char *content)
{
    int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0)
    {
        perror("Error creating file");
        return;
    }
    write(fd, content, ft_strlen(content));
    close(fd);
}
*/
/*int main()
{
    // Crear archivo vacío
    create_file("empty.txt", "");

    // Crear archivo con un solo carácter
    create_file("1char.txt", "A\n");

    // Crear archivo sin salto de línea al final
    create_file("no_newline.txt", "Hello World");

    // Crear archivo con múltiples saltos de línea
    create_file("multiple_newlines.txt", "\n\n\n\n");

    // Crear archivo pequeño (5 caracteres)
    create_file("small.txt", "abcde");

    // Crear archivo muy grande (1GB)
    FILE *bigfile = fopen("bigfile.txt", "w");
    if (bigfile != NULL)
    {
        for (size_t i = 0; i < 1000000000; ++i) // Aproximadamente 1GB de datos
        {
            fputc('a', bigfile);
        }
        fclose(bigfile);
    }
    else
    {
        perror("Error creating bigfile.txt");
    }

    printf("Archivos de prueba creados con éxito.\n");

    return 0;
}
*/