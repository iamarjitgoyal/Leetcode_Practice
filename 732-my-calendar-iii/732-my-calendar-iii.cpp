class MyCalendarThree {
    map<int, int> timeline;
public:
    int book(int s, int e) {
        timeline[s]++;
        timeline[e]--;
        int ongoing = 0, k = 0;
        for (pair<int, int> t : timeline)
            k = max(k, ongoing = ongoing + t.second);
        return k;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */