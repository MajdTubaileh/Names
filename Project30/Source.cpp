#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;


class setOfStrings
{
private:
	char **x;
	int NumOfNames;
	int sizeOfArray;

public:

	setOfStrings()
	{
		x = 0;
		NumOfNames = 0;
		sizeOfArray = 0;
	}
	setOfStrings(char X[][20], int n)
	{
		NumOfNames = n;
		sizeOfArray = n;
		x = new char *[n];

		for (int i = 0; i < n; i++)
		{
			x[i] = new char[20];
			strcpy(x[i], X[i]);
		}

	}
	setOfStrings(int n)
	{
		NumOfNames = n;
		sizeOfArray = n;
		x = new char *[n];

		for (int i = 0; i < n; i++)
		{
			x[i] = new char[20];

		}

	}
	//==========================================================================================================
	int belongs(char *e)
	{
		clear();
		for (int i = 0; i < sizeOfArray; i++)
		{

			if (strcmp(e, x[i]) == 0)
			{
				return 1;
			}
		}
		return 0;

	}
	//==========================================================================================================
	int isEmpty()
	{
		clear();
		if (NumOfNames == 0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	//==========================================================================================================
	void insertElement(char *e)
	{
		clear();
		if (NumOfNames == 0)
		{
			strcpy(x[0], e);
			NumOfNames++;
			sizeOfArray++;

		}
		/*else if (sizeOfArray != NumOfNames)
		{
			for (int i = 0; i < sizeOfArray; i++)
			{

				if (strcmp(x[i], "-") == 0)
				{
					strcpy(x[i], e);
					NumOfNames++;
				}

			}
		}*/
		else
		{
			char **M;
			M = new char*[sizeOfArray];

			/*cout << "Error : Array Is Full " << endl;*/
			for (int i = 0; i < sizeOfArray; i++)
			{
				M[i] = new char[20];
				strcpy(M[i], x[i]);

			}
			sizeOfArray++;
			x = new char*[sizeOfArray];

			for (int i = 0; i < sizeOfArray - 1; i++)
			{

				x[i] = new char[20];
				strcpy(x[i], M[i]);
			}
			x[sizeOfArray - 1] = new char[20];
			strcpy(x[sizeOfArray - 1], e);


			NumOfNames++;


		}

	}
	//==========================================================================================================
	void deleteElement(char *e)
	{
		clear();
		if (NumOfNames == 0)
		{
			cout << "Error : Array Is Empty" << endl;

		}
		else
		{
			for (int i = 0; i < sizeOfArray; i++)
			{
				if (strcmp(x[i], e) == 0)
				{
					strcpy(x[i], "-");
					//NumOfNames--;
					break;
				}
			}
		}
		clear();
	}
	//==========================================================================================================
	void deleteAllElements() {


		for (int i = 0; i < sizeOfArray; i++)
		{
			strcpy(x[i], "-");
		}
		NumOfNames = 0;
		sizeOfArray = 0;
	}
	//==========================================================================================================
	void print()
	{
		clear();
		if (NumOfNames == 0)
		{
			cout << "Error :No Elements To Show" << endl;
		}
		else {
			cout << "Set : " << endl;
			for (int i = 0; i < sizeOfArray; i++)
			{

				cout << x[i] << endl;
			}
		}

		cout << "--------------------------------------" << endl;
	}
	int size() {
		return NumOfNames;
	}
	//==========================================================================================================
	setOfStrings Union(setOfStrings A) {
		int sizeOfTemp = A.sizeOfArray + sizeOfArray;
		setOfStrings interSectElements = intersection(A);
		setOfStrings UnionSet(sizeOfTemp);

		int w = 0;

		for (int i = 0; i < sizeOfArray; i++)
		{

			strcpy(UnionSet.x[i], x[i]);
		}
		int counter;
		for (int i = sizeOfArray; i < sizeOfTemp; i++)
		{
			counter = 0;
			for (int j = 0; j < interSectElements.size(); j++)
			{
				if (strcmp(interSectElements.x[j], A.x[w]) == 0)
				{
					break;
				}
				else
				{
					counter++;
				}

			}
			if (counter == interSectElements.size())
			{
				strcpy(UnionSet.x[i], A.x[w]);

			}
			else { strcpy(UnionSet.x[i], "-"); }
			w++;
		}

		UnionSet.clear();

		return UnionSet;
	}
	//==========================================================================================================
	setOfStrings intersection(setOfStrings A)
	{
		clear();
		A.clear();
		int sizeOfTempArray = 0;
		for (int i = 0; i < sizeOfArray; i++)
		{
			for (int j = 0; j < A.sizeOfArray; j++)
			{
				if (strcmp(x[i], A.x[j]) == 0)
				{
					sizeOfTempArray++;
				}


			}

		}
		setOfStrings temp0(sizeOfTempArray);

		if (NumOfNames == 0)
		{
			cout << "Error : Array Is Empty" << endl;

		}
		if (A.NumOfNames == 0)
		{
			cout << "Error : Array of The second set Is Empty" << endl;

		}
		int k = 0;
		for (int i = 0; i < sizeOfArray; i++)
		{
			for (int j = 0; j < A.sizeOfArray; j++)
			{
				if (strcmp(x[i], A.x[j]) == 0)
				{
					strcpy(temp0.x[k], x[i]);
					k++;
				}


			}

		}
		return temp0;
	}
	void clear()
	{
		int countOfNames = 0;
		for (int i = 0; i < size(); i++)
		{
			if (strcmp(x[i], "-") != 0)
			{
				countOfNames++;
			}

		}
		setOfStrings newClearSet(countOfNames);
		int count = 0;
		for (int i = 0; i < size(); i++)
		{
			if (strcmp(x[i], "-") != 0)
			{
				strcpy(newClearSet.x[count], x[i]);
				count++;
			}

		}
		deleteAllElements();
		sizeOfArray = countOfNames;
		for (int i = 0; i < sizeOfArray; i++)
		{
			strcpy(x[i], newClearSet.x[i]);
			NumOfNames++;
		}
	}
	//==========================================================================================================
	setOfStrings Difference(setOfStrings A)
	{
		A.clear();
		clear();
		setOfStrings interSet = intersection(A);
		setOfStrings UniSet = Union(A);
		for (int i = 0; i < UniSet.sizeOfArray; i++)
		{
			for (int j = 0; j < interSet.sizeOfArray; j++)
			{
				if (strcmp(interSet.x[j], UniSet.x[i]) == 0)
				{
					strcpy(UniSet.x[i], "-");
				}
			}
		}
		UniSet.clear();
		return UniSet;



	}






};


int main()
{
	char K[4][20] = { "sami", "jamal", "ali", "ahmad" };
	char W[7][20] = { "jihad", "jamal", "imad", "ahmad" ,"sameer","isaa","ali" };
	setOfStrings S1(K, 4);
	setOfStrings S2(W, 7);

	S1.print();
	char newName[20] = "saeed";
	S1.insertElement(newName);
	S2.print();
	//S1.print();

	setOfStrings S3 = S1.Union(S2);
	S3.print();
	cout << S3.size() << endl;
	S3.deleteAllElements();
	cout << S3.size() << endl;
	S3.insertElement(newName);
	S3.print();
	cout << S3.size() << endl;
	S2.print();
	cout << S2.size() << endl;
	setOfStrings S4 = S1.Difference(S2);
	S4.print();
	cout << S4.size() << endl;
	cout << S1.belongs(newName) << endl;
	char newName2[20] = "sameeh";
	S1.insertElement(newName2);
	char newName3[20] = "ismaeel";
	S1.insertElement(newName3);
	setOfStrings S5 = S1.Difference(S2);
	S1.print();
	S2.print();
	S5.print();
	/*S3.deleteAllElements();

	S3.print();
	S3.insertElement(newName);
	S3.print();
	S3.deleteElement(newName);
	cout << S3.size() << endl;*/
	/*S2.print();

	cout << S1.size() << endl;
	cout << S2.size() << endl;
	char ali[20] = "ali";
	S1.deleteElement(ali);
	S1.print();

	char majd[20] = "majd";
	S1.insertElement(majd);

	S1.print();
	setOfStrings S3 = S1.intersection(S2);
	S3.print();

	setOfStrings S4 = S1.Difference(S2);
	S4.print();

	S4.deleteAllElements();

	S4.print();*/
	/*
	char kamal [20] = "kamal";
	char jamal[20] = "jamal";
	S1.insertElement(kamal);
	S2.deleteElement(jamal);
	setOfStrings S3 = S1.Union(S2);
	S3.print();
	setOfStrings S4 = S1.intersection(S2);
	S4.print();
	setOfStrings S5 = S1.Difference(S2);
	S5.print();
	S3.deleteAllElements();
	S3.print();
	cout << S3.size();
	*/
	system("pause");
	return 0;
}