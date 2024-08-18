#include <stdio.h>
#include <stdlib.h>
struct st_node {
    int val;
    struct st_node *next;
};

typedef struct st_node node;

int v_empty(node *ll) {
    if (ll->next == NULL) {
        return 1;
    } else {
        return 0;
    }
}

void free_list(node *ll) {
    if (!v_empty(ll)) {
        node *nextNode, *currentNode;
        while (currentNode != NULL) {
            nextNode = currentNode->next;
            free(currentNode);
            currentNode = nextNode;
        }
    }
}

void print_list(node *ll) {
    if (v_empty(ll)) {
        printf("Empty list\n");
        return;
    }
    node *tempNode;
    tempNode = ll->next;
    while (tempNode != NULL) {
        printf("%d ", tempNode->val);
        tempNode = tempNode->next;
    }
    printf("\n");
}

void insertFirst(node *ll) {
    node *newNode = (node *)malloc(sizeof(node));
    if (!newNode) {
        printf("Not enough space\n");
        exit(1);
    }
    printf("Enter new value: ");
    scanf("%d", &newNode->val);
    node *oldHead = ll->next;
    ll->next = newNode;
    newNode->next = oldHead;
}

void insertLast(node *ll) {
    node *newNode = (node *) malloc(sizeof(node));
    if (!newNode) {
        printf("Not enough space\n");
        exit(1);
    }
    printf("Enter new value: ");
    scanf("%d", &newNode->val);
    newNode->next = NULL;
    if (v_empty(ll)) {
        ll->next = newNode;
    } else {
        node *tempNode = ll->next;
        while (tempNode->next != NULL) {
            tempNode = tempNode->next;
        }
        tempNode->next = newNode;
    }
}

void startList(node *ll) {
    ll->next = NULL;
}

void option(node *ll, int option) {
    switch (option) {
        case 0:
            free_list(ll);
            break;
        case 1:
            print_list(ll);
            break;
        case 2:
            insertFirst(ll);
            break;
        case 3:
            insertLast(ll);
            break;
        case 4:
            startList(ll);
            break;
        default:
            printf("Invalid option\n");
    }
}

int menu() {
    int opt;
    printf("Switch option: \n");
    printf("0. Exit\n");
    printf("1. Print list\n");
    printf("2. Insert first\n");
    printf("3. Insert last\n");
    printf("4. Start list\n");
    printf("Option: ");
    scanf("%d", &opt);
    return opt;
}
int main() {
    node *ll = (node *) malloc(sizeof(node));
    if (!ll) {
        printf("Not enough space\n");
        exit(1);
    }
    startList(ll);
    int opt;
    do {
        opt = menu();
        option(ll, opt);
    }while (opt);
    free(ll);
}
