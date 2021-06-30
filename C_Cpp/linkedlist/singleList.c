#include <stdio.h>
#include <stdbool.h>

struct singleList {
	struct singleList *next;
	int val;
};

struct singleList_head {
	struct singleList *head;
};

bool is_empty(struct singleList_head *head)
{
	return head->head == NULL;
}

void dump(struct singleList_head *head)
{
	struct singleList *tmp = head->head;
	int idx = 0;

	while (tmp) {
		printf("[%02d]: %08d\n", idx++, tmp->val);
		tmp = tmp->next;
	}
}

void insert(struct singleList **prev, struct singleList *elem)
{
	if (!prev)
		return;

	elem->next = *prev;
	*prev = elem;
}

void insert_head(struct singleList_head *head, struct singleList *elem)
{
	insert(&head->head, elem);
}

struct singleList* del(struct singleList **prev)
{
	struct singleList *tmp;

	if (!prev)
		return NULL;
	if (*prev == NULL)
		return NULL;
	tmp = *prev;
	*prev = (*prev)->next;
	tmp->next = NULL;

	return tmp;
};

struct singleList* delete_head(struct singleList_head* head)
{
	return del(&head->head);
};

struct singleList** search(struct singleList_head* head, int target)
{
	struct singleList **prev, *tmp;

	for (prev = &head->head, tmp = *prev;
	     tmp && (tmp->val < target);
	     prev = &tmp->next, tmp = *prev)
		;

	return prev;
};

void reverse(struct singleList_head* head)
{
	struct singleList_head tmp = {NULL};
	struct singleList *elem;

	while (!is_empty(head)) {
		elem = delete_head(head);
		insert_head(&tmp, elem);
	}

	head->head = tmp.head;
}

bool is_cyclic(struct singleList_head* head)
{
	struct singleList *s1, *s2;

	s1 = s2 = head->head;

	while(s1 && s2) {
		s1 = s1->next;
		s2 = s2->next ? s2->next->next:s2->next;

		if (s1 == s2)
			return true;
	}
	return false;
}

struct singleList* middle(struct singleList_head* head)
{
	struct singleList *s1, *s2;
	struct singleList pseudo_head;

	pseudo_head.next = head->head;
	s1 = s2 = &pseudo_head;

	while (true) {
		if (!s2 || !s2->next)
			return s1;
		s1 = s1->next;
		s2 = s2->next->next;
	}

	return NULL;
};

int main()
{
	struct singleList_head head = {NULL};
	struct singleList lists[10];
	struct singleList **prev;
	int idx;

	for (idx = 0; idx < 10; idx++) {
		lists[idx].val = idx;
		lists[idx].next = NULL;
	}

	insert_head(&head, &lists[6]);
	insert_head(&head, &lists[5]);
	insert_head(&head, &lists[4]);
	insert_head(&head, &lists[1]);
	insert_head(&head, &lists[0]);

	printf("=== insert 0, 1, 4, 5, 6\n");
	dump(&head);

	prev = search(&head, 2);
	insert(prev, &lists[2]);
	printf("=== insert 2\n");
	dump(&head);

	printf("middle elem is %d\n", middle(&head)->val);

	prev = search(&head, 2);
	if ((*prev) && ((*prev)->val == 2))
		printf("The list contains 2\n");
	else
		printf("The list not contains 2\n");

	del(prev);
	prev = search(&head, 2);
	printf("After remove 2\n");
	if ((*prev) && ((*prev)->val == 2))
		printf("The list contains 2\n");
	else
		printf("The list not contains 2\n");
	dump(&head);

	printf("After reverse \n");
	reverse(&head);
	dump(&head);

	printf("middle elem is %d\n", middle(&head)->val);

	lists[0].next = &lists[6];
	printf("list is%s cyclic\n", is_cyclic(&head)?"":" not");

	return 0;
}