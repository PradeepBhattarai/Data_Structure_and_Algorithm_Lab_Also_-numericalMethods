#include<iostream>
using namespace std;
struct Node
{
   int coeff;
   int power;
   struct Node *next;
};
void create_node(int x, int y, struct Node **temp)
{
   struct Node *a, *r;
   a = *temp;
   if(a == NULL)
   {
      r =new Node();
      r->coeff = x;
      r->power = y;
      *temp = r;
      r->next = new Node();
      r = r->next;
      r->next = NULL;
   } 
   else
   {
      r->coeff = x;
      r->power = y;
      r->next = new Node();
      r = r->next;
      r->next = NULL;
   }
}
//adding two polynomials

void add(struct Node *p1, struct Node *p2, struct Node *result)
{
   while(p1->next && p2->next) 
   {
      if(p1->power > p2->power) 
      {
         result->power = p1->power;
         result->coeff = p1->coeff;
         p1 = p1->next;
      }
      else if(p1->power < p2->power)
      {
         result->power = p2->power;
         result->coeff = p2->coeff;
         p2 = p2->next;
      } 
      else 
      {
         result->power = p1->power;
         result->coeff = p1->coeff+p2->coeff;
         p1 = p1->next;
         p2 = p2->next;
      }
      result->next = new Node();
      result = result->next;
      result->next = NULL;
   }
   while(p1->next || p2->next)
   {
      if(p1->next)
      {
         result->power = p1->power;
         result->coeff = p1->coeff;
         p1 = p1->next;
      }
      if(p2->next)
      {
         result->power = p2->power;
         result->coeff = p2->coeff;
         p2 = p2->next;
      }
      result->next = new Node();
      result = result->next;
      result->next = NULL;
   }
}
//display function to print resultant polynomial
void display(struct Node *node)
{
   while(node->next != NULL)
   {
      cout<<node->coeff<<"x^"<<node->power;
      node = node->next;
      if(node->next != NULL)
         cout<<" + ";
   }
}
int main()
{
   struct Node *p1 = NULL, *p2 = NULL, *result = NULL;
   //creating polynomial1 p1 and polynomial2 p2
   create_node(4,5,&p1);
   create_node(2,3,&p1);
   create_node(5,0,&p1);
   create_node(2,3,&p2);
   create_node(5,2,&p2);
   create_node(5,1,&p2);
   cout<<"polynomial 1:";
   display(p1);
   cout<<"\npolynomial 2:";
   display(p2);
   result = new Node();
   add(p1, p2, result);
   cout<<"\nresultant polynomial: ";
   display(result);
   return 0;
}