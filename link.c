#include<stdio.h>
#include<stdlib.h>


typedef int data_t;
struct link{
  data_t data;
  struct link *next;  
}link_t;

link_t *create_link()
{
  link_t *head = malloc(sizeof(link_t));
  if(NULL == head)
  return NULL;
  head -> next = NULL;
  return head;
}

int ins_head_link(link_t *head, const data_t *data)
{
  link_t *newnode = malloc(sizeof(link_t));
  newnode -> next = head -> next;
  head -> next = newnode;
  newnode -> data = *data;
  return 0;
}

int del_head_link(link_t *head)
{
  link_t * temp;
  temp = head -> next;
  head -> next = temp -> next;
  free(temp);
  return 0;
}

void print_link(link_t * head)
{
  while(head -> next != NULL)
  {
    printf("%d\n",head -> next -> data);
    head = head -> next ;
  }
  return ;
}
int main(int argc,const char *argv[])//argc 是外部参数的个数，而argv是一个数组可以存放外部命令的。
{
  link_t *p;
  int data;
  p = create_link();
  for(data = 0; data < 8; data ++)
  {
    ins_head_link(p, &data);
  }
  print_link(p);
  del_head_link(p);
  print_link(p);
  return 0;
}
