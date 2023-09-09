/**
 * Definition for a street.
 * class Street {
 * public:
 *     Street(vector<int> doors);
 *     void openDoor();
 *     void closeDoor();
 *     bool isDoorOpen();
 *     void moveRight();
 *     void moveLeft();
 * };
 */
class Solution {
public:
    int houseCount(Street* street, int k) {
        for(int i=0;i<k;i++){
            street->closeDoor();
            street->moveRight();
        }

        int cnt = 0;
        while(street->isDoorOpen() == false){
            cnt++;
            street->openDoor();
            street->moveRight();
        }
        return cnt;
    }
};
