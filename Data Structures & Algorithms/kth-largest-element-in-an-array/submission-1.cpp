class Solution {
int size=0; int capacity;
vector <int> arr;
public:
    int parent (int i) {return (i-1)/2;}
    int left (int i) {return (2*i+1);}
    int right (int i) {return (2*i+2);}

    void heapify (int i){
        int lt= left(i), rt= right(i);
        int smallest= i;

        if (lt<size && arr[lt]<arr[smallest])
            smallest=lt;
        if (rt<size && arr[rt]<arr[smallest])
            smallest=rt;
        if (smallest!=i){
            swap(arr[i], arr[smallest]);
            heapify(smallest);
        }
    }

    void add(int x){
        size++; arr.push_back(x);
        for (int i=size-1; i!=0 && arr[parent(i)]>arr[i];){
            swap(arr[parent(i)],arr[i]);
            i=parent(i);
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        capacity=k;

        for (int i=0; i<nums.size(); i++){
            if (capacity!=size){
                add(nums[i]);
            }else{
                if(arr[0]<nums[i]){
                    arr[0]=nums[i];
                    heapify(0);
                }
            }
        }
        return arr[0];
    }
};
