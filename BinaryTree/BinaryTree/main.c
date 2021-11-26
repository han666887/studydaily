#define _CRT_SECURE_NO_WARNINGS
#include "binarytree.h"

int main() {
	char str[] = "ABD###CE##F##";
	int sz = strlen(str);
	int i = 0;

	/*BTNode* n1 = BTNodeCreat('A');
	BTNode* n2 = BTNodeCreat('B');
	BTNode* n3 = BTNodeCreat('C');
	BTNode* n4 = BTNodeCreat('D');
	BTNode* n5 = BTNodeCreat('E');
	BTNode* n6 = BTNodeCreat('F');

	n1->left = n2;
	n1->right = n3;
	n2->left = n4;
	n3->left = n5;
	n3->right = n6;*/

	BTNode* bt = BTCreat(str, sz, &i);
	BTPrevOrder(bt);
	printf("\n");

	BTPrevOrder(bt);
	printf("\n");
	BTMidOrder(bt);
	printf("\n");
	BTPostOrder(bt);
	printf("\n");

	printf("%d\n", BTNodeSize(bt));


	printf("%d\n",BTLeafSize(bt));

	printf("%d\n",BTKSize(bt, 3));
	printf("%d\n", BTKSize(bt, 2));
	printf("%d\n", BTKSize(bt, 1));

	printf("%p\n",BTFind(bt, 'D'));
	printf("%p\n", BTFind(bt, 'B'));
	printf("%p\n", BTFind(bt, 'F'));
	printf("%p\n", BTFind(bt, 'G'));

	
	BTLevelOrder(bt);
	printf("\n");

	printf("%d\n",BTComplete(bt));

	BTDistory(bt);
	return 0;
}