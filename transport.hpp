#include <iostream>
#include <vector>

class transportCosts{
private:
    ///function to calculate transportation costs
    static long long transpCost(int numberOfCast){
        long long result;

        result = numberOfCast % 50;

        if(result == 0)
            return (numberOfCast / 50) * 5680;
        else
            return ((numberOfCast / 50) + 1) * 5680;
    }

public:
    friend class totalCost;
};
