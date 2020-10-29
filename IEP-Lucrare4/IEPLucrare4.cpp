//Exemplu: copy assignment operator
//If you want to support copy assignment operator in a class containing a reference member, you must define the copy operator yourself.

#include <iostream>
using namespace std;

class elev {
	public:
		elev();
		~elev();
		elev& operator=(const elev& rhs);
		void SetElev(const string nume, const int id);
		void GetElev();
	private:
		//pentru item-ul 6 vom spune compilatorului sa nu genereze copy constructor pentru clasa asta deoarece nu avem nevoie de el, astfel:
		elev(const elev&);
		string* nume;
		int* id;
};

//default constructor
elev::elev() {

	this->nume = new string;
	*(this->nume) = "Null";

	this-> id = new int;
	*(this->id) = 0;

	return;
}

//destructor
elev::~elev() {

	if(this->nume != NULL) {
		delete this->nume;
	}

	if(this->id != 0) {
		delete this->id;
	}

	return;
}

//definim operatorul copy assignment pentru a-i "pasa" atributele in mod corespunzator
elev& elev::operator=(const elev& rhs) {
	
	cout << "Operatorul = a fost apelat" << endl << endl;
	
	(*this->nume) = (*rhs.nume);
	(*this->id) = (*rhs.id);

	return *this;
}

void elev::SetElev(const string nume, const int id) {
	
	*(this->nume) = nume;
	
	*(this->id) = id;

	return;
}

void elev::GetElev() {
	
	cout << *(this->nume) << ", id: " << *(this->id) << endl;

	return;
}

int main() {

	//Programul defineste doua obiecte, initializeaza doar pe unul, iar celalalt ii copiaza atributele prin operatorul definit de noi

	elev e1, e2;	//Item 5: Obiectele sunt initializate de constructorul default definit de noi (nume: NULL, id: 0)

	e1.SetElev("Marian", 62);

	e2 = e1;	//Am definit operatorul copy assignment deci nu mai avem eroare de compilare aici.

	//ambele rezultate vor afisa acelasi lucru dar refera spre obiecte diferite.
	e1.GetElev();
	e2.GetElev();

	return 0;
}
