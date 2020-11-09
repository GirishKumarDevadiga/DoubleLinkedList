#include <stdint.h>
#ifndef SLIST_H_INCLUDED
#define SLIST_H_INCLUDED

typedef struct _node_ Node;

struct _node_
{
    int32_t data;
    Node *prev;
    Node *next;
};

typedef struct _dlist_ Dlist;

struct _dlist_ {
    Node *head;
    Node *tail; 
    uint32_t length;
};


Dlist dlist_new();
uint8_t dlist_lookup(const Dlist *list, int32_t key);
uint32_t dlist_length(const Dlist *list);
Dlist* dlist_addnode_head(Dlist *list, int32_t val);
Dlist*   dlist_addnode_tail(Dlist *list, int32_t val);
uint8_t dlist_lookup(const Dlist *list, int32_t key);
Dlist* dlist_delnode_head(Dlist *list);
Dlist* dlist_delnode_tail(Dlist *list);
Dlist* dlist_addnode_afterspecifiedelement(Dlist *list, int32_t val, int32_t specifiedval);
Dlist* dlist_deletenode_specifiedelement(Dlist *list, int32_t specifiedval);

#endif //SLIST_H_INCLUDED

