// https://leetcode.com/problems/maximum-frequency-stack/description/

class FreqStack {
public:
    FreqStack() {
        max_freq = 0;
    }
    
    void push(int x) {
        max_freq = max(max_freq, ++freq[x]);
        level[freq[x]].push(x);
    }
    
    int pop() {
        if (!max_freq) return 0;
        int res = level[max_freq].top();
        freq[res]--;
        level[max_freq].pop();
        if (level[max_freq].size() == 0)
            max_freq--;
        return res;
    }
private:
    int max_freq;
    unordered_map<int, int> freq;
    unordered_map<int, stack<int>> level;
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack obj = new FreqStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 */
