#include<iostream>
#include<string>
using namespace std;
char arr[3][3] = { '1', '2', '3', '4', '5', '6' , '7', '8', '9' };
char aanduiding = 'X';
string spelerKruisje, spelerRondje, speler;
void spelersNamen() {
  cout << "Naam speler 1 (kruisje): ";
  cin >> spelerKruisje;
  cout << "Naam speler 2 (rondje): ";
  cin >> spelerRondje;
  speler = spelerKruisje;

  if (spelerKruisje == spelerRondje) {
	  cout << "Je mag niet dezelfde naam gebruiken!" <<endl;
	  cout<<"*************************************"<<endl;
	  spelersNamen();
  }
}
void printSpel() { system("cls");
	for (int i = 0; i<3; i++) {
		for (int j = 0; j<3; j++) {
			cout<< arr[i][j] <<"    ";
		}
	cout << endl;
}
}

void speelSpel() {
	char positie;
	cout<< "Kies jou positie -( " << speler << " ) : ";
	cin >>positie;
	for (int i = 0; i<3; i++) {
		for (int j = 0; j<3; j++) {
			if (arr[i][j] == positie) {
				arr[i][j] = aanduiding;
			}
		}
	}
	if (aanduiding == 'X'){
		aanduiding = 'O';
		speler = spelerRondje;
		}
	else {
	aanduiding = 'X';
	speler = spelerKruisje;
	}
}
	char wieGewonnen(){
	int Xteller = 0, Oteller = 0;
	int teller = 0;
	for (int i = 0; i<3; i++) {
		for (int j = 0; j<3; j++) {
		   if (arr[i][j] != 'X' && arr[i][j] != 'O') teller++;
		   if (arr[i][j] != 'X' || arr[i][j] != 'O'){

		   }

		   if (arr[i][j] == 'X') Xteller++;
		   else if (arr[i][j] == 'O') Oteller++;

		   if (Xteller == 3 || Oteller == 3) {
			   return Xteller > Oteller ? 'X' : 'O';
		   }
		}
		Xteller = 0;
		Oteller = 0;
	}

		for (int i = 0; i<3; i++) {
			for (int j = 0; j<3; j++) {
			   if (arr[j][i] == 'X') Xteller++;
			   else if (arr[j][i] == '0') Oteller++;
			   if (Xteller == 3 || Oteller == 3) {
				   return Xteller > Oteller ? 'X' : 'O';
			   }
		}
		Xteller = 0;
		Oteller = 0;
	}
	if (arr[0][0] == 'X' && arr[1][1] == 'X' && arr[2][2] =='X') return 'X';
	else if (arr[0][0] == 'O' && arr[1][1] == 'O' && arr[2][2] =='O') return 'O';
	else if (arr[0][2] == 'X' && arr[1][1] == 'X' && arr[2][0] == 'X') return 'X';
	else if (arr[0][2] == 'O' && arr[1][1] == 'O' && arr[2][0] == 'O') return 'O';

	if (teller == 0) return 'Z';


	return '.';
}


int main(){

	cout<<"WELCOME DAT JE ONZE TIC TAC TOE GAME SPEELT!"<<endl;
	cout<<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;

   spelersNamen();
	while (wieGewonnen() == '.') {
		printSpel();
		speelSpel();
	}
	printSpel();
	if (wieGewonnen() == 'Z')
	cout<<"\nniemand heeft gewonnen"<<endl;
	else
		if (wieGewonnen() == 'X'){
		cout << "\nDe winnaar is (" << spelerKruisje << ")" << endl;
		}
	else {
	cout<<"\n De winnaar is speler (" << spelerRondje << ")";
	}

	string antwoord;
	cout <<"\nWillen jullie nog een keer spelen?" << endl;
	cout << "Ja of Nee: ";
	cin >> antwoord;

	if (antwoord == "ja" || antwoord == "Ja") {
		system("cls");
		main();

	}
	system("pause >> null");
	return 0;
}









