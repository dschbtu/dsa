
typedef long long int ll;
const ll MAXN=10000005;

class Stack
{
    private:
        ll arr[MAXN];
        ll curr=-1;
    
    public:
        bool isFull()
        {
            if(curr==MAXN-1)
                return true;
            return false;
        }

        bool isEmpty()
        {
            if(curr==-1)
                return true;
            return false;
        }

        void push(ll data)
        {
            if(isFull())
                return;
            curr++;
            arr[curr]=data;
        }

        ll pop()
        {
            if(isEmpty())
                return -1;
            ll temp=arr[curr];
            arr[curr]=0;
            curr--;
            return temp;
        }

        ll peek()
        {
            if(isEmpty())
                return -1;
            return arr[curr];
        }

        ll size()
        {
            return curr+1LL;
        }
};
