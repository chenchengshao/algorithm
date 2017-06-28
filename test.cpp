#include "linkedList.h"

int main(int argc, char *argv[])
{
   list *newList = new list();
   newList->createNode(2);
   newList->createNode(1);
   newList->displayNode();

   newList->insert_start(3);
   newList->displayNode();

   newList->insert_end(10);
   newList->displayNode();

   newList->delete_position(1);
   newList->displayNode();
   newList->delete_position(3);
   newList->displayNode();
}
