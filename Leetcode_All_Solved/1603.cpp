class ParkingSystem {
public:
    vector<int> car;
    ParkingSystem(int big, int medium, int small) {
        car = vector<int>({0, big, medium, small});
    }
    
    bool addCar(int carType) {
        if(car[carType] == 0) return false;
        car[carType]--;
        return true;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
