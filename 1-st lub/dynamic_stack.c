#include "dynamic_stack.h"
#include <stdlib.h>
#include <stdio.h>
int main(){
    stack *head = create();
    printf("1. Вывод текущего состояния стека на экран\n");
    printf("2. Добавление элемента в вершину стека\n ");
    printf("3. Добавление случайного числа элементов в стек.\n ");
    printf("4. Удаление элемента из стека.\n ");
    printf("5. Вывод текущего состояния вспомогательного стека на экран\n");
    printf("0. Выход из программы.\n ");
    menu(&head);
    destroy(&head);
    return 0;
}
void menu(stack ** root){
    /* 
    1. Вывод текущего состояния стека на экран.(• проверку пустоты стека, • вывод текущего состояния стека на экран)
    2.  Добавление элемента в вершину стека
        1. Добавление нового элемента со стороны пользователя
        2. Добавление нового элемента из вспомогательного стека
    3. Добавление случайного числа элементов в стек.
        получение количества случайных элементов.
    4. Удаление элемента из стека.
        1.Удаление элемента
        2.Перемещение элемента во вспомогательный стек.
    • при добавлении нового элемента запросить у пользователя происхождение этого элемента: действительно создание нового элемента или выбор его с вершины вспомогательного стека
    • вывод содержимого вспомогательного стека удаленных элементов
ssh-keygen -t ed25519 -C "your_email@example.com"
    */
   stack * sub_head = create();
   int flag = 1;
   while(flag!= 0){
       // fpurge(stdin);
        if(scanf("%d", &flag)!= 1){
            printf("Number's excepted\n");
            scanf("%*[^\n]");
            continue;
        }
        switch(flag){
            case 1 :
                if(is_empty(*root) == 0){
                    output(*root);
                } else { printf("Стек пуст\n"); }
                break;

            case 2 :
                printf("1. Добавление нового элемента со стороны пользователя\n");
                printf("2. Добавление нового элемента из вспомогательного стека\n");
                int choice;
                if(scanf("%d", &choice)!= 1){
                    printf("Number's excepted\n");
                    scanf("%*[^\n]");
                    break;
                }
                if(choice == 1){
                int elem;
                if(scanf("%d", &elem)!= 1){
                    printf("Number's excepted\n");
                    scanf("%*[^\n]");
                    break;
                }else{
                    push(root, elem);
                    printf("Элемент добавлен\n");
                }
                }
                else if(choice == 2){
                    if(is_empty(sub_head) == 0){
                       move(&sub_head, root) ;//push(root, pop(&sub_head));
                    } else {printf("Вспомогательный стек пуст\n");}
                }else{
                    printf("Error number\n");
                }
                break;

            case 3 :
                printf("Введите количество элементов\n");
                int count;
                if(scanf("%d", &count)!= 1){
                    printf("Number's excepted\n");
                    scanf("%*[^\n]");
                    break;
                }else{
                    push_random(root, count);
                    printf("Элементы добавлены\n");
                }
                break;
            case 4 :
                if(is_empty(*root) == 0){
                    printf("1. Удалить элемент\n");
                    printf("2. Переместить элемент во вспомогательный стек\n");
                    int elem;
                    if(scanf("%d", &elem)!= 1){
                        printf("Number's excepted\n");
                        scanf("%*[^\n]");
                        break;
                    }
                    if(elem == 1){
                        printf("%d\n", pop(root));
                    }
                    else if(elem == 2){
                        move(root, &sub_head);//push(&sub_head, pop(root));
                    }
                    else{
                        printf("Error number\n");
                    }
                } else { printf("Стек пуст\n"); }
                break;
            case 5:
                if(is_empty(sub_head) == 0){
                    output(sub_head);
                } else { printf("Вспомогательный стек пуст\n"); }
                break;
            case 0 :
                flag = 0;
                break;
            default:
                printf("Error number\n");
                break;



        }
   }
   destroy(&sub_head);
}