
typedef long long int ll;
const int MAXN = 100;
class Queue
{
    private:
    
        int arr[MAXN];
        int front=-1;
        int rear=-1;
    
    public:
    
        bool isFull()
        {
            return ((rear+1)%MAXN==rear);
        }
        
        bool isEmpty()
        {
            return front==-1;
        }
        
        void enQueue(int data)
        {
            if(isFull())
                return;
            rear=(rear+1)%MAXN;
            arr[rear]=data;
            if(front==-1)
                front=rear;
        }
        
        int deQueue()
        {
            if(isEmpty())
                return -1;
            int temp=arr[front];
            if(front==rear)
            {
                front=-1;
                rear=-1;
            }
            else
                front=(front+1)%MAXN;
            return temp;
        }
        
        int peek()
        {
            if(isEmpty())
                return -1;
            return arr[front];
        }
        
        int size()
        {
            return (MAXN+rear-front+1)%MAXN;
        }
        
};
