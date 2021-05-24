//
// Created by Berk Delibalta on 21/05/2021.
//

#ifndef UNTITLED133_TREE_CONTROL_H
#define UNTITLED133_TREE_CONTROL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Tree_Prototypes.h"
#include "Tree_Private_Functionalities.h"
#define MAX_BUFFER 30


void Tree_control(){

    node_s * root=NULL;
    char command[MAX_BUFFER];
    int value,k,stop=0;


    while (stop==0){

        fprintf(stdout,"\nWelcome to the command line\n");
        fprintf(stdout,"load           -load data from file and create the bst\n");
        fprintf(stdout,"min            -find the minimum root in the bst tree\n");
        fprintf(stdout,"max            -find the maximum root in the bst tree\n");
        fprintf(stdout,"successor      -find the successor of a root\n");
        fprintf(stdout,"predecessor    -find the predecessor of a root\n");
        fprintf(stdout,"partition      -partition the kth smallest value to the root\n");
        fprintf(stdout,"kth            -find the Kth smallest value in the bst tree\n");
        fprintf(stdout,"size           -find the size of the sub-trees connected to a node\n");
        fprintf(stdout,"rank           -find the rank of a root\n");
        fprintf(stdout,"delete         -delete nodes from the bst tree\n");
        fprintf(stdout,"prefix         -display the bst tree in prefix form\n");
        fprintf(stdout,"infix          -display the bst tree in infix form\n");
        fprintf(stdout,"postfix        -displays the bst tree in postfix form\n");
        fprintf(stdout,"exit           -exit the program\n");
        fprintf(stdout,"\n");
        fprintf(stdout,"Enter a command please :");
        scanf("%s",command);

        if(strcmp(command,"load")==0){
            root= load_data(root);
        } else if(strcmp(command,"delete")==0) {

            fprintf(stdout, "Enter the value you wish to delete from the bst tree please :");
            scanf("%d", &value);

            root= delete_node(root,value);

            if(root==NULL){
                fprintf(stderr,"ERROR:the value is not existing!\n");
            } else {
                fprintf(stdout, "The value %d has been deleted successfully\n", delete_node(root, value)->value);
            }
        } else if(strcmp(command,"min")==0){
            fprintf(stdout,"Min root: %d", find_min_node(root)->value);
        } else if(strcmp(command,"max")==0){
            fprintf(stdout,"Max root: %d", find_max_node(root)->value);
        } else if(strcmp(command,"successor")==0){
            fprintf(stdout,"Enter the value ,successor of which you want to find out please:");
            scanf("%d",&value);
            if(search_successor_node(root,value)==NULL){
                fprintf(stderr,"ERROR:the value doesn't have a successor\n");
                continue;
            }
            fprintf(stdout,"The successor is %d",search_successor_node(root,value)->value);
        } else if(strcmp(command,"predecessor")==0){
            fprintf(stdout,"Enter the value ,predecessor of which you want to find out please:");
            scanf("%d",&value);
            if(search_predecessor_node(root,value)==NULL){
                fprintf(stderr,"ERROR:the value doesn't have a predecessor\n");
                continue;
            }
            fprintf(stdout,"The predecessor is %d", search_predecessor_node(root,value)->value);
        } else if(strcmp(command,"partition")==0){
            fprintf(stdout,"Enter the kth smallest value you want to partition please :");
            scanf("%d",&k);
            partition_node(root,k);
        } else if(strcmp(command,"kth")==0){
            fprintf(stdout,"Enter the k value please :");
            scanf("%d",&k);
            fprintf(stdout,"The Kth smallest value in the bst is %d", select_the_kth_smallest_key(root,k)->value);
        } else if(strcmp(command,"size")==0){
            fprintf(stdout,"Enter the root value please :");
            scanf("%d",&value);
            node_s * key=NULL;
            key = search_node(root,value);
            if(key==NULL)
                fprintf(stderr,"ERROR:the root couldn't have been found out!\n");
            fprintf(stdout,"The sub-tree size of the root is %d", size(key));
        }  else if(strcmp(command,"rank")==0){
            fprintf(stdout,"Enter the root value please :");
            scanf("%d",&value);
            fprintf(stdout,"The rank of the root is %d", key_rank(root,value));
        }  else if(strcmp(command,"prefix")==0){
            fprintf(stdout,"The prefix visited bst\n");
            prefix(root);
        } else if(strcmp(command,"infix")==0){
            fprintf(stdout,"The infix visited bst\n");
            infix(root);
        } else if(strcmp(command,"postfix")==0){
            fprintf(stdout,"The postfix visited bst\n");
            postfix(root);
        } else if(strcmp(command,"exit")==0){
            fprintf(stdout,"This is the end of the program!\n");
            stop=1;
        } else {
            fprintf(stderr,"ERROR:you've entered an unrecognized command!\n");
        }
    }

    bst_free(root);

}



#endif //UNTITLED133_TREE_CONTROL_H
