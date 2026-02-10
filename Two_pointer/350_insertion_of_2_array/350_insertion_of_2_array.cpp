class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());

        int i=0;
        int j=0;
        vector<int> ans;
        while(i<nums1.size()&&j<nums2.size()){
            if(nums1[i]==nums2[j]){
                ans.push_back(nums1[i]);
                i++;
                j++;
            }
            else if(nums1[i]<nums2[j]){
                i++;
            }
            else{
                j++;
            }
        }
        return ans;
        
    }
};



/*class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        vector<int> ans;
        for(int x:nums1){
            mp[x]++;
        }
        for(int x:nums2){
            if(mp[x]>0){
                ans.push_back(x);
                mp[x]--;
            }
        }
        return ans;
    }
};*/