#include <stdio.h>
#include <stdlib.h>

#include "intro.c"

typedef struct node node;

struct node {
  int data;
  node *left;
  node *right;
};

node *createNode(int data) {
  node *newNode = (node *)malloc(sizeof(node));
  if (newNode == NULL) exit(1);
  newNode->data = data;
  newNode->left = newNode->right = NULL;
}

void preOrder(node *root) {
  if (root == NULL) return;
  printf("%d ", root->data);
  preOrder(root->left);
  preOrder(root->right);
}

int main() {
  printIntro("binary tree and pre-order traversal using recursion");
  node *root = NULL;
  node *n1 = createNode(1);
  node *n2 = createNode(5);
  node *n3 = createNode(6);
  node *n4 = createNode(45);
  node *n5 = createNode(67);
  node *n6 = createNode(66);
  node *n7 = createNode(81);

  root = n1;

  root->left = n2;
  root->right = n3;

  n2->left = n4;
  n2->right = n5;

  n3->left = n6;
  n3->right = n7;

  printf("pre-order traversal of binary tree : ");
  preOrder(root);
  return 0;
}