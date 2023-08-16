class Solution {
public:
    int accountBalanceAfterPurchase(int purchaseAmount) 
    {
        int lastdigit = purchaseAmount%10;
        if(lastdigit<5)
        {
            purchaseAmount -=lastdigit;
            return 100 - purchaseAmount;
        }
        else{
            purchaseAmount += 10 - lastdigit;
            return 100- purchaseAmount;
        }
    }
};