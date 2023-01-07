#include <iostream>
#include <vector>


///parent class to use the methods you inherit

class reusableFunctions{
public:
    ///function to count the number of cast members
    static int countCast(){
        int count  = 0;
        std::string line;
        std::fstream file("cast.csv", std::ios::in);
        if (file.is_open()) {
            while (getline(file, line)) {
                count++;
            }
        } else

            std::cout << "Could not open the file\n";

        return count;
    }

    ///function that uses overloading for randomly assigning a monster class and a menu preference

///random assignment out of 5 categories
    static std::string randomAssignment(std::string category1, std::string  category2,std::string category3, std::string  category4, std::string category5){

        std::string categories[] = {category1, category2, category3, category4, category5};

        int chosen;

        chosen = rand() % 5;

        return categories[chosen];

    }

///random assignment out of 3 categories
    static std::string randomAssignment(std::string category1, std::string category2, std::string category3){

        std::string categories[] = {category1, category2, category3};

        int chosen;

        chosen = rand() % 3;

        return categories[chosen];

    }


    };


