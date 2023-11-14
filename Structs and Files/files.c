#include <stdio.h>

#define FILE_NAME "text.txt"

int main(int argc, char const *argv[]) {
    /* FILE *fopen(const char *filename, const char *mode); - открывает файл, return value: ​0​ on success, EOF otherwise */

    /* mode:
        r - read
        w - write
        a - append

        r+ - чтeние и запись
        w+ - чтeние и запись (создаёт новый файл, если требуется)
        a+ - чтeние и запись (переходит сразу в конец файла)

        rb, wb, ab, rb+, wb+, ab+ - для работы с бинарными файлами
    */

    /* int fclose(FILE *stream); - закрывает файл */

    /* FILE *freopen (const char *filename, const char *mode, FILE *stream);
        freopen = fclose + fopen
    */

    FILE *file = fopen(FILE_NAME, "w");

    fprintf(file, "Hello, file!");

    fclose(file);

    file = fopen(FILE_NAME, "r");

    char ch;
    while (fscanf(file, "%c", &ch) == 1) {
        printf("%c", ch);
    }

    fclose(file);

    /*
        int fscanf ( FILE *f , const char * format , ...);
        int fprintf ( FILE *f , const char * format , ...);
        int fgetc ( FILE * f );
        int fputc ( int c , FILE * f );
        char * fgets ( char *s , int n , FILE * f );
        int fputs ( char *s , FILE * f );
     */

    return 0;
}
