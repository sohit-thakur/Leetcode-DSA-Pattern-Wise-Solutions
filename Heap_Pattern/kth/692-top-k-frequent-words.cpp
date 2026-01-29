class Solution {
public:
    struct cmp {
        bool operator()(const pair<int, string>& a,
                        const pair<int, string>& b) {
            if (a.first == b.first)
                return a.second < b.second; 
            return a.first > b.first;   
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {

        unordered_map<string, int> freq;
        for (string &w : words)
            freq[w]++;

        priority_queue<pair<int, string>,
                       vector<pair<int, string>>,
                       cmp> minHeap;

        for (auto &p : freq) {
            minHeap.push({p.second, p.first});
            if (minHeap.size() > k)
                minHeap.pop();
        }

        vector<string> result;
        while (!minHeap.empty()) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
