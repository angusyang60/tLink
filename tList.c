#include "tList.h"

/**
 * @fn tList_init
 * @brief init a list struct
 * @return list_t : original list struct node
 */
list_t tList_init(char node)
{
	list_t new_list;

	new_list = (list_t)calloc(1, sizeof(list_t));
	if (new_list) {
		new_list->node = node;
	}
	return new_list;
}

/**
 * @fn tList_add
 * @biref add node to list struct
 * @param lst the main list struct
 * @param node the inserted node
 * @return list_t :return main list struct
 */
list_t tList_add(list_t lst, char node)
{
	list_t new_list = NULL;
	list_t tlst;

	if (!lst) {
		if (!(lst = (list_t)calloc(1, sizeof(list_t))))
			return NULL;

		lst->node = node;
	} else {
		if ((lst->node == 0) && !lst->next)
			lst->node = node;

		else{
			tlst = lst;
			while (tlst->next)
				tlst = tlst->next;

			if (!(new_list = (list_t)calloc(1, sizeof(list_t))))
				return NULL;
			
			new_list->node = node;
			tlst->next = new_list;
		}
	}

	return lst;
}

/**
 * @fn tList_delete 
 * @brief delete node from list struct 
 * @param lst : main list struct
 * @param node the removed node
 * @return list_t : main list struct after removed mode
 */
list_t tList_delete(list_t lst, char node)
{
	list_t orig = lst, prev_l = lst;

	if (!lst)
		return NULL;

	if (lst->node == node) {
		free(lst);
		memset(lst, 0, sizeof(list_t));
		return orig->next;
	}

	prev_l = lst;
	do {
		if (lst->node == node) {
			prev_l->next = lst->next;
			free(lst);
			memset(lst, 0, sizeof(list_t));
			break;
		}
		prev_l = lst;
	}while ((lst = lst->next));
	
	return orig;
}

/**
 * @fn tList_eraseAll 
 * @brief delete all nodes of list struct
 * @param lst main list struct
 */
void tList_eraseAll(list_t lst)
{
	list_t tl;
	
	if (!lst)
		return;

	do {
		tl = lst;
		free(tl);
		memset(tl, 0, sizeof(list_t));
	}while ((lst = lst->next));
}
