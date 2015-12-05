#ifndef GTEST_MYLIST_MYLIST_H
#define GTEST_MYLIST_MYLIST_H

#include <stdlib.h>
#include <stdio.h>
#include <exception>
#include "CNode.h"

CNode* CreateList(int count, const int* vals);

void print(CNode* pFirst);

CNode* sort(CNode** pFirst);

#endif  // GTEST_MYLIST_MYLIST_H
