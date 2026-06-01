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
int DelElByData(struct point** list, int x, int y);
int PrintList(struct point* list); // With debug logic
int AddElToHead(struct point** list, int x, int y);
int AddElToTail(struct point** list, int x, int y);
int AddElAtPos(struct point** list, size_t pos, int x, int y);
int AddElBefore(struct point** list, size_t pos, int x, int y);
int AddElAfter(struct point* list, size_t pos, int x, int y);
int FindEl(struct point* list, int x, int y);

int main()
{
    printf("Hello World!\n");
    return 0;
}

int FindEl(struct point* list, int x, int y)
{
  if(!list) return -1;
  if(!*list) return 1;

  struct point* fHead = *list;

  while((fHead->x != x || fHead->y != y) && fHead->next)
    fHead = fHead->next;

  if(fHead->x == x && fHead->y == y)
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
    return 2; // 2 - el does not exists

  return 0;
}

int AddElAfter(struct point* list, size_t pos, int x, int y)
{
  if(!list) return -1;
  if(pos == 0) return 2; // 2 - pos does not exists

  struct point* ptrNewEl = (struct point*)malloc(sizeof(struct point));
  if(!ptrNewEl) return 3;
  ptrNewEl->x = x;
  ptrNewEl->y = y;

  size_t i = 0;
  struct point* fHead = list;

  for(i = 1; i < pos && fHead; i++, fHead = fHead->next);

  if(i == pos && fHead)
  {
    ptrNewEl->next = fHead->next;
    ptrNewEl->prev = fHead;
    if(fHead->next)
      fHead->next->prev = ptrNewEl;
    fHead->next = ptrNewEl;

    return 0;
  }
  else
    return 2; // 2 - pos does not exists

  return 0;
}

int AddElBefore(struct point** list, size_t pos, int x, int y)
{
  if(!list) return -1;
  if(!*list) return 1;

  struct point* ptrNewEl = (struct point*)malloc(sizeof(struct point));
  if(!ptrNewEl) return 3;
  ptrNewEl->x = x;
  ptrNewEl->y = y;

  if(pos == 1) // if before head
  {
    ptrNewEl->next = *list;
    ptrNewEl->prev = NULL;
    (*list)->prev = ptrNewEl;
    *list = ptrNewEl;

    return 0;
  }

  size_t i = 0;
  struct point* fHead = *list;

  for(i = 1; i < pos && fHead; i++, fHead = fHead->next);

  if(i == pos && fHead)
  {
    ptrNewEl->next = fHead;
    ptrNewEl->prev = fHead->prev;
    fHead->prev = ptrNewEl;
    ptrNewEl->prev->next = ptrNewEl;

    return 0;
  }
  else
    return 2; // 2 - pos does not exists

  return 0;
}

int AddElAtPos(struct point** list, size_t pos, int x, int y)
{
  if(!list) return -1;
  if(pos == 0) return 2; // 2 - pos does not exists

  struct point* ptrNewEl = (struct point*)malloc(sizeof(struct point));
  if(!ptrNewEl) return 3;
  ptrNewEl->x = x;
  ptrNewEl->y = y;

  if(pos == 1) // if before head
  {
    ptrNewEl->next = *list;
    ptrNewEl->prev = NULL;
    if(*list)
      (*list)->prev = ptrNewEl;
    *list = ptrNewEl;

    return 0;
  }

  if(!*list) return 1;

  size_t i = 0;
  struct point* fHead = *list;

  pos--;
  for(i = 1; i < pos && fHead; i++, fHead = fHead->next);

  if(i == pos && fHead)
  {
    ptrNewEl->next = fHead->next;
    ptrNewEl->prev = fHead;
    if(fHead->next)
      fHead->next->prev = ptrNewEl;
    fHead->next = ptrNewEl;

    return 0;
  }
  else
    return 2; // 2 - pos does not exists

  return 0;
}

int AddElToTail(struct point** list, int x, int y)
{
  if(!list) return -1;

  struct point* ptrNewEl = (struct point*)malloc(sizeof(struct point));
  if(!ptrNewEl) return 3;
  ptrNewEl->next = NULL;
  ptrNewEl->x = x;
  ptrNewEl->y = y;

  struct point* fHead = *list;
  while(fHead && fHead->next)
    fHead = fHead->next; // Go to tail

  ptrNewEl->prev = fHead;
  if(*list)
    fHead->next = ptrNewEl;
  else
    *list = ptrNewEl;

  return 0;
}

int AddElToHead(struct point** list, int x, int y)
{
  if(!list) return -1;
  // if(!*list) return 1;

  struct point* ptrNewEl = (struct point*)malloc(sizeof(struct point));
  if(!ptrNewEl) return 3;
  ptrNewEl->x = x;
  ptrNewEl->y = y;
  ptrNewEl->prev = NULL;
  ptrNewEl->next = *list;
  if(ptrNewEl->next) // empty list check
    ptrNewEl->next->prev = ptrNewEl;
  *list = ptrNewEl;

  return 0;
}

int DelElByData(struct point** list, int x, int y)
{
  if(!list) return -1;
  if(!*list) return 1;

  struct point* fHead = *list;

  while((fHead->x != x || fHead->y != y) && fHead->next)
    fHead = fHead->next;

  if(fHead->x == x && fHead->y == y)
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
    return 2; // 2 - el does not exists

  return 0;
}

int DelElByPos(struct point** list, size_t pos)
{
  if(!list) return -1;
  if(!*list) return 1;

  size_t i = 0;
  struct point* fHead = *list;

  for(i = 1; i < pos && fHead; i++, fHead = fHead->next);

  if(i == pos && fHead)
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

int PrintList(struct point* list)
{
  if(!list) return 1;

  do
  {
    printf("x = %d\ny = %d\n", list->x, list->y);
    list = list->next;
  }while(list->next);

  // FOR DEBUG - BACK LINKS CHECK
  while(list)
  {
    printf("bx = %d\nby = %d\n", list->x, list->y);
    list = list->prev;
  }
  // ----------------------------

  return 0;
}
