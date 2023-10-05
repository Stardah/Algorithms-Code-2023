#include <stdio.h>

void do_something(void)
{
    printf("did something\n");
}

void print_i(int i)
{
    printf("i = %d\n", i);
}

void basic_expressions()
{
    int a = 5;
    int b = 10;

    // Простейшие операторы
    a = b;
    5 + 1;

    // Составной оператор {} группирует операторы
    {
        int b = 500;
        printf("%d", b);
    }

    // Условный оператор
    if (b > 100)
    {
        if (b == 10)
        {
            printf("b == 10\n");
        }
        else
        {
            printf("b > 100\n");
        }
    }
    else
    {
        printf("b <= 100\n");
    }
}

void test_switch()
{
    int b = 10;

    // Оператор Switch
    switch (b + 1) /* expression */
    {
        case 100: /* метка case с constant-expression */
            /* code */
            printf("b == 100\n");
            break;

        default: /* выполнится, если ни один case не подошёл */
            printf("default\n");
            break; /* оператор прекращения выполнения оператора */
    }
}

void test_loops()
{
    // while () {}
    while (0)
    {
        do_something();
    }

    // do {} while ();
    do
    {
        do_something();
    } while (0);

    // for
    for (int i = 0; i < 1; i++)
    {
        print_i(i);
    }

    for (int i = 0; i < 100; ++i)
    {
        print_i(i);
        break; // досрочный выход из цикла
    }

    for (int i = 0; i < 1; ++i)
    {
        continue; // переход к следующей итерации цикла
        print_i(i);
    }
}

void test_goto(void)
{
    int i, j;

    for (i = 0; i < 10; i++)
    {
        printf("Внешний цикл. i = %d\n", i);
        for (j = 0; j < 3; j++)
        {
            printf("Внутренний цикл. j = %d\n", j);
            if (i == 5) {
                goto stop;
            }
        }
    }

    /* Это сообщение не будет напечатано: */
    printf("Вышли из цикла. i = %d\n", i);

stop:
    printf("Прыгнули в stop. i = %d\n", i);
}

int main(void)
{

    /* Простые операции */
    basic_expressions();

    /* Switch */
    test_switch();

    /* Циклы */
    test_loops();

    /* goto */
    test_goto();

    return 0;
}
