#include<iostream>
#include <vector>
#include<fstream>
#include<string>
#include <sstream>
using namespace std;

int totalElec = 0;

ifstream input("Office.txt");
ofstream output;

vector<char> offOrElec;
vector<int> quantity;
vector<string> name;
vector<char> price;
vector<double> numPrice;

vector<int> whichElec;
vector<int> whichOff;

void getingInfo()
{
	for (int i = 0; i < 8; i++)
	{
		char tempVar;
		input >> tempVar;
		offOrElec.push_back(tempVar);

		int tempQuan;
		input >> tempQuan;
		quantity.push_back(tempQuan);

		string holdingPlace;
		input >> holdingPlace;
		name.push_back(holdingPlace);

		char tempPrice;
		input >> tempPrice;
		price.push_back(tempPrice);

		double tempRealPrice;
		input >> tempRealPrice;
		numPrice.push_back(tempRealPrice);


	}
}

void determiningType()
{

	for (int i = 0; i < 8; i++)
	{
		if (offOrElec.at(i) == 'E')
		{
			whichElec.push_back(i);
		}
		else if (offOrElec.at(i) == 'O')
		{
			whichOff.push_back(i);
		}
	}

}

void printOut(int choice)
{
	double overallTotal = 0;
	if (choice == 1)
	{
		for (int i = 0; i < whichElec.size(); i++)
		{
			double itemsTotal = 0;
			cout << "E" << endl << "Quantity: " << quantity.at(whichElec.at(i)) << endl <<
				"Name: " << name.at(whichElec.at(i)) << endl << "Price: $" << numPrice.at(whichElec.at(i)) << endl << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;

			itemsTotal = quantity.at(whichElec.at(i)) * numPrice.at(whichElec.at(i));

			overallTotal += itemsTotal;
			cout << "Total: " << itemsTotal <<endl ;
			
		}
	
	}
	else if (choice == 2)
	{
		for (int i = 0; i < whichOff.size(); i++)
		{
			double itemsTotal2 = 0;
			

			cout << "O" << endl << "Quantity: " << quantity.at(whichOff.at(i)) << endl <<
				"Name: " << name.at(whichOff.at(i)) << endl << "Price: $" << numPrice.at(whichOff.at(i)) << endl << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;

			itemsTotal2 = quantity.at(whichOff.at(i)) * numPrice.at(whichOff.at(i));
			
			overallTotal += itemsTotal2;

			cout << "Total: " << itemsTotal2<< endl;


		
		}

	}

	cout << "=================================================" << endl << "The total for everything is: " << overallTotal << endl <<"================================================="<< endl;
	overallTotal = 0;
}


// JUST NEED TO GET THIS TO OUTPUT TO THE SUMMERY FILE
//DONE
void printToSumm()
{
	double fullItemTotal = 0;
	
	output.open("ThisSummery.txt");
		for (int i = 0; i < whichElec.size(); i++)
		{
			double itemsTotal = 0;
			
			output <<  "E" << endl << "Quantity: " << quantity.at(whichElec.at(i)) << endl <<
		"Name: " << name.at(whichElec.at(i)) << endl << "Price: $" << numPrice.at(whichElec.at(i)) << endl << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;

			itemsTotal = quantity.at(whichElec.at(i)) * numPrice.at(whichElec.at(i));

			fullItemTotal += itemsTotal;

		}

				output << "=================================================" << endl << "The total for everything is: " << fullItemTotal << endl << "=================================================" << endl;
	
		double fullItemTotal2 = 0;

	
		for (int i = 0; i < whichOff.size(); i++)
		{
			double itemsTotal2 = 0;

			output << "O" << endl << "Quantity: " << quantity.at(whichOff.at(i)) << endl <<
				"Name: " << name.at(whichOff.at(i)) << endl << "Price: $" << numPrice.at(whichOff.at(i)) << endl << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;

			itemsTotal2 = quantity.at(whichOff.at(i)) * numPrice.at(whichOff.at(i));

			fullItemTotal2 += itemsTotal2;



		}
			output << "=================================================" << endl << "The total for everything is: " << fullItemTotal2 << endl << "=================================================" << endl;


}




//this was ment to do some calculation for the amount total but just got that done in the printOut();
/*double returningTot(int choice)
{
	double thisTotal = 0;

	if (choice == 1)
	{
		for (int i = 0; i < whichElec.size(); i++)
		{
			thisTotal += numPrice.at(whichElec.at(i));
		
		}
	}
	else if(choice == 2)
	{
		for (int i = 0; i < whichOff.size(); i++)
		{
			thisTotal += numPrice.at(whichOff.at(i));
		}
	}

	return thisTotal;

}*/

int main()
{
	bool carryOn = true;
	getingInfo();
	int choice;
	
	while (carryOn)
	{
		cout << "Option 1: Output Electronics Supplies to the screen with the total cost of all electronic products. " << endl
			<< "Option 2: Output Office Supplies to the screen with the total cost of all office products. " << endl
			<< "Option 3: Output Electronics and Office Supplies to “Summary.txt” with total cost of all electronics supplies and total cost of all office supplies. " << endl
			<<"Option 4: Quit"<<endl;
		cout << "Please choose on of the following(1,2,3,4): ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			determiningType();
			printOut(choice);
			break;

		case 2:
			determiningType();
			printOut(choice);
			break;
		case 3:
			determiningType();
			printToSumm();
			cout << "The information has been printed out! " << endl;
			break;
		case 4:
			carryOn = false;
			break;

		default:

			break;
		}

	}
	return 0;
}