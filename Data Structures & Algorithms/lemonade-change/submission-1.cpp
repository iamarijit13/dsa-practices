class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fives = 0, tens = 0;

        for (int bill : bills) {
            if (bill == 5) fives++;
            else if (bill == 10) tens++;

            int change = bill - 5;
            if (change == 5) 
                if (fives > 0) fives--; 
                else return false;
            else if (change == 10) 
                if (tens > 0) tens--; 
                else if (fives >= 2) fives -= 2; 
                else return false;
            else if (change == 15) 
                if (tens > 0 && fives > 0) tens--, fives--; 
                else if (fives >= 3) fives -= 3; 
                else return false; 
        }
        return true;
    }
};