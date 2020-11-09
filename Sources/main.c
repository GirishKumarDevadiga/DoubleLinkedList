#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../Headers/dlist.h"

void test_addnode_head(){
   Dlist s = dlist_new();
   Dlist *list = &s;

   list = dlist_addnode_head(list, 10);
   list = dlist_addnode_head(list, 20);
   list = dlist_addnode_head(list, 30);
   list = dlist_addnode_head(list, 40);

   assert(dlist_length(list) == 4);
   assert(dlist_lookup(list, 30) == 1);
}

void test_addnode_tail(){
   Dlist s = dlist_new();
   Dlist *list = &s;

   list = dlist_addnode_tail(list, 10);
   list = dlist_addnode_tail(list, 20);
   list = dlist_addnode_tail(list, 30);
   list = dlist_addnode_tail(list, 40);

   assert(dlist_length(list) == 4);
   assert(dlist_lookup(list, 30) == 1);
}

void test_delnode_head(){
   Dlist s = dlist_new();
   Dlist *list = &s;

   list = dlist_addnode_head(list, 10);
   list = dlist_addnode_head(list, 20);
   list = dlist_addnode_head(list, 30);
   list = dlist_addnode_head(list, 40);

   assert(dlist_length(list) == 4);
   assert(dlist_lookup(list, 40) == 1);

   list = dlist_delnode_head(list);
   assert(dlist_length(list) == 3);
   assert(dlist_lookup(list, 40) == 0);
}


void test_delnode_tail(){
   Dlist s = dlist_new();
   Dlist *list = &s;

   list = dlist_addnode_tail(list, 10);
   list = dlist_addnode_tail(list, 20);
   list = dlist_addnode_tail(list, 30);
   list = dlist_addnode_tail(list, 40);

   assert(dlist_length(list) == 4);
   assert(dlist_lookup(list, 40) == 1);

   list = dlist_delnode_tail(list);
   assert(dlist_length(list) == 3);
   assert(dlist_lookup(list, 40) == 0);
}

void test_addnodeatspecifiedvalue(){
    Dlist s1 = dlist_new();
    Dlist *list = &s1;

    list = dlist_addnode_tail(list, 10);
    list = dlist_addnode_tail(list, 20);
    list = dlist_addnode_tail(list, 40);
    list = dlist_addnode_tail(list, 50);
    assert (dlist_length(list) == 4);
    list = dlist_addnode_afterspecifiedelement(list, 30, 20);
    assert (dlist_length(list) == 5);
    assert (dlist_lookup(list, 30) == 1);
    list = dlist_addnode_afterspecifiedelement(list, 60, 50);
    assert (dlist_length(list) == 6);
    assert (dlist_lookup(list, 60) == 1);

}


void test_deletenodespecifiedvalue(){
    Dlist s1 = dlist_new();
    Dlist *list = &s1;

    list = dlist_addnode_tail(list, 10);
    list = dlist_addnode_tail(list, 20);
    list = dlist_addnode_tail(list, 30);
    list = dlist_addnode_tail(list, 40);
    list = dlist_addnode_tail(list, 50);
    assert (dlist_length(list) == 5);
    list = dlist_deletenode_specifiedelement(list, 10);
    assert (dlist_length(list) == 4);
    assert (dlist_lookup(list, 10) == 0);
    list = dlist_deletenode_specifiedelement(list, 40);
    assert (dlist_length(list) == 3);
    assert (dlist_lookup(list, 40) == 0);
    list = dlist_deletenode_specifiedelement(list, 50);
    assert (dlist_length(list) == 2);
    assert (dlist_lookup(list, 50) == 0);

}

int main(){
 
  test_addnode_head();
  test_addnode_tail();
  test_delnode_head();
  test_delnode_tail();
  test_addnodeatspecifiedvalue();
  test_deletenodespecifiedvalue();

  return 0;

}