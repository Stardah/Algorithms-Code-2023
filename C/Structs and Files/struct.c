#include <stdbool.h>
#include <stdio.h>

#define SIZE 10
typedef int (*matrix_row)[SIZE];

void func(void) {
    int matrix[10][10];
    matrix_row row = matrix;
    return row;
    // int *rows[10];
}

typedef struct homework {
    char *book_name;
    int page_number;
} Homework;

struct subject {
    char name[20];
    int difficulty;
    float hours;
    struct homework hw;
} subject; // глобальная инициализированная переменная

struct student {
    char name[20]; // 16 + 4 + (4)
    int group;     // 4 + (4)
    char city[20]; // 16 + 4 + (4)

    // bool(struct subject *sbj_ptr)* study;
    bool (*study)(struct subject *sbj_ptr); // 8

    enum Language { C = 1,
                    Go,
                    CPP,
                    Java = 20,
                    CSharp,
                    Python } lang; // 4 + (4)

    char flexible_array_member[]; // 8
} student, *ptr;                  // 80 байт

bool study(struct subject *sbj_ptr) {
    sbj_ptr->hours += sbj_ptr->difficulty / 60.0;
    return true;
}

void print_homework(const struct homework *hw) {
    printf("Book: %s \nPage: %d", hw->book_name, hw->page_number);
}

void print_subject(const struct subject *s) {
    printf("Name: %s \nDifficulty: %d \nHours: %f\n", s->name, s->difficulty, s->hours);
    printf("Homework: {\n");
    print_homework(&(s->hw));
    printf("\n}\n");
}

int main(int argc, char const *argv[]) {
    // struct student st = {"Смирнов П.В.", 104, "Калуга"};
    char arr[20] = "Смиронов"; // Это работает
    // struct student st = {.name = "Смирнов"}; // А это нет

    struct student st = {.name = "Smirnov", .city = "Moscow", .group = 10};
    // struct student *st_p = malloc(sizeof(struct student) * 1);
    struct student *st_p = &st;

    st.lang = 39825;
    st.name;
    st_p->name;
    (*st_p).name;

    st.study = study;
    st.lang = Java;

    struct homework hw = {"WorkBook", 45};
    struct subject sbj = {"Algorithms", 7, 0, hw};
    struct subject *sbj_ptr = &sbj;

    (&sbj)->hw.book_name;
    sbj_ptr->hw.book_name;

    st.study(&sbj);

    print_subject(&sbj);

    return 0;
}
