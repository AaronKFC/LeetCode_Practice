// Solution1 
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> visit;
        
        while (visit.find(n) == visit.end()) {
            visit.insert(n);
            n = squareSum(n);
            if (n == 1) {
                return true;
            }
        }
        return false;
    }
    
private:
    int squareSum(int n) {
        int res = 0;
        while (n > 0) {
            res += pow((n%10), 2);
            n /= 10;
        }
        return res;
    }
};


// Solution2
class Solution {
public:
    bool isHappy(int n) {
        int slow = n;
        int fast = squareSum(n);
        
        while (slow != fast) {
            fast = squareSum(squareSum(fast));
            slow = squareSum(slow);
        }
        if (fast==1) {
            return true;
        } else {
            return false;
        }
    }
    
private:
    int squareSum(int n) {
        int res = 0;
        while (n > 0) {
            res += pow((n%10), 2);
            n /= 10;
        }
        return res;
    }
};


