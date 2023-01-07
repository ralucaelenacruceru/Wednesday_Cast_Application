#include <iostream>

class totalCost: public transportCosts, public make_Up, public foodMenu, public AccommodationAndLocation{
private:
    static long long calculateCost(int nrDays){
        make_Up object1;
        try{
            object1.makeUpMenuCost();
        }catch (std::string message){
            std::cerr << message << std::endl;
        }
        foodMenu object2;
        try{
            object2.makeUpMenuCost();
        }catch (std::string message){
            std::cerr << message << std::endl;
        }
        int nCast = reusableFunctions::countCast();
        long long totalCost = 0;

        totalCost = transpCost((nCast)) * 2 + object1.makeUpMenuCost() * nrDays + object2.makeUpMenuCost() * nrDays + accommodationCost() * nrDays + drinksCost() * nrDays +
                locationCost(nrDays);

        long long transport = transpCost((nCast)) * 2;
        long long makeUp =  object1.makeUpMenuCost() * nrDays;
        long long foodMenu = object2.makeUpMenuCost() * nrDays;
        long long accommodation = accommodationCost() * nrDays;
        long long drinks = drinksCost() * nrDays;
        long long location  =  locationCost(nrDays);
        long long TCOST = totalCost;

        std::fstream fout;
        std::fstream fout1;
        fout.open("totalCost.csv", std::ios::out | std::ios::app);
        fout << "------ NUMBER OF DAYS: " << nrDays << " ------" << std::endl;
        fout <<"Transportation: " << transport <<" lei"<<" ------- "<< ceil(transport * 0.22) << " $  (dollars)" <<std::endl;
        fout <<"Make Up: " << makeUp <<" lei"<<" ------- "<< ceil(makeUp * 0.22) << " $  (dollars)" <<std::endl;
        fout <<"Food Menu: " << foodMenu << " lei"<<" ------- "<< ceil(foodMenu * 0.22) << " $  (dollars)" <<std::endl;
        fout <<"Accommodation"<< accommodation <<" lei"<<" ------- "<< ceil(drinks * 0.22) << " $  (dollars)" <<std::endl;
        fout << "Location: " << location <<" lei"<<" ------- "<< ceil(location * 0.22) << " $  (dollars)" <<std::endl;
        fout << "------ TOTAL COST ------" << std::endl;
        fout << totalCost << " lei" <<" ------- "<< TCOST << " $  (dollars)" <<std::endl;
        fout << std::endl;

        fout1.open("totalCostRomana.csv", std::ios::out | std::ios::app);
        fout1 << "------ NUMARUL DE ZILE: " << nrDays << " ------" << std::endl;
        fout1 <<"Transport: " << transport <<" lei"<<" ------- "<< ceil(transport * 0.22) << " $  (dolari)" <<std::endl;
        fout1 <<"Make Up: " << makeUp <<" lei"<<" ------- "<< ceil(makeUp * 0.22) << " $  (dolari)" <<std::endl;
        fout1 <<"Meniu Mancare: " << foodMenu << " lei"<<" ------- "<< ceil(foodMenu * 0.22) << " $  (dolari)" <<std::endl;
        fout1 <<"Cazare: "<< accommodation <<" lei"<<" ------- "<< ceil(drinks * 0.22) << " $  (dolari)" <<std::endl;
        fout1 << "Locatie: " << location <<" lei"<<" ------- "<< ceil(location * 0.22) << " $  (dolari)" <<std::endl;
        fout1 << "------ COST TOTAL ------" << std::endl;
        fout1 << totalCost << " lei" <<" ------- "<< TCOST << " $  (dolari)" <<std::endl;
        fout1 << std::endl;

        return totalCost;
    }

public:

    static void getCost(int nrDays){
        std::cout << calculateCost(nrDays) << " ";
    }


};


