class Solution {
    int size = 0;
    int capacity = 0;
    vector<pair<int, pair<int, int>>> arr;
public:
    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

    void construct(pair<int, pair<int, int>> h) {
        size++;
        arr.push_back(h);
        for (int i = size - 1; i != 0 && arr[parent(i)].first < arr[i].first;) {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    void maxHeapify(int i) {
        int largest = i;
        int lt = left(i), rt = right(i);

        if (lt < size && arr[lt].first > arr[largest].first)
            largest = lt;
        if (rt < size && arr[rt].first > arr[largest].first)
            largest = rt;
        
        if (largest != i) {
            swap(arr[i], arr[largest]);
            maxHeapify(largest);
        }
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        capacity = k;

        for (int i = 0; i < points.size(); i++) {
            int x = points[i][0], y = points[i][1];
            int dis = x * x + y * y;

            if (capacity != size) {
                construct({dis, {x, y}});
            } else {
                if (arr[0].first > dis) {
                    arr[0] = {dis, {x, y}}; 
                    maxHeapify(0); 
                }
            }
        }

        vector<vector<int>> res;
        for (int i = 0; i < size; i++) {
            res.push_back({arr[i].second.first, arr[i].second.second});
        }
        return res;
    }
};