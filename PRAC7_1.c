/*
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int size_of(int xyz[]) {
    int y = 0;
    int cnt = 0;
    while (xyz[y] != 0) {
        cnt++;
        y++;
    }
    return cnt;
}

bool isempty(int estack[]) {
    return estack[0] == 0;
}

void destination(int stacksrc[], int auxilary_stack[]) {
    int destination_stack[3] = {0, 0, 0};
    int sizesrc = size_of(stacksrc);
    int i = 0, y = 0, pushidx = sizesrc - 1;

    while (destination_stack[0] != 3 || destination_stack[1] != 2 || destination_stack[2] != 1) {

        if (isempty(destination_stack) || stacksrc[pushidx] < destination_stack[size_of(destination_stack) - 1]) {
            destination_stack[size_of(destination_stack)] = stacksrc[pushidx];
            pushidx--;
        } else {
            auxilary_stack[size_of(auxilary_stack)] = stacksrc[pushidx];
            pushidx--;
        }
    }

    for (int i = 0; i < 3; i++) {
        printf("%d ", destination_stack[i]);
    }
    printf("\n");
}

int main() {
    int A = 1, B = 2, C = 3;
    int source_stack[3] = {C, B, A};
    int auxilary_stack[3] = {0, 0, 0};
    destination(source_stack, auxilary_stack);
    return 0;
}
*/

#include <stdio.h>

void tower_of_hanoi(int n, char source, char auxiliary, char destination) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }
    tower_of_hanoi(n - 1, source, destination, auxiliary);
    printf("Move disk %d from %c to %c\n", n, source, destination);
    tower_of_hanoi(n - 1, auxiliary, source, destination);
}

int main() {
    int n = 3; // Number of disks
    tower_of_hanoi(n, 'A', 'B', 'C'); // A, B and C are names of rods
    return 0;
}

