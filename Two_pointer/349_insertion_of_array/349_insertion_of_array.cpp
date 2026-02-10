class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int i = 0, j = 0;
        vector<int> ans;

        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j]) {
                if (ans.empty() || ans.back() != nums1[i]){
                    ans.push_back(nums1[i]);
            }
            i++;
            j++;
        }
            else if (nums1[i] < nums2[j]) {
                i++;
            }
            else {
                j++;
            }
    }
        return ans;
    }
};
/*class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        vector<int> ans;
        for(int i:nums1){
            mp[i]++;
        }
        for(int i:nums2){
            if(mp.count(i)){
                ans.push_back(i);
                mp.erase(i);
            }
        }
        return ans;
    }
};*/

/*class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st(nums1.begin(),nums1.end());
        vector<int> ans;
        for(int x:nums2){
            if(st.count(x)>0){
                ans.push_back(x);
                st.erase(x);
            }
        }
        return ans;
    }
};*/
