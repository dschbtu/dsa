struct PriorityQueue
{
    int *arr;
    int capaicity;
    int type;           // 1 for max , 0 for min
    int count;
};

PriorityQueue *Create(int cap,int type)
{
    PriorityQueue *pq=(PriorityQueue *)malloc(sizeof(PriorityQueue));
    pq->type=type;
    pq->count=0;
    pq->capaicity=cap;
    pq->arr=(int *)malloc(sizeof(int)*cap);
    return pq;
}

int parent(PriorityQueue *pq,int n)
{
    if(n>pq->count)
        return -1;
    return (n-1)/2;
}

int LeftChild(PriorityQueue *pq,int n)
{
    int left=2*n+1;
    if(left>=pq->count)
        return -1;
    return left;
}

int RightChild(PriorityQueue *pq,int n)
{
    int right=2*n+2;
    if(right>=pq->count)
        return -1;
    return right;
}

int GetMax(PriorityQueue *pq)
{
    if(pq->type==0 or pq->count==0)
        return -1;
    return pq->arr[0];
}

int GetMin(PriorityQueue *pq)
{
    if(pq->type==1 or pq->count==0)
        return -1;
    return pq->arr[0];
}

void PercolateDown(PriorityQueue *pq,int n)
{
    int l=LeftChild(pq,n),r=RightChild(pq,n);
    if(pq->type==1)
    {
        int maxi,temp;
        if(l!=-1 && pq->arr[l]>pq->arr[n])
            maxi=l;
        else
            maxi=n;
        if(r!=-1 && pq->arr[r]>pq->arr[maxi])
            maxi=r;
        if(maxi!=n)
        {
            temp=pq->arr[maxi];
            pq->arr[maxi]=pq->arr[n];
            pq->arr[n]=temp;
            PercolateDown(pq,maxi);
        }
    }
    else
    {
        int mini,temp;
        if(l!=-1 && pq->arr[l]<pq->arr[n])
            mini=l;
        else
            mini=n;
        if(r!=-1 && pq->arr[r]<pq->arr[mini])
            mini=r;
        if(mini!=n)
        {
            temp=pq->arr[mini];
            pq->arr[mini]=pq->arr[n];
            pq->arr[n]=temp;
            PercolateDown(pq,mini);
        }
    }
}

int Delete(PriorityQueue *pq)
{
    if(pq->count==0)
        return -1;
    int data=pq->arr[0];
    pq->arr[0]=pq->arr[pq->count-1];
    pq->count--;
    PercolateDown(pq,0);
    return data;
}

void Insert(PriorityQueue *pq,int data)
{
    pq->count++;
    int i=pq->count-1;
    if(pq->type==1)
    {
        while(i>0 && data>pq->arr[(i-1)/2])
        {
            pq->arr[i]=pq->arr[(i-1)/2];
            i=(i-1)/2;
        }
        pq->arr[i]=data;
    }
    else
    {
        while(i>0 && data<pq->arr[(i-1)/2])
        {
            pq->arr[i]=pq->arr[(i-1)/2];
            i=(i-1)/2;
        }
        pq->arr[i]=data;
    }
}
