class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int j=height.size()-1;
        int area = 0;
        while(i<j){
            int MinLen = min(height[i],height[j]);
            int breadth = j-i;
            int curr = MinLen*breadth;
            area = max(area,curr);
            if(height[i]<height[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return area;
    }
};