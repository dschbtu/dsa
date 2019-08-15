
struct QueueNode
{
    int data;
    QueueNode *next;
};

struct MyQueue {
    private:
    	QueueNode *front;
    	QueueNode *rear;

    public:
	bool isEmpty()
    	void push(int);
    	int pop();
	int peek();
};

bool MyQueue:: isEmpty()
{
    if(front==NULL)
	return true;
    return false;
}


void MyQueue:: push(int x)
{
    QueueNode *temp = (QueueNode *)malloc(sizeof(QueueNode));
    temp->data=x;
    temp->next=NULL;
    if(isEmpty())
    {
        front=temp;
        rear=temp;
        return;
    }
    rear->next=temp;
    rear=temp;
}

int MyQueue :: pop()
{
    if(isEmpty())
        return -1;
    int p = front->data;
    if(front==rear)
    {
        delete(front);
        front=NULL;
        rear=NULL;
    }
    else
    {
        QueueNode *temp=front;
        front=front->next;
        free(temp);
    }
    return p;
}

int MyQueue:: peek()
{
    if(isEmpty())
	return -1;
    return front->data;
}
