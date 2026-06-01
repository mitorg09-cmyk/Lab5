# Lab5
Contains set of functions for work with dual-linked lists
Contains hardcode tests

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
struct point* FindEl(struct point* list, int x, int y);