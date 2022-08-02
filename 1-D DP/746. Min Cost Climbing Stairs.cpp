//Solution1
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        cost.push_back(0);
        
        for (int i=cost.size()-3; i>=0; i--) {
            cost[i] += min(cost[i+1], cost[i+2]);
        }
        
        return min(cost[0], cost[1]);
            
    }
};

// Solution 2
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int down1=0;
        int down2=0;
        
        for (int i=2; i<=cost.size(); i++) {
            int tmp = down1;
            down1 = min(down1 + cost[i-1], down2 + cost[i-2]);
            down2 = tmp;
        }
        // return min(down1, down2); //wrong
        return down1;
    }
};

