#include <string>
#include <array>
#include <cstdio>
#include <bitset>
#include <cstddef>
#include <iostream>
#include <utility>
#include <iterator>
#include <algorithm>
#include <limits>
#include <cstdint>


template<typename Container>
void print(const Container& c, const char* name)
{
	std::cout << name << ' ';
	for (auto i = c.begin(); i != c.end(); ++i) {
		std::cout << *i << ' ';
	}
	std::cout << '\n';
}
class Test
{
private:
	int age;
public:
	explicit Test(int age_) : age(age_)
	{
		printf("Test(%d)-----%p\n", age_, this);
	}
	Test(const Test& t) : age(t.age)
	{
		printf("Test(const Test& t)(%d)\n", t.age);
	}
	Test(Test&& t) : age(std::move(t.age))
	{
		printf("Test(Test&& t)(%d)\n", age);
	}	
	Test& operator=(const Test& t)
	{
		printf("Test& operator=(const Test& t)(%d)---%p\n", t.age, &t);
		age = t.age;
		return *this;
	}
	Test& operator=(Test&& t)
	{
		printf("Test& operator=(Test&& t)(%d)\n", t.age);
		age = std::move(t.age);
		return *this;
	}
	Test() { printf("Test()\n");};
	~Test()
	{
		printf("~Test(%d)\n", age);
	}
};

int main()
{
	std::array<Test, 10> t; // call default contructor for all 10 objects.
	t.fill(Test{4});
	// create a new Test object with age is 4
	// and then call copy assignment for all 10 created objects before

	std::array s = {"Quan", "Trang"}; // auto deduction C++17
	// std::array<const char*, 2> s = {"Quan", "Trang"};

	s.at(0); // "Quan"
	// s.at(2); // throw an exception (at() use bound checking)

	s[1]; // "Trang"
	s[4]; // not error, dont throw an exception, but undefined behavior


	s.front(); // "Quan";
	s.back(); // "Trang";
	// if s is empty std::array, the calling to front() and back() is undefined


	std::array<int, 0> emptyArray;
	emptyArray.front(); // undefined behavior
	emptyArray.back(); // undefined behavior


	s.data(); // underlying array (pointer)
	// if std::array is empty, the return value may (or may not) be nullptr
	emptyArray.data(); // may or may not be nullptr



	std::array s2 = {"Soc", "Kien"};

	s.swap(s2);
	//s = {"Soc", "Kien"}
	// s2 = {"Quan", "Trang"}
	// keep the old address, only change contents

	return 0;
}