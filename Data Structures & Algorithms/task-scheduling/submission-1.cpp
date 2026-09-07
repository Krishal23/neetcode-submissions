class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> frq(26, 0);
        for (char task : tasks) {
            frq[task - 'A']++;
        }

        priority_queue<int> pq;
        for (int f : frq) {
            if (f > 0) pq.push(f);
        }

        queue<pair<int, int>> coolDown;
        int time = 0;

        while (!pq.empty() || !coolDown.empty()) {
            time++;

            if (!coolDown.empty() && coolDown.front().second == time) {
                pq.push(coolDown.front().first);
                coolDown.pop();
            }

            if (!pq.empty()) {
                int cnt = pq.top(); pq.pop();
                if (cnt > 1) {
                    coolDown.push({cnt - 1, time + n+1});
                }
            }
        }

        return time;
    }
};
