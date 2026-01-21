#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_SIZE 20

int data[MAX_SIZE] = {0};
int size = MAX_SIZE;
int count = 0;

int left(int num, int index);
int right(int num, int index);
void setRoot(int x);
void insert(int x);
void displayTree();
int showMin();
int showMax();
void taskMenu();

void setRoot(int x) {
    data[0] = x;
    count++;
}

int left(int num, int index) {
    int current = (2 * index) + 1;
    if (current >= size) {
        printf("Cannot insert, index out of bounds.\n");
        return 0;
        
    }

    if (data[current] != 0) {
        if (num < data[current]) left(num, current);
        else right(num, current);
    } else {
        data[current] = num;
        count++;
    }
    return 0;
}

int right(int num, int index) {
    int current = (2 * index) + 2;
    if (current >= size) {
        printf("Cannot insert, index out of bounds.\n");
        return 0;
    }

    if (data[current] != 0) {
        if (num < data[current]) left(num, current);
        else right(num, current);
    } else {
        data[current] = num;
        count++;
    }
    return 0;
}

void insert(int x) {
    if (count >= size) {
        printf("Cannot insert, BST is full.\n");
        return;
    }
    if (count == 0) {
        setRoot(x);
    } else {
        if (x < data[0]) left(x, 0);
        else right(x, 0);
    }
}

void displayTree() {
    if (count == 0) {
        printf("...Tree is empty...\n");
        return;
    }
    for (int i = 0; i < size; i++) {
        if (data[i] != 0) {
            int leftChild = ((2 * i) + 1 < size) ? data[(2 * i) + 1] : 0;
            int rightChild = ((2 * i) + 2 < size) ? data[(2 * i) + 2] : 0;
            printf("Node %d: Left -> %d | Right -> %d\n", data[i], leftChild ? leftChild : 0, rightChild ? rightChild : 0);
        }
    }
    for(int j = 0;j < size; j++) {
        printf(" %d,", data[j]);
    }
}

int showMin() {
    int min_index = 0;
    while (data[(2 * min_index) + 1] != 0) {
        min_index = (2 * min_index) + 1;
    }
    return data[min_index];
}

int showMax() {
    int max_index = 0;
    while (data[(2 * max_index) + 2] != 0) {
        max_index = (2 * max_index) + 2;
    }
    return data[max_index];
}

void taskMenu() {
    int choice;
    int input;
    int status, status_c;
    printf("                 Group 8\n");
    printf("    -Show minimum and maximum number-\n\n");
    while (1) {
        printf("\n> Current size: %d <\n", count);
        printf("> Space left: %d <\n\n", size - count);

        printf("______________> TASK MENU <______________\n\n");
        printf("1> Insert\n2> Display\n3> Show Minimum and Maximum Number\n4> Exit\n_________________________________________\n");

        printf("\nSelect Task : ");
        status = scanf("%d", &choice);
        
        if (status == 1 && (choice >= 1 && choice <= 4)) {
            switch (choice) {
                case 1: {
                    if (count >= size) {
                        printf("Cannot insert, BST is full.\n");
                        break;
                    }
                    while (1) {
                        printf("> Insert a number to BST : ");
                        status_c = scanf("%d", &input);
                        if (status_c == 1 && input != 0) {
                            insert(input);
                            break;
                        } else {
                            printf("!! Invalid input !!\n");
                            if (input == 0) printf("Input cannot be 0\n");
                            while (getchar() != '\n');
                        }
                    }
                    break;
                }
                case 2: {
                    displayTree();
                    break;
                }
                case 3: {
                    if (count > 0) {
                        printf("\nMinimum number -> %d\n", showMin());
                        printf("Maximum number -> %d\n", showMax());
                    } else {
                        printf("...Tree is empty...\n");
                    }
                    break;
                }
                case 4: {
                    printf("Exiting program...\n");
                    return;
                }
            }
        } else {
            printf("!! Invalid input !!\n");
            while (getchar() != '\n');
        }
        
    }
}
int main() {
    taskMenu();
    return 0;
}
