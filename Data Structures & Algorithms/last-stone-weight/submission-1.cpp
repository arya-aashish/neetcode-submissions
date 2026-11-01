class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> que;

        for (int &num: stones)
            que.push(num);
        
        while (que.size()>1){
            int x=que.top();
            que.pop();
            int y=que.top();
            que.pop();

            int res=0;
            if (x!=y)
                res=x-y;
            if (res!=0)
                que.push(res);
        }
        if (que.size()==0)
            return 0;
        else 
            return que.top();
    }
};
