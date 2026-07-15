class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>>car(n);
        for(int i = 0; i<n; i++){
            car[i] = {position[i], speed[i]};
        }
        sort(car.begin(), car.end(), [](const auto& l, const auto& r){
            return l.first > r.first;
        });
        int fleets = 0;
        float prevT = -1;
        for(auto& c: car){
            float time = (target - c.first)*1.0/c.second;
            if(time>prevT){
                fleets++;
                prevT = time;
            }
        }
        return fleets;
    }
};
