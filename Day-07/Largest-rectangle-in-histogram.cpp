class Solution {
public:
    void prevSmaller(vector<int>& heights,vector<int>& prev){
        stack<int>st;
        st.push(-1);
        for(int i=0;i<heights.size();i++){
            while(st.top()!=-1 && heights[st.top()]>=heights[i]) st.pop();
            prev.push_back(st.top());
            st.push(i);
        }
    }
    void nextSmaller(vector<int>& heights,vector<int>& next){
        stack<int>st;
        st.push(-1);
        for(int i=heights.size()-1;i>=0;i--){
            while(st.top()!=-1 && heights[st.top()]>=heights[i]) st.pop();
            if(st.top()==-1){
                next.push_back(heights.size());
            }else{
                next.push_back(st.top());
            }
            st.push(i);
        }
        reverse(next.begin(),next.end());
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int>prev;
        prevSmaller(heights,prev);
        vector<int>next;
        nextSmaller(heights,next);
        int ans = 0;
        for(int i=0;i<heights.size();i++){
            int b = next[i]-prev[i]-1;
            int area = heights[i]*b;
            ans = max(area,ans);
        }
        return ans;
    }
};
