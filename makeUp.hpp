#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>



class make_Up{
public:
     virtual void AssignCategory()  {

        ///find the actors and extras

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
        for (int i = 0; i < content.size(); i++) {
            if (content[i][1].find("extra") != std::string::npos ||
                content[i][1].find("actor/actress") != std::string::npos) {
                /// u need to assign the categories here and count the cost
                std::fstream fout;
                fout.open("makeUpCategory.csv", std::ios::out | std::ios::app);
                std::string category = reusableFunctions::randomAssignment("vampire", "werewolf", "siren", "clairvoyant", "human");
                std::fstream fout1;
                fout1.open("makeUpCategoryRomana.csv", std::ios::out | std::ios::app);
                if(category == "vampire"){
                    fout1 << content[i][0] << "," << "vampir" << std::endl;
                }else if(category == "werewolf"){
                    fout1 << content[i][0] << "," << "varcolac" << std::endl;
                }else if(category == "siren"){
                    fout1 << content[i][0] << "," << "sirena" << std::endl;
                }else if(category == "clairvoyant"){
                    fout1 << content[i][0] << "," << "clarvazator" << std::endl;
                }else {
                    fout1 << content[i][0] << "," << "om" << std::endl;
                }
                fout << content[i][0] << "," << category << std::endl;
            }
        }


    }


private:
     virtual long long makeUpMenuCost(){

        long long makeUpCost = 0;

        std::vector<std::vector<std::string>> content;
        std::vector<std::string> row;
        std::string line, word;
        std::fstream file("makeUpCategory.csv", std::ios::in);
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
                 if(content[i][1].find("vampire")){
                    makeUpCost = makeUpCost + 230;
                }else if(content[i][1].find("werewolf")){
                    makeUpCost =  makeUpCost  + 555;
                }else if(content[i][1].find("siren")){
                    makeUpCost  =  makeUpCost  + 345;
                }else if(content[i][1].find("clairvoyant")){
                    makeUpCost  =  makeUpCost  + 157;
                }else if(content[i][1].find("human")){
                    makeUpCost  =  makeUpCost  + 55;
                }

            }
        return makeUpCost;
        }

        friend class totalCost;
};

