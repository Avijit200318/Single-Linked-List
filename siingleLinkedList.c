#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int info;
    struct node*link;
}n;

void display(n*head)
{
    n*x;
    x=head;
    if(head==NULL)
    {
        printf("the list is empty");
        return;
    }
    else
    {
        while(x!=NULL)
        {
            printf("%d ",x->info);
            x=x->link;
        }
    }
}

void search(n*head)
{
    n*x;
    x=head;
    int num,count=0,i=0;
    if(head==NULL)
    {
        printf("the list is empty\n");
    }
    else
    {
        printf("enter the number you want to search:");
        scanf("%d",&num);
        while(x!=NULL)
        {
            count++;
            x=x->link;
        }
        x=head;
        while(x!=NULL)
        {
            if(x->info==num)
            {
                printf("the number is present in the list\n");
                break;
            }
            else
            {
                i++;
            }
            x=x->link;
        }
        if(i==count)
        {
            printf("the number is not present in the list\n");
        }
    }
}

n*insertFront(n*head)
{
    n*ptr,*x=head;
    ptr=(n*)malloc(sizeof(n));
    printf("enter the number you want to insert:");
    scanf("%d",&ptr->info);
    ptr->link=NULL;
    if(head==NULL)
    {
        head=ptr;
    }
    else
    {
        ptr->link=x;
        head=ptr;
    }
    return head;
}

n*insertEnd(n*head)
{
    n*ptr,*x;
    x=head;
    ptr=(n*)malloc(sizeof(n));
    printf("enter the info:");
    scanf("%d",&ptr->info);
    ptr->link=NULL;
    if(head==NULL)
    {
        head=ptr;
    }
    else
    {
        while(x->link!=NULL)
        {
            x=x->link;
        }
        x->link=ptr;
    }
    return head;
}

n*deleteFront(n*head)
{
    n*x;
    x=head;
    if(head==NULL)
    {
        printf("delete is not posible\n");
    }
    else
    {
        head=head->link;
        free(x);
    }
    return head;
}

n*deleteEnd(n*head)
{
    n*x=head,*y;
    if(head==NULL)
    {
        printf("the list is empty\n");
        return head;
    }
    if(head->link==NULL)
    {
        free(x);
        head=NULL;
        return head;
    }
    else
    {
        while(x->link!=NULL)
        {
            y=x;
            x=x->link;
        }
        y->link=NULL;
        free(x);
    }
    return head;
}

n*insert(n*head)
{
    n*x,*ptr;
    x=head;
    int pos,count=0,i=1;
    printf("enter the position:");
    scanf("%d",&pos);
    while(x!=NULL)
    {
        count++;
        x=x->link;
    }
    x=head;
    if(pos>count+1)
    {
        printf("invalid position\n");
    }
    ptr=(n*)malloc(sizeof(n));
    printf("enter the info:");
    scanf("%d",&ptr->info);
    ptr->link=NULL;
    if(pos==1)
    {
        ptr->link=head;
        head=ptr;
        return head;
    }
    else
    {
        while(i<pos-1)
        {
            x=x->link;
            i++;
        }
        ptr->link=x->link;
        x->link=ptr;
    }
    return head;
}

n*delete(n*head)
{
    n*x,*y;
    x=head;
    int pos,i=1,count=0;
    printf("enter the position you want to delete:");
    scanf("%d",&pos);
    while(x!=NULL)
    {
        count++;
        x=x->link;
    }
    x=head;
    if(pos>count)
    {
        printf("invalid position\n");
        return head;
    }
    if(pos==1)
    {
        head=head->link;
        free(x);
    }
    else
    {
        while(i<pos)
        {
            y=x;
            x=x->link;
            i++;
        }
        y->link=x->link;
        free(x);
    }
    return head;
}

n*insertBeData(n*head)
{
    n*x,*ptr;
    x=head;
    int data,a=0,count=0;
    if(head==NULL)
    {
        printf("the list is  already empty\n");
        return head;
    }
    printf("enter the data before you want to insert:");
    scanf("%d",&data);
    while(x!=NULL)
    {
        count++;
        x=x->link;
    }
    x=head;
    while(x!=NULL)
    {
        if(x->info==data)
        {
            break;
        }
        else
        {
            a++;
        }
        x=x->link;
    }
    if(count==a)
    {
        printf("the info is not present in the list\n");
        return head;
    }
    x=head;
    if(data==head->info)
    {
        ptr=(n*)malloc(sizeof(n));
        printf("enter the info:");
        scanf("%d",&ptr->info);
        ptr->link=NULL;
        ptr->link=x;
        head=ptr;
        return head;
    }
    ptr=(n*)malloc(sizeof(n));
    printf("enter the info:");
    scanf("%d",&ptr->info);
    ptr->link=NULL;
    while((x->link)->info!=data)
    {
        x=x->link;
    }
    ptr->link=x->link;
    x->link=ptr;
    return head;
}

