// Definition for arrays:
// typedef struct arr_##name {
//   int size;
//   type *arr;
// } arr_##name;
//
// arr_##name alloc_arr_##name(int len) {
//   arr_##name a = {len, len > 0 ? malloc(sizeof(type) * len) : NULL};
//   return a;
// }
//
// Definition for binary tree:
// typedef struct tree_##name {
//   type value;
//   struct tree_##name *left;
//   struct tree_##name *right;
// } tree_##name;
//
// tree_##name *alloc_tree_##name(type v) {
//   tree_##name *t = calloc(1, sizeof(tree_##name));
//   t->value = v;
//   return t;
// }

tree_integer * max(tree_integer * t){
    while(t->right != NULL)
        t = t->right;
    
    return t;
}

tree_integer * delMax(tree_integer * t){
    if(t->right == NULL)
        return t->left;
    
    t->right = delMax(t->right);
    
    return t;
}

tree_integer * deleteKey(tree_integer * t, int key){
    if(t == NULL)
        return NULL;
    
    if(t->value == key){
        if(t->left == NULL)
            return t->right;
        else{
            tree_integer * tmp = max(t->left);
            tmp->left = delMax(t->left);
            tmp->right = t->right;
            
            return tmp;
        }
    }else{
        t->left = deleteKey(t->left, key);
        t->right = deleteKey(t->right, key);
    }
    
    return t;
}

tree_integer * deleteFromBST(tree_integer * t, arr_integer queries) {
    for(int i = 0; i < queries.size; i++){
        t = deleteKey(t, queries.arr[i]);
    }
    
    return t;
}
