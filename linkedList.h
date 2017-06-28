#include <cstddef>
#include <iostream>
#include <stdlib.h>


using namespace std;
class node 
{
   private:
     int data;
     node *next;
   public:
    node(){
    }
    void setData(int value)
    {
       data = value;   
    } 
    void setNext(node *nextNode)
    {
       next = nextNode; 
    }
    int getData()
    {
       return data;
    }
    node *getNext()
    {
       return next;
    }
};

class list
{
   private:
   node *head, *tail;

   public:
   list()
   {
	head = NULL; 
        tail = NULL;	
   }

   void createNode(int value)
   {
     node *newNode = new node; 
     newNode->setData(value);
     newNode->setNext(NULL);

     if(head == NULL)
     {
        head = newNode;
        tail = newNode;
        newNode = NULL;
     }
     else
     {
	tail->setNext(newNode);	
        tail = newNode;
     }
   }
    

   void displayNode()
   {
     if (head == NULL)
     {
       return;
     }
     node *iter = head;
     while( iter != NULL)
     {
	cout << iter->getData() <<endl;;
        iter = iter->getNext();
     }

   }
   
   //Insertion Time Complexity O(1) 
   void insert_start(int value)
   {
      node *tmpNode = new node();
      tmpNode->setData(value);
      tmpNode->setNext(head);
      head = tmpNode;
   }
   void insert_end(int value)
   {
      node *tmpNode = new node();
      tmpNode->setData(value);
      tmpNode->setNext(NULL);
    
      if (head == NULL)
      {
           head = tmpNode;
           tail = tmpNode;
      } 
      else
      {
        tail->setNext(tmpNode);
        tail = tmpNode;
      }
   }
   
  //Deletion Time Complexity O
  void delete_position(int position)
  {
     int iteration = 1;
     node *tmpNode = head;
     node *nextNode = head;
     //Check if head is empty
     if (head == NULL)
     {
          cout <<"nothing to delete"<<endl;
          exit;
     }
     else if (position == 1)
     {
         if (tail == head)
         {
	   tail = NULL;
           head = NULL;
         } 
         else head = head->getNext();
     }
     else
     {
	while (iteration++ < position)
        {
          tmpNode  = nextNode;
	  nextNode = tmpNode->getNext();
          if (nextNode == NULL)
          {
	     cout <<"Only have" << iteration+1 << "nodes" <<endl;
             break;
          }
        }
        tmpNode->setNext(nextNode->getNext());
     }
  }
};

