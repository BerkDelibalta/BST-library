//
// Created by Berk Delibalta on 21/05/2021.
//

#ifndef UNTITLED133_TREE_PRIVATE_FUNCTIONALITIES_H
#define UNTITLED133_TREE_PRIVATE_FUNCTIONALITIES_H
#define MAX_BUFFER 30

node_s * load_data(node_s * root){


    FILE * BST_DATA;
    char BUFFER[MAX_BUFFER];
    int value;

    if((BST_DATA= fopen("BST.txt","r"))==NULL){
        fprintf(stderr,"ERROR:the file couldn't have been found out!\n");
        exit(1);
    }


    while (fgets(BUFFER, MAX_BUFFER, BST_DATA) != NULL){
        sscanf(BUFFER,"%d",&value);
        root=insert_node(root,value);
    }

    fclose(BST_DATA);

    return root;


}

node_s * create_new_node(node_s * root,int value){


    root=(node_s*) malloc(sizeof(node_s));
    if(root==NULL){
        fprintf(stderr,"ERROR:index out of bounds!");
        exit(1);
    }

    root->value=value;
    root->parent=root;
    root->right=NULL;
    root->left=NULL;

    return root;

}

node_s * insert_node(node_s * root,int value){

    if(root==NULL){
        return create_new_node(root,value);
    }


    if (root->value > value) {
        root->left = insert_node(root->left,value);
        root->parent =root;
    }

    if (root->value < value) {
        root->right = insert_node(root->right,value);
        root->parent = root;
    }



    return root;

}

node_s * search_node(node_s * root,int value){


    if(root==NULL){
        return NULL;
    }

    if(root->value>value)
        return search_node(root->left,value);


    if(root->value<value)
        return search_node(root->right,value);

    return root;

}

node_s * find_min_node(node_s * root){

    if(root==NULL)
        return NULL;

    if(root->left==NULL)
        return root;


    return find_min_node(root->left);

}

node_s * find_max_node(node_s * root){

    if(root==NULL)
        return NULL;

    if(root->right==NULL)
        return root;


    return find_max_node(root->right);

}

node_s * rotate_right(node_s * h){
    node_s * x = h->left;
    h->left=x->right;
    x->right=h;
    return x;
}

node_s * rotate_left(node_s * h){
    node_s * x= h->right;
    h->right=x->left;
    x->left=h;
    return x;
}

node_s * search_successor_node(node_s * root,int value){

    node_s * parent;

    if(root==NULL)
        return NULL;

    if(root->value>value) {
        return search_successor_node(root->left, value);
    }

    if(root->value<value) {
        return search_successor_node(root->right, value);
    }

    if(root->right!=NULL) {
        return find_min_node(root->right);
    } else {
        parent=root->parent;
        while (parent!=NULL && root==parent->right){
            root=parent;
            parent=parent->parent;
        }

        return parent;
    }
}


node_s * search_predecessor_node(node_s * root,int value){

    node_s * parent;

    if(root==NULL)
        return NULL;

    if(root->value>value) {
        return search_predecessor_node(root->left, value);
    }

    if(root->value<value) {
        return search_predecessor_node(root->right, value);
    }

    if(root->right!=NULL){
        return find_max_node(root->left);
    } else {
        parent=root->parent;
        while (parent!=NULL && root==parent->left){
            root=parent;
            parent=parent->parent;
        }
        return parent;
    }

}

node_s * select_the_kth_smallest_key(node_s * root,int k){

    int t;

    if(root==NULL)
        return NULL;

    t=(root->left==NULL) ? 0 : size(root->left);

    if(k<t) {
        return select_the_kth_smallest_key(root->left, k);
    }

    if(k>t) {
        return select_the_kth_smallest_key(root->right, k - t - 1);
    }

    return root;

}

node_s * partition_node(node_s * root,int k){

    int t;

    if(root==NULL)
        return NULL;

    t=(root->left==NULL) ? 0 : size(root->left);
    if(k<t){
        root->left= partition_node(root->left,k);
        root= rotate_right(root);
    }

    if(k>t){
        root->right= partition_node(root->right,k-t-1);
        root= rotate_left(root);
    }

    return root;

}


node_s * delete_node(node_s * root,int value){

    node_s * tmp;


    if(root==NULL){
        return NULL;
    }

    if(root->value>value){
        root->left=delete_node(root->left,value);
        return root;
    }

    if(root->value<value){
        root->right=delete_node(root->right,value);
        return root;
    }

    tmp=root;

    if(root->left==NULL){
        root=root->right;
        free(tmp);
        return root;
    }

    if(root->right==NULL){
        root=root->left;
        free(tmp);
        return root;
    }

    root->left= delete_max_node(root->left,&value);
    root->value=value;

    return root;


}

node_s * delete_max_node(node_s * root,int * value){

    node_s * tmp;

    if(root->right==NULL){
        *value=root->value;
        tmp=root->left;
        free(root);
        return tmp;
    }

    root->right= delete_max_node(root->right,value);

    return root;

}

int size(node_s * x){

    if(x==NULL)
        return 0;

    return (size(x->left)+1+ size(x->right));

}

int key_rank(node_s * root,int value){

    node_s * key;

    key= search_node(root,value);

    if(key==NULL)
        return -1;

    if(root->value>key->value) {
        return key_rank(root->left, key->value);
    }

    if (root->value < key->value) {
        return 1 + size(key->left) + size(key->right);
    }

    if (root->value == key->value){
        return size(key->left);
    }

    return 0;

}

void prefix(node_s * root){

    if(root==NULL){
        return;
    }

    prefix(root->left);
    prefix(root->right);
    fprintf(stdout,"%d\n",root->value);

}

void infix(node_s * root){

    if(root==NULL){
        return;
    }

    infix(root->left);
    fprintf(stdout,"%d\n",root->value);
    infix(root->right);

}

void postfix(node_s * root){

    if(root==NULL){
        return;
    }

    fprintf(stdout,"%d\n",root->value);
    postfix(root->left);
    postfix(root->right);

}

void bst_free(node_s * root){

    free(root->parent);
    free(root->left);
    free(root->right);
    free(root);

}


#endif //UNTITLED133_TREE_PRIVATE_FUNCTIONALITIES_H

