#include <iostream>
#include <conio.h>

using namespace std;

struct Book {
	string Title;
	string Author;
	int yearPublished;
	int numPages;
};

int main()
{
	const int NUM_BOOKS = 4;
	Book libraryBooks[NUM_BOOKS] = {
		{"Lorem Ipsum the Novelization", "Lipsum", 1969, 404},
		{"Animal Farm", "George_Orwell", 1945, 92},
		{"Don Quixote", "Miguel_De_Cervantes", 1605, 940},
		{"Fahrenheit 451", "Ray_Bradbury", 1953, 156}
	};
	Book tempBook[1] = {
		{"string", "string", 1, 1},
	};

	for (int i = 0; i < NUM_BOOKS; i++)
	{
		cout << (i + 1) << ": " << libraryBooks[i].Title << "\n";
		cout << "Author: " << libraryBooks[i].Author << "\n";
		cout << "Published: " << libraryBooks[i].yearPublished << "\n";
		cout << "Page count: " << libraryBooks[i].numPages << "\n\n";
	}

	for (int i = 0; i < NUM_BOOKS; ) {
		cout << "Enter the ID of the book you would like to update";

		int input;
		string saveChanges;

		cin >> input;
		if (input < NUM_BOOKS) {
			i = input;

			cout << "Please update the title of the book. (" << libraryBooks[input].Title << ")";
			cin >> tempBook[0].Title;
			cout << "\nPlease update the author of the book. (" << libraryBooks[i].Author << ")";
			cin >> tempBook[0].Author;
			cout << "\nPlease update the year the book was published (in the form of an integer). (" << libraryBooks[i].yearPublished << ")";
			cin >> tempBook[0].yearPublished;
			cout << "\nPlease update the page count of the book. (" << libraryBooks[i].numPages << ")";
			cin >> tempBook[0].numPages;
			cout << "\nWould you like to save your changes? [Y/N]";
			cin >> saveChanges;

			
			if (saveChanges == "Y") {
				libraryBooks[input].Title = tempBook[0].Title;
				libraryBooks[input].Author = tempBook[0].Author;
				libraryBooks[input].yearPublished = tempBook[0].yearPublished;
				libraryBooks[input].numPages = tempBook[0].numPages;

				cout << "\n" << (i + 1) << ": " << libraryBooks[i].Title << "\n";
				cout << "Author: " << libraryBooks[i].Author << "\n";
				cout << "Published: " << libraryBooks[i].yearPublished << "\n";
				cout << "Page count: " << libraryBooks[i].numPages << "\n\n";
			}
			else if (saveChanges == "N"){
				cout << "Changes not saved.\n";
				cout << "\n" << (i + 1) << ": " << libraryBooks[i].Title << "\n";
				cout << "Author: " << libraryBooks[i].Author << "\n";
				cout << "Published: " << libraryBooks[i].yearPublished << "\n";
				cout << "Page count: " << libraryBooks[i].numPages << "\n\n";
				(void)_getch();
				return 0;
			}
		}

		else cout << "That book is not in our library. \n";
	}

	(void)_getch();
	return 0;

}