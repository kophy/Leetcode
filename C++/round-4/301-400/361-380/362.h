class HitCounter {
public:
    /** Initialize your data structure here. */
    HitCounter() {
        window_count = 0;
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        ++hitcounts[timestamp];
        ++window_count;
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        evictOlderThan(timestamp - 300);
        return window_count;
    }
    
private:
    map<int, int> hitcounts;
    int window_count;
    
    void evictOlderThan(int timestamp) {
        while (!hitcounts.empty() && hitcounts.begin()->first <= timestamp) {
            window_count -= hitcounts.begin()->second;
            hitcounts.erase(hitcounts.begin());
        }
    }
};