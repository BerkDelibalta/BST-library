//
// Created by Berk Delibalta on 21/05/2021.
//

#ifndef UNTITLED133_TREE_PROTOTYPES_H
#define UNTITLED133_TREE_PROTOTYPES_H
typedef struct node_t{

    int value;
    struct node_t * parent;
    struct node_t * right;
    struct node_t * left;

}node_s;

node_s * load_data(node_s * root);
node_s * create_new_node(node_s * root,int value);
node_s * insert_node(node_s * root,int value);
node_s * search_node(node_s * root,int value);
node_s * find_min_node(node_s * root);
node_s * find_max_node(node_s * root);
node_s * rotate_right(node_s * h);
node_s * rotate_left(node_s * h);
node_s * search_successor_node(node_s * root,int value);
node_s * search_predecessor_node(node_s * root,int value);
node_s * select_the_kth_smallest_key(node_s * root,int k);
node_s * partition_node(node_s * root,int k);
node_s * delete_node(node_s * root,int value);
node_s * delete_max_node(node_s * root,int * value);
int key_rank(node_s * root,int value);
int size(node_s * x);
void prefix(node_s * root);
void infix(node_s * root);
void postfix(node_s * root);
void bst_free(node_s * root);

#endif //UNTITLED133_TREE_PROTOTYPES_H
