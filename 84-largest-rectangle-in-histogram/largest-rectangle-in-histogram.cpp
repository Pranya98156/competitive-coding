class Solution {
private:
    vector<int> PrevSmaller(vector<int>& heights, int n) {
        stack<int> st;
        st.push(-1);
        vector<int> ans(n);
        for(int i = 0; i < n; i++) {
            int curr = heights[i];
            while(st.top() != -1 && heights[st.top()] >= curr) {
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> NextSmaller(vector<int>& heights, int n) {
        stack<int> st;
        st.push(-1);
        vector<int> ans(n);
        for(int i = n - 1; i >= 0; i--) {
            int curr = heights[i];
            while(st.top() != -1 && heights[st.top()] >= curr) {
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> next = NextSmaller(heights, n);
        vector<int> prev = PrevSmaller(heights, n);
        int area = 0;
        for(int i = 0; i < n; i++) {

            if(next[i] == -1)
                next[i] = n;
            int width = next[i] - prev[i] - 1;
            int newArea = heights[i] * width;
            area = max(area, newArea);
        }
        return area;
    }
};