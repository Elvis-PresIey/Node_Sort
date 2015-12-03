#include "CNode.h"
#include "MyList.h"

CNode* CreateList(int count, const int* vals) {
  if (count <= 0) return 0;
  CNode *head = new CNode;
  head->val = vals[0];
  CNode *prev = head;
  for (int i = 1; i < count; ++i) {
    CNode *node = new CNode;
    node->val = vals[i];
    prev->next = node;
    prev = node;
  }
  prev->next = 0;
  return head;
}

void print(CNode* pFirst) {
	printf("\n[ ");
	while (pFirst) {
		printf("%d, ", pFirst -> val);
		pFirst = pFirst -> next;
	}
	printf("]\n");
}

CNode* sort(CNode** pFirst) {
	if (!(*pFirst) || !((*pFirst) -> next)) return *pFirst;

	if (!((*pFirst) -> next -> next)) {
		if ((*pFirst) -> val > (*pFirst) -> next -> val) {
			CNode *tmp = (*pFirst) -> next;
			(*pFirst) -> next -> next = (*pFirst);
			(*pFirst) -> next = NULL;
			(*pFirst) = tmp;
		}
    return *pFirst;
	}

	CNode *tmp = NULL;
	bool flag = true;
	while (flag) {
		flag = false;
		tmp = (*pFirst);
		if (tmp -> val > tmp -> next -> val) {
			flag = true;
			CNode *tmpNext = (*pFirst) -> next;
			CNode *tmpNextNext = (*pFirst) -> next -> next;
			(*pFirst) -> next -> next = (*pFirst);
			(*pFirst) -> next = tmpNextNext;
			(*pFirst) = tmpNext;
		}

		while (tmp -> next -> next) {
			if ((tmp -> next -> val) > (tmp -> next -> next -> val)) {
				flag = true;
				CNode* tmpPrev = tmp -> next;
				CNode* tmpCurr = tmp -> next -> next;
				CNode* tmpNext = tmp -> next -> next -> next;
				tmpCurr -> next = tmpPrev;
				tmpPrev -> next = tmpNext;
				tmp -> next = tmpCurr;
			}
			tmp = tmp -> next;
		}
	}
	return *pFirst;
}
