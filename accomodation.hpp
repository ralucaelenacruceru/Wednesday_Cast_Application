#include <iostream>
#include <vector>

class AccommodationAndLocation:public reusableFunctions{
private:

    static int accommodationCost(){

        int nrCast = countCast();

        std::vector<std::vector<std::string>> content;
        std::vector<std::string> row;
        std::string line, word;
        std::fstream file("cast.csv", std::ios::in);
        if (file.is_open()) {
            while (getline(file, line)) {
                row.clear();
                std::stringstream str(line);
                while (getline(str, word, ','))
                    row.push_back(word);
                content.push_back(row);
            }
        } else
            std::cout << "Could not open the file\n";

        int extras = 0;
        for (int i = 0; i < content.size(); i++) {
            if (content[i][1].find("extra") != std::string::npos ) {
                extras++;
            }
        }

        int originalCast = nrCast - extras;
        int accCost = 0;

        if(originalCast % 2 != 0){
            accCost = ((originalCast / 2) + 1) * 350;
        }else if(originalCast % 2 == 0)
            accCost = (originalCast / 2)  * 350;

        if(extras % 2 != 0){
            accCost = accCost + ((extras / 2) + 1) * 420;
        }else
            accCost = accCost + (extras / 2)  * 420;

        return accCost;
    }

    static long long locationCost(int nrDays){
        long long locCost = 0;
        locCost = 10000 * nrDays - 200 * (nrDays / 10);
        locCost = locCost * 0.2;
        return locCost;
    }




    friend class totalCost;

};

