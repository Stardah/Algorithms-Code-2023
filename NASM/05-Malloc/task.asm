; // FILE * get_stdin(void);
; // FILE * get_stdout(void);

; typedef struct list_t {
;     short key;
;     struct list_t *next;
; } list;

; (a) Напишите функцию list *read_list(void);, 
; которая считывает числа со стандартного потока
; ввода и строит из них список и сортирует его.

; (b) Напишите функцию void free_list(list *p);, 
; которая освобождает переданный ей список.