// Подключаем нужные библиотеки
#include <iostream>
#include <fstream>
// Подключаем нашу локальную билиотеку
//#include "mylab.h"
#include <cstring>
#define u_int unsigned int
// Подключаем пространство имен
using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::ofstream;
// Наводим красоту
void logo(){
	cout << "\033[37;1m\033[44m"<< "\n **********************************************************";
	cout << "\033[37;1m\033[47m"<< "\n * Nizhniy Novgorod Technical University                  *";
	cout << "\033[37;1m\033[47m"<< "\n * Study work number 3. Task number 12.                   *";
	cout << "\033[37;1m\033[47m"<< "\n * Performed student 18-IVT-2 Kremlev Anton               *";
	cout << "\033[37;1m\033[44m"<< "\n **********************************************************";
	cout << "\x1b[39;49m" << endl << endl;;
}
class Aircraft{
protected:
	 type_of_aircraft;
	bool manual_contlor;
};
class Piloted_aircraft : public Aircraft {
protected:
	Piloted_aircraft(){
		manual_contlor = true;
	}
};
class Not_piloted_aircraft : public Aircraft{
protected:
	Not_piloted_aircraft(){
		manual_contlor = false;
	}
};
class Plane : public Piloted_aircraft{
public:
	Plane(){
		type_of_aircraft = "Plane";
	}
	void getP(){
		cout<< type_of_aircraft;
		cout<< manual_contlor;
	}

};
class Helicopter : public Piloted_aircraft{
	Helicopter(){
		type_of_aircraft = "Helicopter";
	}
};
class Meteozond : public Not_piloted_aircraft{
	Meteozond(){
		type_of_aircraft = "Meteozond";
	}
};
class Flying_robot : public Not_piloted_aircraft{
	Flying_robot(){
		type_of_aircraft = "Flying_robot";
	}
};

int main(int argc, char* argv[]){
	//Выводим лого
	logo();
//Прверяем нужна ли пользователю помощь
 	if ((!strcmp(argv[1],"--help")) || (!strcmp(argv[1],"--h"))){
	help();
		return 0;
 	}
//Проверка на верное количество аргументов
	if (argc != 4){
        cout << "Please get support by use --help" << endl;
        return 0;
	}
	Plane tu;
	tu.getP();
	return 0;
	
}
