class Solution {
public:
    void left(vector<int>& heights,vector<int>&ls)
    {
        int temp=-1;
        stack<pair<int,int>>s;
        for(int i=0;i<heights.size();i++)
        {
            if(s.empty())
                ls.push_back(temp);
            else if(s.size()>0 && s.top().first<heights[i])
                ls.push_back(s.top().second);
            else if(s.size()>0 && s.top().first>=heights[i])
            {
                while(s.size()>0 && s.top().first>=heights[i])
                    s.pop();
                if(s.empty())
                    ls.push_back(temp);
                else
                    ls.push_back(s.top().second);
            }
            s.push({heights[i],i});
            
        }
        
        
    }
    void right(vector<int>& heights,vector<int>& rs)
    {

        int temp=heights.size();
        stack<pair<int,int>>s;
        for(int i=temp-1;i>=0;i--)
        {
            if(s.empty())
                rs.push_back(temp);
            else if(s.size()>0 && s.top().first<heights[i])
                rs.push_back(s.top().second);
            else if(s.size()>0 && s.top().first>=heights[i])
            {
                while(s.size()>0 && s.top().first>=heights[i])
                    s.pop();
                if(s.empty())
                    rs.push_back(temp);
                else
                    rs.push_back(s.top().second);
            }
            s.push({heights[i],i});
            
        }
        reverse(rs.begin(),rs.end());
    }
    
    int largestRectangleArea(vector<int>& heights) {
        vector<int>ls;
        vector<int>rs;
        left(heights,ls);
        right(heights,rs);
        int maxarea=INT_MIN;
        for(int i=0;i<heights.size();i++)
        {
            maxarea=max(maxarea,(rs[i]-ls[i]-1)*heights[i]);
        }
     return maxarea;   
    }
};