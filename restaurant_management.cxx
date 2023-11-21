#include<iostream>
using namespace std;
class A{
public:
	int o;
	int w;
	int nn;
	int price[16] = { 0, 200, 2300, 3000, 500, 500,400,300,150,400,1000 ,800,700,400,1500,900};
	int price_print[16];
	int num;
	int number_demand[1000];
	int x = 0;
	float total;
	float q;
	string food[16] = { "\t\t|  Number  |     The eater     |  Price  |", "    Boiled eggs    ","       pizza       ", "  grilled chicken  ", "     potatoes      ", "       cake        " ,"    orang juse     ","     milk tea      ","      red tea      ","    mango juice    ","     mix juice     ", "       rice        ","      milkshik     ", "       flafl       ","       prgar       ","      nodels       "};
	string food_print[16]={"| The number |  Name of the eat  |  Quantity  | Price |"};
	string username = "maram";
	string u;
	string password = "123456";
	string p;

	void foods();
	void output();
	void choose();
};
class B : public A{
public:
	B();
	void swap();
};
void A::foods(){
	int i = 0;
	cout << "\t\t __________________________________________" << endl;
	cout << food[0];
	cout << endl;
	for (int i = 1; i<16; i++){
		cout << "\t\t __________________________________________" << endl;
		cout << "\t\t|    " << i << "     |" << food[i] <<"|   " << price[i] <<"   |" << endl;
	}
	cout << "\t\t ------------------------------------------" << endl;
	cout << endl;
}
void A::choose(){
	cout << "Pleas select the number of foods you want to request : ";
	cin >> nn;
	for (int i = 1; i <=nn; i++){
		cout << "Choose the number of the food you want :";
		cin >> num;
		cout << "How many " << food[num] << " do you want :";
		cin >> number_demand[i];
		food_print[i] = food[num];
		price_print[i] = price[num];
	}
}
void A::output(){
	system("cls");
	int j=0;
	total=0;
	cout<<"\t\t_______________________________________________________"<<endl;
	cout <<"\t\t"<<food_print[j] <<endl;
	for (j = 1; j <= nn; j++){
		q = price_print[j] * number_demand[j];
		cout <<"\t\t|    "<< j <<"       |"<<food_print[j] << "|      " << number_demand[j] << "     |" << q <<"  |"<<endl;
		total += q;
	}
	cout<<"\t\t-------------------------------------------------------"<<endl;
	cout <<"\t\t| Number of oeders : " << j-1 << "\t Total price : " <<total<<" YER    |"<<endl;
	cout<<"\t\t-------------------------------------------------------"<<endl;
}
B::B(){
	int x = 0;
	Q:
	system("cls");
	cout << "\t \t   ...[welcome in my program]... \n \n \n";
	while (x < 5) {
	Y:
		cout << "     Enter username :";
		cin >> u;
		cout << "     Enter password:";
		cin >> p;
		if (username == u && password == p){
			P:
			system("cls");
			foods();
        	choose();
        	system("cls");
        	cout << "If you want to print the request, press the number : 1 \n"
	                "If you want to adjust the request, press the number : 2 "<<endl;
           	int l;
           	int z;
        	cin >> l;
        	switch (l){
        	case 1:output();
    		break;
        	case 2:swap();	
    		break;
	}
		cout<<"If you want to enter another request press number : 1"<<endl;
        cout<<"If you want to exit the program press number : 2"<<endl;
	 	M:
	    cin>>z;
	    if (z==1)
           goto P;
     	else if (z==2)
		   goto Q;
		else {	
		    cout<<"Wrong ! pleas press number 1 or 2"<<endl;
		    goto M;
}	
		}
		else{
			cout << endl;
			cout << "    wrong!\n " << endl;
			int m;
			cout << "If you want try again,press number 1\n";
			cout << "If you forget the password,press number 2\n";
			cin >> m;
			system("cls");
			switch (m){
			case 1: goto Y;
				break;
			case 2:{
				cout << "Eenter now username :";
				cin >> username;
				cout << "Eenter now password :";
				cin >> password;
				goto Y;
				break;
			}
			}
		}
		x++;
	}
}
void B::swap(){
		system("cls");
		cout<<"\t\t Food menu "<<endl;
		foods();
		cout<<"The food bill you want to adjust  "<<endl;
		output();
		cout << "Choose the order number you want to modify from the invoice" << endl;
		cin >> o;
		cout << "Choose the order number you want to add the invoice"<< endl;
		cin >> w;
		cout << "How many " << food[w] << " do you want :";
		cin >> number_demand[w];
		food_print[o] = food[w];
		price_print[o] = price[w];
		number_demand[o]=number_demand[w];
		system("cls");
		cout<<"\t\t The new bill"<<endl;
		output();
	
}
int main(){
	B w;
	return 0;
}