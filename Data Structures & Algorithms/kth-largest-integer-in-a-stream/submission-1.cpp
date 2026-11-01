class KthLargest {
    int capacity;
    int size=0;
    vector<int> h;
public:
    int parent(int i){ return (i-1)/2;}
    int left (int i){ return 2*i+1;}
    int right (int i){return 2*i+2;}
    void heapify(int i){
        int lt= left(i), rt= right(i);
        int smallest=i;

        if (lt<size && h[lt]<h[i])
            smallest=lt;
        if (rt<size && h[rt]<h[smallest])
            smallest=rt;
        
        if (smallest!=i){
            swap(h[smallest], h[i]);
            heapify(smallest);
        }
    }

    void insert (int val){
        h.push_back(val);
        for (int i=size-1; i!=0 && h[parent(i)]>h[i];)
            {
                swap(h[i], h[parent(i)]);
                i=parent(i);
            }
    }
    KthLargest(int k, vector<int>& nums) {
        capacity=k;
        for (int i=0; i<nums.size(); i++)
            add(nums[i]);
    }
    
    int add(int val) {
        if (size!=capacity){
            size++;
            insert(val);
        }else{
            if (val>h[0])
            {
                h[0]=val;
                heapify(0);
            }
        }
        return h[0];
    }
};
