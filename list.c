#include "list.h"

#include <string.h>

List* list_new() {
	List* list = malloc(sizeof(list));
	if (list == NULL) { return NULL; }
	list->head = NULL;
	return list;
}

void list_push(List* list, void* data, size_t data_size) {
	ListNode* new_list_node = malloc(sizeof(ListNode));
	if (new_list_node == NULL) { return; }
	new_list_node->data = data;
	new_list_node->data_size = data_size;
	new_list_node->next = NULL;

	if (list->head == NULL) { list->head = new_list_node; }
	else {
		ListNode* list_node = list->head;
		while (list_node->next != NULL) {
			list_node = list_node->next;
		}
		list_node->next = new_list_node;
	}
}

bool list_find(const List* list, const void* data, size_t data_size) {
	ListNode* list_node = list->head;
	while (list_node != NULL) {
		if (data_size == list_node->data_size) {
			if (!memcmp(data, list_node->data, list_node->data_size)) {
				return 1;
			}
		}
		list_node = list_node->next;
	}
	return 0;
}

void list_free(List* list) {
	if (list == NULL) { return; }
	while (list->head != NULL) {
		ListNode* list_node = list->head;
		if (list_node->data != NULL) { free(list_node->data); }
		list->head = list_node->next;
		free(list_node);
	}
	free(list);
}