n*insertAfterData(n*head)
{
    n*x,*ptr;
    x=head;
    int data,count=0,a=0;
    if(head==NULL)
    {
        printf("list is empty so it has no data");
        return head;
    }
    printf("enter the data after you want to insert:");
    scanf("%d",&data);
    while(x!=NULL)
    {
        count++;
        x=x->link;
    }
    x=head;
    while(x!=NULL)
    {
        if(x->info==data)
        {
            break;
        }
        else
        {
            a++;
        }
        x=x->link;
    }
    if(count==a)
    {
        printf("the data is not present in the list\n");
        return head;
    }
    x=head;
    ptr=(n*)malloc(sizeof(n));
    printf("enter the info:");
    scanf("%d",&ptr->info);
    ptr->link=NULL;
    while(x->info!=data)
    {
        x=x->link;
    }
    ptr->link=x->link;
    x->link=ptr;
    return head;
}

n*deleteBeData(n*head)
{
    n*x,*y;
    x=head;
    int data,count=0,a=0;
    if(head==NULL)
    {
        printf("the list is empty\n");
        return head;
    }
    printf("enter the data before you want to delete:");
    scanf("%d",&data);
    while(x!=NULL)
    {
        count++;
        x=x->link;
    }
    x=head;
    while(x!=NULL)
    {
        if(x->info==data)
        {
            break;
        }
        else
        {
            a++;
        }
        x=x->link;
    }
    if(a==count)
    {
        printf("the data is not present in the list\n");
        return head;
    }
    x=head;
    if(head->info==data)
    {
        printf("the is only one info in list so delete is not posible\n");
        return head;
    }
    if(head->link->info==data)
    {
        head=head->link;
        free(x);
        return head;
    }
    while((x->link)->info!=data)
    {
        y=x;
        x=x->link;
    }
    y->link=x->link;
    free(x);
    return head;
}

n*deleteAfterData(n*head)
{
    n*x,*y;
    x=head;
    int data,count=0,a=0;
    if(head==NULL)
    {
        printf("the list is empty\n");
        return head;
    }
    printf("enter the data after you want to delete:");
    scanf("%d",&data);
    while(x!=NULL)
    {
        count++;
        x=x->link;
    }
    x=head;
    while(x!=NULL)
    {
        if(x->info==data)
        {
            break;
        }
        else
        {
            a++;
        }
        x=x->link;
    }
    if(a==count)
    {
        printf("the data is not present in the list\n");
        return head;
    }
    if(x->link==NULL)
    {
        //this if case represent two case-1.if there is only one element 2.if the data is the last element.
        printf("delete is not posible \n");
        return head;
    }
    while(y->info!=data && x->link!=NULL)
    {
        y=x;
        x=x->link;
    }
    y->link=x->link;
    free(x);
    
    return head;

}

void maxMin(n*head)
{
    n*x=head;
    int max=x->info,min=x->info;
    while(x!=NULL)
    {
        if(max<x->info)
        {
            max=x->info;
        }
        if(min>x->info)
        {
            min=x->info;
        }
        x=x->link;
    }
    printf("\nmax=%d and min=%d\n",max,min);
}

int main()
{
    n*head=NULL,*current,*ptr;
    int ans,ch;
    while(1)
    {
        ptr=(n*)malloc(sizeof(n));
        printf("enter the info:");
        scanf("%d",&ptr->info);
        ptr->link=NULL;
        if(head==NULL)
        {
            head=ptr;
            current=ptr;
        }
        else
        {
            current->link=ptr;
            current=ptr;
        }
        printf("do you want to continue:");
        scanf("%d",&ans);
        if(ans==0)
        {
            break;
        }
    }
    while(1)
    {
        printf("\n1.display\n2.search\n3.insert at the begening\n4.insert at the end\n5.delete at the begening\n");
        printf("6.delete at the end\n7.insert any position\n8.delete at any position\n9.insert element before data\n");
        printf("10.insert after data\n11.delete before data\n12.delete after data\n13.max and min\n14.exit\n");
        printf("enter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:display(head);
                break;
            case 2:search(head);
                break;
            case 3:head=insertFront(head);
                break;
            case 4:head=insertEnd(head);
                break;
            case 5:head=deleteFront(head);
                break;
            case 6:head=deleteEnd(head);
                break;
            case 7:head=insert(head);
                break;
            case 8:head=delete(head);
                break;
            case 9:head=insertBeData(head);
                break;
            case 10:head=insertAfterData(head);
                break;
            case 11:head=deleteBeData(head);
                break;
            case 12:head=deleteAfterData(head);
                break;
            case 13:maxMin(head);
                break;
            case 14:exit(0);
        }
    }
}

