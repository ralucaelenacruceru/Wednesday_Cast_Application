#include <iostream>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <fstream>


class randomNameGen{
public:


	static std::string SensibleNamegen(int length) {
		const char* names[] = {"Sophia","Sanjay","Jacob","Jon","Isabella","Guido","Emma","William","Jayden","Mehmet","Emily","Mia","Noah","Michael", "Ethan",
		"Chloe","Aiden","Daniel","Elizabeth","Ava","Avery","Benjamin","Gennady","David","Sofia","Grace","Andrew","Bjarne","Logan","Zoey","Alexis","Lucas","Gabriel",
		"Kaylee","Isaac","Taylor","Evan","Landon","Jack","Alexa","Fabrice","Aaron","Brandon","Linus","Steve","Dough","Connor","Arianna","Scarlett","Eva", "bourne",
		"Dennis","James","Adam","John","Anders","Stephen","Jeff","Ian","Tim","Brian","Ken","Ferhat","Richard","Petr","Donald"};
		
		const char* surnames[] = {"Smith","Johnson","Williams","Brown","Jones","Rossum","Watson","Stone","Miller","Davis","Torvalds","Garcia","Rodrigez","Wilson", "Ethan",
		"Anderson","Clarke","Thomas","Lee","Ava","White","Moore","Hernandez","Harris","Sofia","Grace","Lewis","Stroustrup","Hall","Zoey",
		"Walker","Perez","Gabriel", "Lopez","Newton","Edison","Evan","Robinson","Dorsey","Alexa","Fabrice","Eder","Fischer","Clark","Jobs",
		"Doug","Connor","Arianna","Scarlett","Eva","Again","Schwarz", "Maier","Mayr","Egger","Claes","Nielsen","Petersen","Madsen","Ilves",
		"Robert","Leroy","Lion","Martin","Hawking","Meyer","Weber","Schulz","Becker","Hoffmann","Samaras","koufos","Kritikos","Papp","Jensen",
		"Waage","Kvaran","Rossi","Russo","Ferrari","Esposito", "Bianchi","Romano","Emine","Egzon","Arben","Yilmaz","Demir","Sahin","Celik","Kaya",
		"Aydin","Ozdemir","Arslan","Dogan","Kilic","Yildiz","Ozturk","Yildirim","Melnyk","Kovalenko","Boyko","Koval","Moroz","Petrenko","Robinson","Wood",
		"Ritchie","Gosling","Gontier","John","Anders","Bezos","Ian","Cook","Brian","Gecdogan","Richard","Petr","Donald"}; 	

  		std::string name = "";

  		int random = rand() % 2;
  		int count = 0;

  		for(int i = 0; i < length; i++) {
			if(length - 1 == i) {
      				name = name + surnames[rand() % 104];
      				count = 0;
    			} else if(random < 120 && count < 120) {
      				name = name + names[rand() % 66];
      				count++;
    			}
            if(i != length - 1)
                name.append(" ");



			random = rand() % 2;
  		}

 	 	return name;
	}




	static void GenerateAndSaveToFile(){

        std::fstream fout;
        fout.open("cast.csv", std::ios::out | std::ios::app);
        std::string name;
        name = randomNameGen::SensibleNamegen(2);
        fout << name << ",extra"<< "\n" ;


    }
};




