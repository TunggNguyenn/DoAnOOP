#include "MyString.h"

#include <string>

int main()
{
	MyString name;

	std::cout << "Please, enter your name: ";
	std::cin >> name;
	std::cout << "Hello, " << name << "!\n";
	cin >> name;
	cout << name << endl;
	cin >> name;
	cout << name << endl;




	//MyString foo = "alpha";
	//MyString bar = "beta";



	//if (foo == bar) std::cout << "foo and bar are equal\n";
	//if (foo != bar) std::cout << "foo and bar are not equal\n";
	//if (foo < bar) std::cout << "foo is less than bar\n";
	//if (foo > bar) std::cout << "foo is greater than bar\n";
	//if (foo <= bar) std::cout << "foo is less than or equal to bar\n";
	//if (foo >= bar) std::cout << "foo is greater than or equal to bar\n";


	//const MyString& str0("nguyen");
	//MyString&& str1("thanh");
	//

	//MyString str3("hihi");
	//char c = 'c';


	//str3 = c + str1;
	//cout << str3 << endl;
	//cout << str0 << endl;
	//cout << str1 << endl;








	//MyString str = "Hello world!";
	//std::cout << str << '\n';




	//MyString buyer("moneyaaaaaaaaaaaaaa");
	//cout << buyer.size() << endl;
	//cout << buyer.capacity() << endl;
	//MyString seller("goods");
	//cout << seller.size() << endl;
	//cout << seller.capacity() << endl;

	//std::cout << "Before the swap, buyer has " << buyer;
	//std::cout << " and seller has " << seller << '\n';

	//swap(buyer, seller);

	//std::cout << " After the swap, buyer has " << buyer;
	//std::cout << " and seller has " << seller << '\n';
	//cout << buyer.size() << endl;
	//cout << buyer.capacity() << endl;

	//cout << seller.size() << endl;
	//cout << seller.capacity() << endl;



	//MyString str1("green apple");
	//MyString str2("red apple");

	//cout << str1.compare(str2) << endl;

	//if (str1.compare(str2) != 0)
	//	std::cout << str1 << " is not " << str2 << '\n';

	//if (str1.compare(6, 5, "apple") == 0)
	//	std::cout << "still, " << str1 << " is an apple\n";

	//if (str2.compare(str2.size() - 5, 5, "apple") == 0)
	//	std::cout << "and " << str2 << " is also an apple\n";

	//if (str1.compare(6, 5, str2, 4, 5) == 0)
	//	std::cout << "therefore, both are apples\n";




	//MyString str = "We think in generalities, but we live in details.";
	//// (quoting Alfred N. Whitehead)

	//MyString str2 = str.substr(48, 1000);     // "think"
	//cout << str2;
	//cout << str2.size() << endl;
	//cout << str2.capacity();

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