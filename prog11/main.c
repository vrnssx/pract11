#include <stdio.h>
#include <stdlib.h>

int count_positive_before_first_negative(int arr[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] < 0) {
            break;
        }
        if (arr[i] > 0) {
            count++;
        }
    }
    return count;
}

int main() {
    int size;

    printf("Введіть розмір масиву: ");
    if (scanf("%d", &size) != 1 || size <= 0) {
        printf("Некоректний розмір масиву.\n");
        return 1;
    }

    int *arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Помилка виділення пам'яті.\n");
        return 1;
    }

    printf("Введіть елементи масиву через пробіл:\n");
    for (int i = 0; i < size; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Помилка введення елемента.\n");
            free(arr);
            return 1;
        }
    }

    int positive_count = count_positive_before_first_negative(arr, size);

    printf("Кількість додатних елементів до першого від'ємного в масиві: %d\n", positive_count);

    free(arr);
    return 0;
}