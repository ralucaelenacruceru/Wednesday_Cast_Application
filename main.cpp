#include <iostream>
#include <utility>
#include <math.h>
#include "randomNameGen.hpp"
#include "transport.hpp"
#include "reusableFunctions.hpp"
#include "makeUp.hpp"
#include "foodMenu.hpp"
#include "accomodation.hpp"
#include "totalCost.hpp"







class CastMember{
protected:
    std::string fullName;
    std::string jobDescription;
    std::string monsterClass;
    std::string foodMenu;

public:

    ///constructor and destructor
    ~CastMember() {

        std::cout << "The object is being deleted" << std::endl;
    }

    // Default ( constructor + initialization constructor )
    CastMember( std::string fullname = "default", std::string jobDescription = "default", std::string monsterClass = "default", std::string foodMenu = "default"):
    fullName{std::move(fullname)}, jobDescription{std::move(jobDescription)}, monsterClass{std::move(monsterClass)}, foodMenu{std::move(foodMenu)}
    {
    }


    // Getters
    std::string getFullName(){
        return fullName;
    }


    std::string getJobDes(){
        return  jobDescription;
    }

    std::string getMonClass(){
        return  monsterClass;
    }


    std::string getfoodChoice(){
        return  foodMenu;
    }

};










int main() {


///generating the 132 random names
std::cout << "....generating 132 random names as extras" << std::endl;
    unsigned seed = time(0);
    srand(seed);
    for (int i = 0; i < 132; i++)
        randomNameGen::GenerateAndSaveToFile();


///generating the random assignment to make up categories

make_Up object1;
std::cout << "....generating random assignment for make up to actors and extras" <<std::endl;
try {
    object1.AssignCategory();
}catch (std::string message){
    std::cerr << message << std::endl;
}



/// u assign the cast randomly the different types of diets
foodMenu object2;
std::cout << "....generating random assignment for food menu to the entire cast" << std::endl;
try {
    object2.AssignCategory();
}catch (std::string message){
    std::cerr << message << std::endl;
}
/////u create the 3 days menu randomly
std::cout << "....generating a 3 day menu" << std::endl;
foodMenu::menuGen();

///getting the total cost
std::cout << "....calculating the total cost" << std::endl;

totalCost::getCost(30);
totalCost::getCost(45);
totalCost::getCost(60);
totalCost::getCost(100);

CastMember object3("Cruceru Raluca", "extra", "vampire", "flexitarian");
std::cout << std::endl;
std::cout << object3.getFullName() << " " << object3.getJobDes() << " " << object3.getMonClass() << " " << object3.getfoodChoice() << " " << std::endl;









    return 0;
}
