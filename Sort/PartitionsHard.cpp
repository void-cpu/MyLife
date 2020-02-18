#include <iostream>

using namespace std;

struct Node
{
    int value;
    Node *next;
};

//��ӡ����
void printLists(Node *head)
{
    while(NULL != head)
    {
        cout << head->value << " " ;
        head = head->next;
    }
    cout << endl;
}

//���������е�����
void swap(Node *a,Node *b)
{
    int tmp = a->value;
    a->value = b->value;
    b->value = tmp;
}


//���������еķ�������
void arrPartition(Node *arr,int len,int pivot)
{
    int index = 0;
    len--;
    while(index < len)
    {
        while(index < len && arr[index].value <= pivot)
            index++;
        swap(&arr[index],&arr[len]);
        while(index < len && arr[len].value >= pivot)
            len--;
        swap(&arr[index],&arr[len]);    
    }
}

//�ǽ����㷨
Node* listPartition1(Node *head,int pivot)
{
    if(NULL == head)
        return NULL;
    Node *cur = head;
    int len = 0;
    while(NULL != cur)    //ͳ��������
    {
        len++;
        cur = cur->next;
    }
    
    Node *arr = new Node[len];
    cur = head;
    for(int i=0;i<len;i++)
    {
        arr[i] = *cur;
        cur = cur->next;
    }
    arrPartition(arr,len,pivot); //����
    for(int i=1;i<len;i++)
    {
        arr[i-1].next = &arr[i];
        Node *ptr = head;
        head = head->next;
        delete ptr;
    }
    arr[len-1].next = NULL;
    delete head;
    return arr;
}

//�����㷨
Node *listPartition2(Node *head,int pivot)
{
    Node *sH = NULL;    //Сͷ
    Node *sT = NULL;    //Сβ
    Node *eH = NULL;    //���ͷ
    Node *eT = NULL;    //���β
    Node *bH = NULL;    //��ͷ
    Node *bT = NULL;    //��β

    while(NULL != head)
    {
        Node *next = head->next;
        head->next = NULL;

        if(head->value < pivot)
        {
            if(NULL == sH)
            {
                sH = head;
                sT = head;
            }
            else
            {
                sT->next = head;
                sT = head;
            }
        }
        else if(head->value == pivot)
        {
            if(NULL == eH)
            {
                eH = head;
                eT = head;
            }
            else
            {
                eT->next = head;
                eT = head;
            }    
        }
        else
        {
            if(NULL == bH)
            {
                bH = head;
                bT = head;
            }
            else
            {
                bT->next = head;
                bT = head;
            }
        }
        head = next;
    }    
    if(NULL != sT)    //С��������ȶ�
    {
        sT->next = eH;
        eT = (NULL == eT ? sT : eT);
    }

    if(NULL != eT)    //�ж����Ӵ��
        eT->next = bH;
    return NULL != sH ? sH : NULL != eH ? eH : bH;
}


int main()
{
    int arr[] = {9,0,4,5,1};
    Node *head1 = NULL;
    Node *ptr1 = NULL;
    Node *head2 = NULL;
    Node *ptr2 = NULL;
    for(int i=0;i<5;i++)
    {
        if(NULL == head1 && NULL ==head2)
        {
            head1 = new Node;
            head1->value = arr[i];
            head1->next = NULL;
            ptr1 = head1;
            
            head2 = new Node;
            head2->value = arr[i];
            head2->next = NULL;
            ptr2 = head2;
            continue;
        }
        ptr1->next = new Node;
        ptr1 = ptr1->next;
        ptr1->value = arr[i];
        ptr1->next = NULL;
        
        ptr2->next = new Node;
        ptr2 = ptr2->next;
        ptr2->value = arr[i];
        ptr2->next = NULL;
    }
    cout << "list before partiton: " << endl;
    printLists(head1);
    cout << "not ordered partition: " << endl;
    ptr1 = listPartition1(head1,3);
    printLists(ptr1);
    
    cout << "list before partiton: " << endl;
    printLists(head2);
    cout << "ordered partition: " << endl;
    ptr2 = listPartition2(head2,3);
    printLists(ptr2);
    return 0;
}
