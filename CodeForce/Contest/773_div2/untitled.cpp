void createExpTree(BTNode **root, char *prefix) {
   *root = malloc(sizeof(BTNode));
   char *token = strtok(prefix, " ");    // set string prefix, delimited by spaces, to be tokenized
   if( isdigit(token[0]) ) {             // external nodes (= leaves) are operands
       (*root)->item = atoi(token);
       (*root)->left = NULL;
       (*root)->right = NULL;
   }
   else {                                // internal nodes are binary operators
       (*root)->item = token[0];
       createExpTree(&(*root)->left, NULL);  // continue using the same string prefix
       createExpTree(&(*root)->right, NULL); // continue using the same string prefix
   }
}

void printTree(BTNode *node){
   if( node == NULL ) return;
   if( node->left == NULL && node->right == NULL )  // external node
       printf("%d", node->item);
   else {                                           // internal node
       printf("(");
       printTree(node->left);
       printf(" %c ", (char)node->item);
       printTree(node->right);
       printf(")");
   }
}

void printTreePostfix(BTNode *node){
   if( node == NULL ) return;
   printTreePostfix(node->left);
   printTreePostfix(node->right);
   if(node->left ==NULL && node->right == NULL)  // external node
      printf("%d ",node->item);
   else                                          // internal node
      printf("%c ",(char)(node->item));
}

void createExpTree(BTNode** root,char* prefix)
{
 //Write your code here
    *root = malloc(sizeof(BTNode));
    int cnt = 0, otp = 0;
    while(*(prefix+cnt) != '\0' || *(prefix+cnt) != ' '){
        cnt++;
    }
    if(cnt == 1 && isDigit(*(prefix)) ){
        otp = 1;
    }
    if(otp){
        (*root)->item = (int)(*(prefix));
        createExpTree(&(*root)->left, prefix+cnt);
        createExpTree(&(*root)->right, prefix+cnt);
    } else {
        int f = 1, result = 0;
        while(cnt--){
            result += (*(prefix+cnt))*f;
            f *= 10;
        }
        (*root)->item = result;
        (*root)->right = NULL;
        (*root)->left = NULL;
    }
}

void printTree(BTNode *node){
    //Write your code here
}


void printTreePostfix(BTNode *node){
   //Write your code here

}