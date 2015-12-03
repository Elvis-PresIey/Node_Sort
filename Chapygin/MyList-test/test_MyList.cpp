#include "MyList.h"
#include <gtest.h>

TEST(sort, can_sort) {
	int a[7] = {5, 4, 3, 10, 5, 1, 100};
	int ex[7] = {1, 3, 4, 5, 5, 10, 100};
	CNode* head = CreateList(7, a);
	sort(&head);
	for (int i = 0; i < 7; i++) {
		EXPECT_EQ(ex[i], head -> val);
		head = head -> next;
	}
}

TEST(sort, sorts_sorted) {
	int a[5] = {10, 20, 30, 40, 50};
	CNode* head = CreateList(5, a);
	sort(&head);
	for (int i = 0; i < 5; i++) {
		EXPECT_EQ(a[i], head -> val);
		head = head -> next;
	}
}

TEST(sort, sorts_null) {
	CNode* head = NULL;
	sort(&head);
	EXPECT_EQ(NULL, head);
}

TEST(sort, sorts_single_node) {
	CNode* head = new CNode;
	head -> val = 5;
	head -> next = NULL;
	sort(&head);
	EXPECT_EQ(5, head -> val);
	EXPECT_EQ(NULL, head -> next);
}
