//
//  node.h
//  simple linkedlist
//
//  Created by Mingmanas Sivaraksa on 4/2/2566 BE.
//

#ifndef node_h
#define node_h

struct node
{
    int value;
    struct node *next;
};

struct std_node{

    int id;
    char name[30];
    struct std_node *link;

};

#endif /* node_h */
