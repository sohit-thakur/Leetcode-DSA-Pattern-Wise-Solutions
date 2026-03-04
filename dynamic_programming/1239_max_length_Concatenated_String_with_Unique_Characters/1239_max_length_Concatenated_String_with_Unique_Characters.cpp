class Solution {
public:
    bool hasDuplicate(string &temp, string &s) {
        vector<int> freq(26, 0);
        for(char c : temp) {
            freq[c - 'a']++;
            }

        for(char c : s) {
            if(freq[c - 'a'] > 0) 
                return true;
            freq[c - 'a']++;
        }

        return false;
    }

    int solve(int i, vector<string>& arr, string temp, int n) {
        if(i >= n) 
            return temp.size();

        int exclude = solve(i + 1, arr, temp, n);
        int include = 0;
        if(!hasDuplicate(temp, arr[i])) {
            include = solve(i + 1, arr, temp + arr[i], n);
        }

        return max(include, exclude);
    }

    int maxLength(vector<string>& arr) {
        int n = arr.size();
        string temp = "";
        int i = 0;
        return solve(i, arr,temp, n);
    }
};