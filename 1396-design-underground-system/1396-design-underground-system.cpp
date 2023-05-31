class UndergroundSystem {
private:
    struct CheckInInfo {
        string stationName;
        int time;
    };

    struct TravelInfo {
        double totalTime;
        int count;
    };

    unordered_map<int, CheckInInfo> checkIns;
    map<pair<string, string>, TravelInfo> travelTimes;

public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        checkIns[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        CheckInInfo checkInInfo = checkIns[id];
        
        double travelTime = t - checkInInfo.time;
        
        pair<string, string> stations = {checkInInfo.stationName, stationName};
        travelTimes[stations].totalTime += travelTime;
        travelTimes[stations].count++;
        
        checkIns.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        pair<string, string> stations = {startStation, endStation};
        TravelInfo travelInfo = travelTimes[stations];
        
        return travelInfo.totalTime / travelInfo.count;
    }
};
