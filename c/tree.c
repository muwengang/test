#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
	int data;
	struct node *p_right;
	struct node *p_left;
}Node,Tree;

void tree_init(Tree **tree){
	*tree = NULL;
}

int tree_empty(Tree **tree){
	return *tree == NULL;
}
void tree_insert_data(Tree **tree, int data){
	if(*tree == NULL){
		Tree *tmp = (Tree *)malloc(sizeof(Tree));
		if(tmp){
			tmp->data = data;
			tmp->p_left = tmp->p_right = NULL;
			*tree = tmp;
			return;
		}
		return;
	}
	if(data > (*tree)->data){
		tree_insert_data(&(*tree)->p_right,data);
	}
	else{
		tree_insert_data(&(*tree)->p_left,data);
	}
}
void tree_insert_node(Tree **tree, Node *node){
	if(*tree == NULL){
		*tree = node;
		return;
	}
	if((*tree)->data > node->data ){
		tree_insert_node(&(*tree)->p_left,node);
	}else{
		tree_insert_node(&(*tree)->p_right,node);
	}
}
void tree_destory(Tree *tree){
	if(!tree)
		return;
	tree_destory(tree->p_left);
	tree_destory(tree->p_right);
	free(tree);
	tree = NULL;
}
int tree_depth(Tree *tree){
	int left = 0, right = 0;
	if(tree == NULL)
		return 0;
	left = 1 + tree_depth(tree->p_left);
	right = 1 + tree_depth(tree->p_right);
	return left>right ? left:right;
}

void print_preorder(Tree *tree){
	if(tree){
		printf("%d ",tree->data);
		print_preorder(tree->p_left);
		print_preorder(tree->p_right);
	}
}

void print_inorder(Tree *tree){
	if(tree){
		print_inorder(tree->p_left);
		printf("%d ",tree->data);
		print_inorder(tree->p_right);
	}
}

void print_postorder(Tree *tree){
	if(tree){
		print_postorder(tree->p_left);
		print_postorder(tree->p_right);
		printf("%d ",tree->data);
	}
}


Node *tree_search(Tree *tree, int data){
	if(tree == NULL)
		return NULL;
	struct node *temp = tree;
	if(tree->data == data){
		return temp;
	}
	if(data > tree->data)
		return tree_search(tree->p_right,data);
	else
		return tree_search(tree->p_left, data);
}

Node *tree_binary_search(Tree *tree,int data,Node **per){
	if(tree == NULL)
		return NULL;
	Node *node = tree;
	if(tree->data == data){
		*per = node;
		return node;
	}else if(tree->p_left!=NULL && tree->p_left->data == data){
		*per = node;
		return tree->p_left;
	}else if(tree->p_right!=NULL && tree->p_right->data == data){
		*per = node;
		return tree->p_right;
	}else{
		if(tree->data > data){
			return tree_binary_search(tree->p_left,data,per);
		}else{
			return tree_binary_search(tree->p_right,data,per);
		}
	}
}
void tree_delete(Tree **tree, int data){
	if(*tree == NULL)
		return;
	Node *per = NULL;
	Node *temp = NULL;
	Node *cur = tree_binary_search(*tree,data,&per);
	if(cur == NULL)
		return;
	//如果是根节点
	 // printf("11111111111111,cur->data = %d\n,cur =%x,per->p_left = %x,per->right= %x",cur->data,cur,(per)->p_left,(per)->p_right);
	if(cur == *tree){
		tree_insert_node(&(*tree)->p_right,(*tree)->p_left);
		temp = *tree;
		*tree = (*tree)->p_right;
		free(temp);
		temp = NULL;
	//如果是左节点
	}else if(cur == (per)->p_left){
		if(cur->p_left != NULL && cur->p_right!=NULL){
			tree_insert_node(&(cur->p_right),cur->p_left);
			(per)->p_left = cur->p_right;
		}else if(cur->p_left == NULL){
			(per)->p_left = cur->p_right;
		}else{
			(per)->p_left = cur->p_left;
		}
		free(cur);
		cur = NULL;
	//如果是右节点
	}else if(cur == (per)->p_right){
		if(cur->p_left != NULL && cur->p_right != NULL){
			tree_insert_node(&(cur->p_right),cur->p_left);
			(per)->p_right = cur->p_right;
		}else if(cur->p_left == NULL){
			(per)->p_right = cur->p_right;
		}else{
			(per)->p_right = cur->p_left;
		}
		free(cur);
		cur = NULL;
	}else{
		printf("error\n");
	}
}

int main(int argc, char **argv){
	Tree *tree;
	tree_init(&tree);
	tree_insert_data(&tree,50);
	tree_insert_data(&tree,40);
	tree_insert_data(&tree,60);
	tree_insert_data(&tree,30);
	tree_insert_data(&tree,55);
	tree_insert_data(&tree,35);
	tree_insert_data(&tree,70);
	tree_insert_data(&tree,65);
	tree_insert_data(&tree,37);
	tree_insert_data(&tree,54);
	tree_insert_data(&tree,56);
	printf("The preorder is:\n");
	print_preorder(tree);
	printf("\nThe postorder is:\n");
	print_postorder(tree);
	printf("\nThe inorder is:\n");
	print_inorder(tree);
	printf("The depth is :%d\n",tree_depth(tree) );
	tree_delete(&tree,60);
	// tree_delete(&tree,37);
	printf("delete success:\n");
	printf("The preorder is:\n");
	print_preorder(tree);
	printf("\nThe postorder is:\n");
	print_postorder(tree);
	printf("\nThe inorder is:\n");
	print_inorder(tree);
	printf("\n");
	tree_destory(tree);
	return 0;
}
/*                          50
*                     40         60
*                  30   35     55    70
*                         37       65
*                                55
*						      54   56
*
*
*/
