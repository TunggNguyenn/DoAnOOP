#include "MyString.h"

#include <string>

int main()
{
	MyString str = "We think in generalities, but we live in details.";
	// (quoting Alfred N. Whitehead)

	MyString str2 = str.substr(48, 1000);     // "think"
	cout << str2;
	cout << str2.size() << endl;
	cout << str2.capacity();

	//std::size_t pos = str.find("live");      // position of "live" in str

	//MyString str3 = str.substr(pos);     // get from "live" to the end

	//std::cout << str2 << ' ' << str3 << '\n';




	//std::string str("Please, erase trailing white-spaces   \n");
	//std::string whitespaces(" \t\f\v\n\r");

	//std::size_t found = str.find_last_not_of(whitespaces);
	////cout << found << endl;
	//if (found != std::string::npos)
	//	str.erase(found + 1);
	//else
	//	str.clear();            // str is all whitespace

	//std::cout << '[' << str << "]\n";



	//std::string str("look for non-alphabetic characters...");

	//std::size_t found = str.find_first_not_of("abcdefghijklmnopqrstuvwxyz ");
	//std::cout << " at position " << found << '\n';

	//if (found != std::string::npos)
	//{
	//	std::cout << "The first non-alphabetic character is " << str[found];
	//	std::cout << " at position " << found << '\n';
	//}





	//MyString str("Please, replace the vowels in this senten.ce by asterisks.");
	//std::size_t found = str.find_first_of("aeiou");
	////while (found != std::string::npos)
	////{
	////	str[found] = '*';
	////	found = str.find_first_of("aeiou", found + 1);
	////}

	//std::cout << found << '\n';

	//found = str.find_first_of('.', 0);
	//std::cout << found << '\n';






	system("pause");
	return 0;
}