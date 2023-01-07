#include <iostream>
#include <vector>
#include <cmath>


class foodMenu:public make_Up, public reusableFunctions{
public:
    void AssignCategory(){

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
            throw "Could not open the file\n";
        unsigned seed = time(0);
        srand(seed);
        for (int i = 0; i < countCast(); i++) {
                /// u need to assign the categories here
                std::fstream fout;
                fout.open("menuCategory.csv", std::ios::out | std::ios::app);
                std::string category = reusableFunctions::randomAssignment("general", "vegetarian", "flexitarian");
                fout << content[i][0] << "," << category << std::endl;
        }


    }

    static void menuGen(){

        unsigned seed = time(0);
        srand(seed);

        for (int i = 1; i<= 3; i++) {


            std::fstream fout;
            std::fstream fout1;
            fout.open("3dayMenu.csv", std::ios::out | std::ios::app);
            fout1.open("3dayMenuRomana.csv", std::ios::out | std::ios::app);
             fout << "-----------DAY " << i << "-----------" << std::endl;
             fout1 << "-----------ZIUA " << i << "-----------" << std::endl;

            fout << "-----------vegetarian-----------" << std::endl;
            fout1 << "-----------vegetarian-----------" << std::endl;

            std::string category = reusableFunctions::randomAssignment("tomato soup", "mushroom soup", "pumpkin soup",
                                                                       "vegetable soup", "noodle soup");
            if(category == "tomato soup"){
                fout1 << "primul fel: " << "supa de rosii"<< std::endl;
            }else if(category =="mushroom soup"){
                fout1 << "primul fel: " << "supa de ciuperci"<< std::endl;
            }else if(category == "pumpkin soup"){
                fout1 << "primul fel: " << "supa de dovleac"<< std::endl;
            }else if(category =="vegetable soup"){
                fout1 << "primul fel: " << "supa de legume"<< std::endl;
            }else if(category =="noodle soup"){
                fout1 << "primul fel: " << "supa de taitei"<< std::endl;
            }
            fout << "first course: " << category << std::endl;

            category = " ";
            category = reusableFunctions::randomAssignment("pomegranate salad", "caesar salad", "vegan curry",
                                                           "halloumi burger and fries", "vegetable noodles");
            if(category == "pomegranate salad"){
                fout1 << "fel principal: " << "salata cu rodie"<< std::endl;
            }else if(category =="caesar salad"){
                fout1 << "fel principal: " << "salata caesar"<< std::endl;
            }else if(category == "vegan curry"){
                fout1 << "fel principal: " << "curry vegan"<< std::endl;
            }else if(category =="halloumi burger and fries"){
                fout1 << "fel principal: " << "burger cu halloumi si cartofi prajti"<< std::endl;
            }else if(category =="vegetable noodles"){
                fout1 << "fel principal: " << "noodles cu legume"<< std::endl;
            }
            fout << "main course: " << category << std::endl;

            category = " ";
            category = reusableFunctions::randomAssignment("fresh watermelon", "cheesecake", "lava cake",
                                                           "fresh fruits", "tiramisu");
            if(category == "fresh watermelon"){
                fout1 << "desert: " << "pepene rosu proaspat"<< std::endl;
            }else if(category =="fresh fruits"){
                fout1 << "desert: " << "fructe proaspete"<< std::endl;
            }else
                fout1 << "desert: " << category << std::endl;

            fout << "desert: " << category << std::endl;


            category = " ";
            fout << "-----------general-----------" << std::endl;
            fout1 << "-----------general-----------" << std::endl;
            category = reusableFunctions::randomAssignment("chicken soup", "ramen", "vegetable soup", "miso soup",
                                                           "pork soup");
            if(category == "chicken soup"){
                fout1 << "primul fel: " << "supa de pui"<< std::endl;
            }else if(category =="vegetable soup"){
                fout1 << "primul fel: " << "supa de legume"<< std::endl;
            }else if(category == "miso soup"){
                fout1 << "primul fel: " << "supa miso"<< std::endl;
            }else if(category =="pork soup"){
                fout1 << "primul fel: " << "supa de porc"<< std::endl;
            }else{
                fout1 << "primul fel: " << category << std::endl;
            }
            fout << "first course: " << category << std::endl;

            category = " ";
            category = reusableFunctions::randomAssignment("curry", "burger and fries", "tacos", "bolognese pasta",
                                                           "chicken noodles");

            if(category == "burger and fries"){
                fout1 << "fel principal: " << "burger cu cartofi prajiti"<< std::endl;
            }else if(category =="bolognese pasta"){
                fout1 << "fel principal: " << "paste bolognese"<< std::endl;
            }else if(category == "chicken noodles"){
                fout1 << "fel principal: " << "noodles cu pui"<< std::endl;
            }else{
                fout1 << "fel principal: " << category << std::endl;
            }
            fout << "main course: " << category << std::endl;

            category = " ";
            category = reusableFunctions::randomAssignment("fresh watermelon", "cheesecake", "lava cake",
                                                           "fresh fruits", "tiramisu");
            if(category == "fresh watermelon"){
                fout1 << "desert: " << "pepene rosu proaspat"<< std::endl;
            }else if(category =="fresh fruits"){
                fout1 << "desert: " << "fructe proaspete"<< std::endl;
            }else
                fout1 << "desert: " << category << std::endl;

            fout << "desert: " << category << std::endl;

            category = " ";
            fout << "-----------flexitarian-----------" << std::endl;
            fout1 << "-----------flexitarian-----------" << std::endl;
            category = reusableFunctions::randomAssignment("tomato soup", "mushroom soup", "pumpkin soup",
                                                           "vegetable soup", "noodle soup");

            if(category == "tomato soup"){
                fout1 << "primul fel: " << "supa de rosii"<< std::endl;
            }else if(category =="mushroom soup"){
                fout1 << "primul fel: " << "supa de ciuperci"<< std::endl;
            }else if(category == "pumpkin soup"){
                fout1 << "primul fel: " << "supa de dovleac"<< std::endl;
            }else if(category =="vegetable soup"){
                fout1 << "primul fel: " << "supa de legume"<< std::endl;
            }else if(category =="noodle soup"){
                fout1 << "primul fel: " << "supa de taitei"<< std::endl;
            }

            fout << "first course: " << category << std::endl;

            category = " ";
            category = reusableFunctions::randomAssignment("sushi", "salmon and rice", "calamari salad","fresh tomato pasta", "tempura shrimps");

            if(category == "salmon and rice"){
                fout1 << "fel principal: " << "somon cu orez"<< std::endl;
            }else if(category =="calamari salad"){
                fout1 << "fel principal: " << "salata cu calamari"<< std::endl;
            }else if(category == "fresh tomato pasta"){
                fout1 << "fel principal: " << "paste cu rosii"<< std::endl;
            }else if(category == "tempura shrimps"){
                fout1 << "fel principal: " << "creveti tempura"<< std::endl;
            }else {
                fout1 << "fel principal: " << category << std::endl;
            }
            fout << "main course: " << category << std::endl;


            category = " ";
            category = reusableFunctions::randomAssignment("fresh watermelon", "cheesecake", "lava cake",
                                                           "fresh fruits", "tiramisu");

            if(category == "fresh watermelon"){
                fout1 << "desert: " << "pepene rosu proaspat"<< std::endl;
            }else if(category =="fresh fruits"){
                fout1 << "desert: " << "fructe proaspete"<< std::endl;
            }else
                fout1 << "desert: " << category << std::endl;

            fout << "desert: " << category << std::endl;

            fout1 << std::endl;
            fout1 << std::endl;

            fout << std::endl;
            fout << std::endl;




        }

    }



