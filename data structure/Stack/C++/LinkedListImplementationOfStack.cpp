struct StackNode
{
    int data;
    StackNode *next;
    StackNode(int a)
    {
        data = a;
        next = NULL;
    }
};

class MyStack 
{
	private:
		StackNode *top;
	public :
	    void push(int);
	    int pop();
	    bool isEmpty();
	    int peek();
	    MyStack()
	    {
		top = NULL;
	    }
};

bool ::isEmpty()
{
	if(!top)
		return true;
	return false;
}

void MyStack ::push(int x) 
{
    StackNode *temp = (StackNode *)malloc(sizeof(StackNode));
    temp->data=x;
    temp->next=top;
    top=temp;
}

int MyStack ::pop() 
{
    if(isEmpty())
        return -1;
    int x = top->data;
    StackNode *temp=top;
    top=top->next;
    free(temp);
    return x;
}

int peek()
{
	if(isEmpty())
		return -1;
	return top->data;
}
