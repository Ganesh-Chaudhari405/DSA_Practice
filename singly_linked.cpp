#include<iostream>
using namespace std;

//singly linked list basic insert and delete operations

struct Node 
{
int data;
Node *next;
Node(int val)
{
this->data=val;
this->next=NULL;

}

};
//first insert
struct Node * binsert(struct Node *head,int data)
{

	Node *nnode=new Node(data);
	nnode->next=head;
	head=nnode;
	return head;	
}
//last insert

void linsert(Node *&head,int data)
{
	Node *n1=new Node(data);

   if(head==NULL)
   {
   	head=n1;

   }
else{
    Node *temp=head;

	while(temp->next)
	{
		temp=temp->next;
	}

	temp->next=n1;
}
}

int len(Node *head)
{
	int c=0;
	while(head)
      {
      	c++;
      	head=head->next;
      }
      return c;

}


void minsert(Node *&head,int data,int ind)
{
	
   if(ind>len(head) || ind<0)
   {
     cout<<"not possible";
   }
  else if(ind==0)
  {
           head=binsert(head,data);
  }
  else if(ind==len(head))
  {
  	linsert(head,data);

  }
  else
  {
  	Node *n2=new Node(data);
  	Node *temp=head,*prev;
    for(int i=0;i<ind;i++)
    {
      prev=temp;
      temp=temp->next;

    }

    prev->next=n2;
    n2->next=temp;


  }

}

int fdel(Node *&head)
{
	if(head==NULL)
		 cout<<"not passible";
	else
	{
		Node *del=head;
		head=head->next;
        return del->data;
	}	
return 0;

}
int ldel(Node *&head)
{

	if(head==NULL)
		 cout<<"not passible";
	else
	{ Node *del=head,*temp;
		while(del->next)
		{
			temp=del;
			del=del->next;

		}
		temp->next=NULL;
       int vl=del->data;
       delete(del);
       return vl;
	}	
return 0;

}



void dis(Node *head)
{
	while(head)
	{
		 cout<<head->data<<" ";
		 head=head->next;
       
       }
}

int main()
{
	Node *head=NULL;

	//head=binsert(head,10);
   //head=binsert(head,20);

	linsert(head,10);
	linsert(head,20);
	linsert(head,30);
	minsert(head,50,0);
	minsert(head,100,4);
	minsert(head,20,1); 
	dis(head);
	cout<<"After deletion"<<endl;

	cout<<"deleted"<<fdel(head)<<endl;
	cout<<"  "<<ldel(head)<<endl;
	//mdel(head,2);
    dis(head);
	


}
