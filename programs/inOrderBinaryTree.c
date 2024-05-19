#include <stdio.h>
#include <stdlib.h>

#include "intro.c"

typedef struct node node;

struct node {
  int info;
  node *left;
  node *right;
};

node *createNode(int info) {
  node *newNode = (node *)malloc(sizeof(node));
  if (newNode == NULL) exit(1);
  newNode->info = info;
  newNode->left = newNode->right = NULL;
}

void inorder(node *root) {
  if (root == NULL) return;
  inorder(root->left);
  printf("%d ", root->info);
  inorder(root->right);
}

int main() {
  printIntro("binary tree and  in-order traversal using recursion");
  node *n1 = createNode(1);
  node *n2 = createNode(5);
  node *n3 = createNode(6);
  node *n4 = createNode(45);
  node *n5 = createNode(67);
  node *n6 = createNode(66);
  node *n7 = createNode(81);

  node *root = n1;

  root->left = n2;
  root->right = n3;

  n2->left = n4;
  n2->right = n5;

  n3->left = n6;
  n3->right = n7;

  printf("in-order traversal of binary tree : ");
  inorder(root);
  printf("\n");
}