// Insertion Sort for sorting the numbers in increasing order

/* 
    arr is the input vector which is to be sorted
    (0-based indexing)
    Worst Case Complexity-> O(n^2)
    Best Case Complexity-> O(n)
    
        */


void InsertionSort(vector<int>& arr)
{
    for(int i=1;i<arr.size();i++)
    {
        for(int j=i;j>0 && arr[j]<arr[j-1];j--)
        {
            swap(arr[j],arr[j-1]);
        }
    }
}


/*
    Loop Invariant->
        arr[0..i-1] is sorted
        
        *Initialization*-> Loop starts with i=1,Thus there is only one element                 before arr[1] i.e. arr[0] so it is already sorted.
        
        *Maintenance*-> Since we iterate the array backwards until the current              element is smaller than the previous element, thus we               place every element at its correct postion.The loop                 invariant is maintained in every iteration.
        
        *Termination*-> When the loop ends,the array is sorted in increasing                order.
        
            */