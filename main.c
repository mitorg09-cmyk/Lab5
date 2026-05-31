#include <stdio.h>
#include <stdlib.h>

struct point
{
  int x, y;
  struct point* next;
  struct point* prev;
};

int DelElByTail(struct point** list);
int DelElByHead(struct point** list);
int DelList(struct point** list);
int DelElByPos(struct point** list, size_t pos);

int main()
{
    printf("Hello World!\n");
    return 0;
}

int DelElByPos(struct point** list, size_t pos)
{
  if(!list) return -1;
  if(!*list) return 1;

  size_t i = 0;
  struct point* fHead = *list;

  for(i = 1; i < pos && fHead; i++, fHead = fHead->next);

  if(i == pos)
  {
    if(!(fHead->prev)) // if Head
    {
      *list = (*list)->next;
      (*list)->prev = NULL;
    }
    else // if just element
    {
      fHead->prev->next = fHead->next;
      if(fHead->next) // Tail check
        fHead->next->prev = fHead->prev;
    }
    free(fHead);
    return 0;
  }
  else
    return 2; // 2 - pos does not exists

  return 0;
}

int DelElByTail(struct point** list)
{
  if(!list) return -1;
  if(!*list) return 1;

  struct point* fHead = *list;
  while(fHead->next)
    fHead = fHead->next; // Go to tail

  if(!(fHead->prev)) // If it is Head
    *list = NULL;
  else
    fHead->prev->next = NULL;

  free(fHead);

  return 0;
}

int DelElByHead(struct point** list)
{
  if(!list) return -1;
  if(!*list) return 1;

  struct point* ptrIx = *list;
  *list = (*list)->next;
  (*list)->prev = NULL;
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
