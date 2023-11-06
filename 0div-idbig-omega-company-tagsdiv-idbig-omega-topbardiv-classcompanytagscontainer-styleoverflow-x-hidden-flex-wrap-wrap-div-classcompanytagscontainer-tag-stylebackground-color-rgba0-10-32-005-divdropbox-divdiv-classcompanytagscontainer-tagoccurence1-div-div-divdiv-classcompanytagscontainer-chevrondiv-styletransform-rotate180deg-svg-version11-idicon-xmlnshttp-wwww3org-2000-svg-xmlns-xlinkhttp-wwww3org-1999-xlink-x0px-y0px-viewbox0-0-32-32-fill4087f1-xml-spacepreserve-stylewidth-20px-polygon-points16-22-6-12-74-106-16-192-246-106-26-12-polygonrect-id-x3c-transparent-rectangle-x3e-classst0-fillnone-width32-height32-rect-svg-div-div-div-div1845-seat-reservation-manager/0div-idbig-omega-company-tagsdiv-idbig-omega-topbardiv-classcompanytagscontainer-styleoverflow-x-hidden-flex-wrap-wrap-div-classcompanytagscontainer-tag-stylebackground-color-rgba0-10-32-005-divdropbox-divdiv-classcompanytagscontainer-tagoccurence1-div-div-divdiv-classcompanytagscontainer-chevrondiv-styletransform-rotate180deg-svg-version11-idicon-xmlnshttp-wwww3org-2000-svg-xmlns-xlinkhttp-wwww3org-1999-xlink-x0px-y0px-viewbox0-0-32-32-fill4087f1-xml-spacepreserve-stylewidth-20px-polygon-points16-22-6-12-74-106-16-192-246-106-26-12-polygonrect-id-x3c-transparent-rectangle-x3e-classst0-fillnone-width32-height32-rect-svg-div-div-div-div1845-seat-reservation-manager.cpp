class SeatManager {
private:
    priority_queue<int, vector<int>, greater<int>> available_seats;

public:
    SeatManager(int n) {
        for (int i = 1; i <= n; i++) {
            available_seats.push(i);
        }
    }

    int reserve() {
        if (!available_seats.empty()) {
            int reserved_seat = available_seats.top();
            available_seats.pop();
            return reserved_seat;
        } else {
            return -1;
        }
    }

    void unreserve(int seatNumber) {
        available_seats.push(seatNumber);
    }
};