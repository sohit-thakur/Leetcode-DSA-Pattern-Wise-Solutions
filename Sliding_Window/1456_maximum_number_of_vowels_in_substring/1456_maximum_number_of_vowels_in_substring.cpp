class Solution {
public:
    bool isVowel(char c){
        return c =='a' || c =='e' || c =='i' || c =='o' || c =='u';
    }
    int maxVowels(string s, int k) {
        int n = s.length();
        int maxCount = 0;
        int count = 0;
        for(int i=0;i<k;i++){
            if(isVowel(s[i])){
                count++;
            }
        }
        maxCount = count;
        for(int j=k;j<n;j++){
            if(isVowel(s[j])){
                count++;
            }
            if(isVowel(s[j-k])){
                count--;
            }
            maxCount = max(maxCount,count);
        }
        return maxCount;
    }
};