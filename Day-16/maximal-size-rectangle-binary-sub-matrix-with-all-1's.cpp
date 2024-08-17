class Solution {
public:
    void nextSmaller(vector<int>& v,vector<int>& next){
        stack<int>st;
        st.push(-1);
        for(int i=v.size()-1;i>=0;i--){
            while(st.top()!=-1 && v[i]<=v[st.top()]) st.pop();

            if(st.top()==-1){
                next.push_back(v.size());
            }else{
                next.push_back(st.top());
            }
            st.push(i);
        }
    }

    void prevSmaller(vector<int>& v,vector<int>& prev){
        stack<int>st;
        st.push(-1);
        for(int i=0;i<v.size();i++){
            while(st.top()!=-1 && v[i]<=v[st.top()]) st.pop();

            prev.push_back(st.top());
            st.push(i);
        }
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int>temp(m,0);
        int ans = INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                temp[j] = (matrix[i][j]=='1') ? temp[j]+1:0;
            }

            vector<int>prev;
            vector<int>next;
            prevSmaller(temp,prev);
            nextSmaller(temp,next);
            reverse(next.begin(),next.end());

            for(int k=0;k<m;k++){
                int area = temp[k]*(next[k]-prev[k]-1);
                ans = max(ans,area);
            }
        }
        return ans;
    }
};
