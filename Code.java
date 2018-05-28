//
// Definition for binary tree:
// class Tree<T> {
//   Tree(T x) {
//     value = x;
//   }
//   T value;
//   Tree<T> left;
//   Tree<T> right;
// }
Tree<Integer> deleteFromBST(Tree<Integer> t, int[] queries) {
    for(int i = 0; i < queries.length; i++){
        t = deleteKey(t, queries[i]);
    }
        
    return t;
}

Tree<Integer> deleteKey(Tree<Integer> t, int key){
    if(t == null)
        return null;
    
    if(t.value == key){
        if(t.left == null)
            return t.right;
        else{
            Tree<Integer> temp = max(t.left);
            temp.left = delMax(t.left);
            temp.right = t.right;
            
            return temp;
        }
    }else{
        t.left = deleteKey(t.left, key);
        t.right = deleteKey(t.right, key);
    }
    
    return t;
}

Tree<Integer> min(Tree<Integer> t){

    while(t.left != null){
        t = t.left;
    }
    
    return t;
}

Tree<Integer> delMin(Tree<Integer> t){
    if(t.left == null)
        return t.right;
    
    t.left = delMin(t.left);
    
    return t;
}


Tree<Integer> max(Tree<Integer> t){

    while(t.right != null){
        t = t.right;
    }
    
    return t;
}

Tree<Integer> delMax(Tree<Integer> t){
    if(t.right == null)
        return t.left;
    
    t.right = delMax(t.right);
    
    return t;
}