    static long long drinksCost(){
        int nrCast = countCast();
        long long oneDayCost = 0;
        float water = 0;
        float coffee = 0;
        float juice = 0;

        water = nrCast * 1;
        coffee = nrCast * 0.5;
        juice  = nrCast * 0.8;

        oneDayCost = ceil(water) * 3 + ceil(coffee) * 30 + ceil(juice) * 4;

        return oneDayCost;
    }


private:
    long long makeUpMenuCost(){

        long long menuCost = 0;

        std::vector<std::vector<std::string>> content;
        std::vector<std::string> row;
        std::string line, word;
        std::fstream file("menuCategory.csv", std::ios::in);

        if (file.is_open()) {

            while (getline(file, line)) {
                row.clear();
                std::stringstream str(line);
                while (getline(str, word, ','))
                    row.push_back(word);
                content.push_back(row);
            }
        } else
            throw "Could not open the file\n";
        unsigned seed = time(0);
        srand(seed);
        for (int i = 0; i < content.size(); i++) {
            if(content[i][1].find("general")){
                menuCost = menuCost + 40;
            }else if(content[i][1].find("vegetarian")){
                menuCost =  menuCost  + 33;
            }else if(content[i][1].find("flexitarian")){
                menuCost  =  menuCost  + 46;
            }

        }
        return menuCost;
    }




    friend class totalCost;
};



