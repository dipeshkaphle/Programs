class heap:
    # Can be initialized with a function and an empty queue
    # Or we can also provide an array as a starting point
    def __init__(self,func,arr=[]):
        self.size=len(arr)
        self.cmp=func
        self.arr=arr.copy()
        self.heapify()

    # This will heapify the element at given index
    # A smaller helper function that will help us in
    # heapifying the queue
    # For example: We are making a min heap
    # Provided an index i, it will make the element at
    # index i less than the element at index 2*i +1 and 2*i+2
    def heapifyAtIndex(self,index):
        swapped = False
        br1=2*index+1
        br2=br1+1
        if(br1<self.size):
            if(self.cmp(self.arr[br1],self.arr[index])==1):
                self.arr[br1],self.arr[index]=self.arr[index],self.arr[br1]
                self.heapifyAtIndex(br1)
                swapped = True
        if(br2<self.size):
            if(self.cmp(self.arr[br2],self.arr[index])==1):
                self.arr[br2],self.arr[index]=self.arr[index],self.arr[br2]
                self.heapifyAtIndex(br2)
                swapped = True
        return swapped


    # Heapifying
    # will start from the index size/2 and heapify every node
    # FInally the entire array is made into the desired heap
    # When we calculate the average cost of this, it turns out to be
    # Linear time process to do it for an unordered array
    def heapify(self):
        for i in range(self.size//2,-1,-1):
            self.heapifyAtIndex(i)
    


    # Heap extract operation
    # Extracts the root and fixes everything else to preserve
    # THe heap property
    # THe call to heapifyAtIndex is responsible for keeping the heap
    # property intact
    # Fixing the heap invariant takes O(LogN) as we bubble down the heap
    # maintaining the heap invariant throughout the array
    def extract(self):
        if(self.size == 0):
            raise Exception("Heap empty")
        self.arr[0],self.arr[-1]=self.arr[-1],self.arr[0]
        x=self.arr[-1]
        self.arr.pop()
        self.size-=1
        self.heapifyAtIndex(0)
        return x

    # Shows the top element of the heap
    def top(self):
        if(self.size == 0):
            raise Exception("Heap empty")
        return self.arr[0]


    # Inserts to the heap
    # Also keeps the heap property intact
    # We bubble up from the end of the array
    # This has complexity of O(logN) i.e height of heap
    def insert(self,data):
        self.arr.append(data)
        self.size+=1
        i=self.size-1
        i= (i-1)//2
        while(i>=0):
            if(not self.heapifyAtIndex(i)):
                break
            i=(i-1)//2
    
if(__name__ == "__main__"):
    arr=[3,2,1,4,5,6]
    a=heap(lambda x,y: 1 if (x<y) else 0,arr)
    a.insert(8)
    for i in range(3):
        print(a.extract())
        a.insert(20*i)
    for i in range(a.size):
        print(a.extract())
    try:
        a.extract()
    except(Exception):
        print("Caught")
    print(arr)

            
