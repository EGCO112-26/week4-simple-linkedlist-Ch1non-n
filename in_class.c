//
//  main.c
//  simple linkedlist
//
//  Created by Mingmanas Sivaraksa on 4/2/2566 BE.
//

#include <stdio.h>
#include <stdlib.h>
#include "node.h"

int main(int argc, const char * argv[]) {
    int c=5;
    struct node a,b,*head ;
    a.value = c;
    a.next=&b;
    head=&a;
    b.value=head->value+3;

    // printf("%d\n", head ->value ); //what value for 5
    // printf("%d\n", head ->next->value ); //what value for 8

/*  Exercise I
    1. Add 1 more than at the end
    2. Add value(11)
    3. Make next become NULL
 */
    printf("Insert in front\n");
    struct node d;
    b.next = &d;
    d.value = 11; // b.next -> value = 11 or (*&d).value or a.next -> next -> value = 11 or head -> next -> next -> value 11
    // printf("%d\n", d.value);
    d.next = NULL; //NullPtr
    
/*  Exercise II
        1. Add 1 more than at the begining!!!!
        2. Add value (2)
*/
    struct node e;
    e.value = 2;
    e.next = &a;
    head = &e;

    struct node mid; // แทรกตรงกลาง
    mid.value = 7;
    mid.next = &b;
    a.next = &mid;

    typedef struct node* NodePtr;
    NodePtr tmp = head; //add temp value to faciliate
        
     //Exercise III Use loop to print everything
     
        int i,n=5;
        for(i=0;i<n;i++){
            printf("%3d ", tmp->value);
          // What is missing???
          tmp = tmp -> next;
        }
        printf("\n");
    
    
   // Exercise IV change to while loop!! (you can use NULL to help)
        tmp = head;
        while(tmp != NULL){
            printf("%3d ", tmp->value);
           // What is missing???
            tmp = tmp -> next;
        }
        printf("\n");

    printf("Create node by malloc\n");
 /*  Exercise V Use malloc to create all nodes, instead of create a struct!!
         //use a loop to help
     */
    typedef struct node* nodePtr;
    nodePtr head2, temp;
    head2 = (nodePtr) malloc (sizeof(struct node)); // have one node before loop
    temp = head2;
    n = 5;
    for(int i = 0; i < n; i++)
    {
        temp -> value = 7 + i*2;
        temp -> next = (NodePtr)malloc(sizeof(struct node));
        temp = temp -> next;
    }
    temp -> value = 7 + i*2;
    temp -> next = NULL;

    //just for print
    temp = head2;
    while(temp != NULL){
        printf("%3d ", temp->value);
           // What is missing???
        temp = temp -> next;
    }
    printf("\n");
    printf("Free malloc\n");
    /*  Exercise VI Free all node !!
         //use a loop to help
     */
    temp = head2;
    for(int i = 0; i <= n; i++){
        head2 = head2 -> next;
        printf("Freeing %d\n", temp -> value);
        free(temp);
        temp = head2;
    }

 

    // printf("%d\n", head ->value ); //what value for 2
    // printf("%d\n", head ->next->value ); //what value for 5
    // printf("%d\n", head ->next->next->value ); //what value for 7
    // printf("%d\n", head ->next->next->next->value ); //what value for 8
    // printf("%d\n", head ->next->next->next->next->value ); //what value for 11
    return 0;
}
