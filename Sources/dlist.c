#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "../Headers/dlist.h"

Dlist dlist_new() {
    Dlist s1 = {NULL, NULL, 0};
    return s1;
}

uint32_t dlist_length(const Dlist *list){
    assert(list != NULL);
    return list->length;
}

static Node* _get_new_node_(int32_t val){
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode->data = val;
    newnode->next = NULL;
    newnode->prev = NULL;

    return newnode;
}

Dlist* dlist_addnode_head(Dlist *list, int32_t val){
    assert(list != NULL);
    Node *new_node = _get_new_node_(val);

    new_node->next = list->head;
    if (list->head != NULL){
        list->head->prev = new_node;
    }

    list->head = new_node;

    if (list->tail == NULL){
        list->tail = new_node;
    }
    ++list->length;

    assert(( list->length == 1 && list->head == list->tail) || 
           (list->length > 1 && list->head != list->tail ));

    return list;
}



Dlist*   dlist_addnode_tail(Dlist *list, int32_t val){
    assert(list != NULL);
    Node *new_node = _get_new_node_(val);

    if(list->tail != NULL) {
        list->tail->next = new_node;
        new_node->prev = list->tail;
        list->tail = new_node;
    }
    else{
        list->head = list->tail = new_node; 
    }

    ++list->length;

    assert(( list->length == 1 && list->head == list->tail) || 
           (list->length > 1 && list->head != list->tail ));

    return list;

}



uint8_t dlist_lookup(const Dlist *list, int32_t key) {
    assert (list != NULL);
    Node *cur = list->head;

    for ( cur = list->head ; cur != NULL; cur = cur->next ){
        if (cur->data == key ){
            break;
        }
    }
    //if (cur != NULL) { return 1;} else { return 0;}
    return (cur != NULL);
}


Dlist* dlist_delnode_head(Dlist *list) {
    assert(list != NULL);

    if (list->head != NULL) {
        list->head = list->head->next;
        list->head->prev = NULL;
        if (list-> head == NULL) {
            list->tail = NULL;
        }
        --list->length;
    }
    return list;
}


Dlist* dlist_delnode_tail(Dlist *list) {
    assert (list !=NULL);
    Node *last, *cur;

    if (list->tail !=NULL) {
        last = list->tail;
        if (list->head == list->tail){
            list->head = list->tail = NULL;
        }
        else {
            for(cur = list->head; cur->next !=last; cur = cur->next);
            list->tail = cur;
            cur->next = NULL;
        }
        --list->length;
        free(last);
    }

    return list;
}



Dlist* dlist_addnode_afterspecifiedelement(Dlist *list, int32_t val, int32_t specifiedval) {
    assert(list != NULL);
    Node *newnode = _get_new_node_(val);
    Node *cur, *temp;

    for(cur = list->head; cur != NULL; cur = cur->next){
        
        if ( cur->data == specifiedval){
            newnode->prev = cur;
            newnode->next = cur->next;
            cur->next = newnode;
            ++list->length;
            break;
        }
    }

    if (newnode->next != NULL){
        temp = newnode->next;
        temp->prev = newnode;
    }

   return list;
}


Dlist* dlist_deletenode_specifiedelement(Dlist *list, int32_t specifiedval){
    assert(list != NULL);
    Node *cur, *temp;

    if (list->head != NULL && list->head->data == specifiedval ) {
        list->head = list->head->next;
        list->head->prev = NULL;
        if (list-> head == NULL) {
            list->tail = NULL;
        }
        --list->length;
    }

    else if (list->tail->data == specifiedval){
        if (list->head == list->tail){
            list->head = list->tail = NULL;
        }
        else {
            list->tail = list->tail->prev;
            list->tail->next = NULL;
        }
        --list->length;
    } 

    else {
        
       for(cur = list->head; cur->data != specifiedval; cur = cur->next){
          temp = cur->next;
           if(temp->data == specifiedval){
               temp = temp->next;
               cur->next = temp;
               temp->prev = cur;
               --list->length;
               break;
           }
       }
    }

   return list;
}
