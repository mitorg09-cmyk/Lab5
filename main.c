#include <stdio.h>

struct point
{
  int x, y;
  struct point* next;
  struct point* prev;
};

int main()
{
    printf("Hello World!\n");
    return 0;
}

int DelElByHead(struct point** list)
{
  if(!list) return -1;
  if(!*list) return 1;

  struct point* ptrIx = *list;
  *list = (*list)->next;
  free(ptrIx);

  return 0;
}

int DelList(struct point** list)
{
  if(!list) return -1;
  if(!*list) return 1;

  struct point* ptrIx = NULL;
  while(*list)
  {
    ptrIx = *list;
    *list = (*list)->next;
    free(ptrIx);
  }

  return 0;
}
