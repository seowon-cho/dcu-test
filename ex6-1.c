#include "queueS.h"

int main(void) {
    QueueType* Q1 = createQueue();
    element data;
    printf("\n ***** 순차 큐 연산 ***** \n");
    printf("\n 삽입 A >> "); enQueue(Q1, 'A'); printQueue(Q1);
    printf("\n 삽입 B >> "); enQueue(Q1, 'B'); printQueue(Q1);
    printf("\n 삽입 C >> "); enQueue(Q1, 'C'); printQueue(Q1);
    data = peekQ(Q1); printf("\n peekQ() >> %c \n", data);

    printf("\n 삭제 >> "); data = deQueue(Q1); printQueue(Q1);
    printf("\n삭제 데이터: %c\n", data);
    printf("\n 삭제 >> "); data = deQueue(Q1); printQueue(Q1);
    printf("\t삭제 데이터: %c\n", data);
    printf("\n 삭제 >> "); data = deQueue(Q1); printQueue(Q1);
    printf("\t\t삭제 데이터: %c\n", data);

    printf("\n 삽입 D >> "); enQueue(Q1, 'D'); printQueue(Q1);
    printf("\n 삽입 E >> "); enQueue(Q1, 'E'); printQueue(Q1);

    getchar();
    return 0;
}
