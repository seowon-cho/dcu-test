#ifndef LISTS_H
#define LISTS_H

#define MAX 100

int insertElement(int list[], int size, int data) {
    if (size >= MAX) return 0;

    int i = 0;
    while (i < size && list[i] < data) i++;

    int move = size - i; // 이동한 자리 수
    for (int j = size - 1; j >= i; j--) {
        list[j + 1] = list[j];
    }

    list[i] = data;
    return move;
}

int deleteElement(int list[], int size, int data) {
    int i = 0;
    while (i < size && list[i] != data) i++;

    if (i == size) {
        return size; // 데이터 없음 신호
    }

    int move = size - 1 - i;
    for (int j = i; j < size - 1; j++) {
        list[j] = list[j + 1];
    }

    return move;
}

#endif // LISTS_H
