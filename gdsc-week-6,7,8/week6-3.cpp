class Solution {
public:
    int trap(vector<int>& height) {
        //for bettr approach watch take u forward vdo.
        int n=height.size();
        int maxl[n];
        int maxr[n];
        int water[n];
        int ml=INT_MIN;
        int mr=INT_MIN;
        for(int i=0;i<n;i++)
        {
            if(height[i]>ml)
            {
                ml=height[i];
            
            }
            maxl[i]=ml;
        }
        for(int i=n-1;i>=0;i--)
        {
            if(height[i]>mr)
            {
                mr=height[i];
            
            }
            maxr[i]=mr;
        }
        
        for(int i=0;i<n;i++)
            water[i]=(min(maxl[i],maxr[i]))-height[i];
        int sum=0;
        for(int i=0;i<n;i++)
           sum+=water[i];
        
        return sum;
    }
};