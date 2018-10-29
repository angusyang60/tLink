#include <tList.h>

char a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

int main(void)
{
	list_t meLst = tList_init(a[0]);
	list_t tlst;
	int i;
	size_t _size = sizeof(a);

	for (i = 0; i < _size; i++)
		tlst = tList_add(meLst, a[i]);

	tlst = meLst;
	do {
		printf("%02x ", tlst->node);
	}while ((tlst = tlst->next));
	printf("\n");

	meLst = tList_delete(meLst, 1);
	tlst = meLst;
	do {
		printf("%02x ", tlst->node);
	}while ((tlst = tlst->next));
	printf("\n");

	meLst = tList_delete(meLst, 1);
	tlst = meLst;
	do {
		printf("%02x ", tlst->node);
	}while ((tlst = tlst->next));
	printf("\n");

	meLst = tList_delete(meLst, 5);
	tlst = meLst;
	do {
		printf("%02x ", tlst->node);
	}while ((tlst = tlst->next));
	printf("\n");

	meLst = tList_delete(meLst, 10);
	tlst = meLst;
	do {
		printf("%02x ", tlst->node);
	}while ((tlst = tlst->next));
	printf("\n");

	meLst = tList_add(meLst, 11);

	tlst = meLst;
	do {
		printf("%02x ", tlst->node);
	}while ((tlst = tlst->next));
	printf("\n");

	meLst = tList_delete(meLst, 2);
	tlst = meLst;
	do {
		printf("%02x ", tlst->node);
	}while ((tlst = tlst->next));
	printf("\n");

	meLst = tList_delete(meLst, 7);
	tlst = meLst;
	do {
		printf("%02x ", tlst->node);
	}while ((tlst = tlst->next));
	printf("\n");

	tList_eraseAll(meLst);
	return 0;
}
