#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"

int main(int argc, char *argv[]){

    if(argc < 3) return 0; // test1 failed

    int N = argc / 2;
    typedef struct std_node *nodePtr;
    nodePtr head, temp;
    head = (nodePtr)malloc(sizeof(struct std_node));
    temp = head;
    temp->id = atoi(argv[1]);
    strcpy(temp->name, argv[2]);
    //printf("%d %s", temp->id, temp->name);

    int i = 1;
    while(i < N){

        temp->link = (nodePtr)malloc(sizeof(struct std_node));
        temp = temp->link;
        temp->id = atoi(argv[(2 * i) + 1]);
        strcpy(temp->name, argv[(2 * i) + 2]);
        i++;
    }
    temp->link = NULL;

    temp = head;
    // while(temp != NULL){
    //     printf("%d %s\n", temp->id, temp->name);
    //     temp = temp->link;
    // }
    for(i = 1; i <= N; i++){
        printf("%d %s", temp->id, temp->name);
        if(i < N)printf("\n");
        temp = temp->link;
    }

    // while(head != NULL){
    //     temp = head;
    //     head = head->link;
    //     free(temp);
    // }


    for(int i = 1; i<=N; i++){
        temp = head;
        head = head->link;
        free(temp);
    }
    
    return 0;
}

