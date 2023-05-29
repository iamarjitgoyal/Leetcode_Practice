class ParkingSystem {
private:
    int availableSpaces[4];
    
public:
    ParkingSystem(int big, int medium, int small) {
        availableSpaces[1] = big;
        availableSpaces[2] = medium;
        availableSpaces[3] = small;
    }
    
    bool addCar(int carType) {
        if (availableSpaces[carType] > 0) {
            availableSpaces[carType]--;
            return true;
        }
        return false;
    }
};
