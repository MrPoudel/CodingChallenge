//============================================================================
// Name        : template-demo.cpp
// Author      : Tanken from https://www.youtube.com/watch?v=IdwJdJw65tU&list=PLGLfVvz_LVvQ9S8YSV0iDsuEU8v11yP9M&index=19
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iterator>
#include <vector>
#include <memory>
// Polymorphic template

class Pizza{
public:
	virtual void MakePizza() = 0;
};

class NYStyleCrust{
public:
	std::string AddIngredient(){
		return "Crust so thin you can see through it \n\n";
	}
};

class DeepDishCrust{
public:
	std::string AddIngredient(){
		return "Super Awesome Chicago Deep Dish \n\n";
	}
};

template<typename T>
class LotsOfMeat: public T{
public:
	std::string AddIngredient(){
		return "Lots of random Meat, " + T::AddIngredient();
	}
};

template<typename T>
class Vegan: public T{
public:
	std::string AddIngredient(){
		return "Vegan Cheese, Veggies, " + T::AddIngredient();
	}
};

template<typename T>
class MeatNYStyle: public T, public Pizza{
public:
	void MakePizza(){
		std::cout << "Meat NY style Pizza:" <<
				T::AddIngredient();
	}
};

template<typename T>
class VeganDeepDish: public T, public Pizza{
public:
	void MakePizza(){
		std::cout << "Vegan Deep Dish:" <<
				T::AddIngredient();
	}
};



int main()
{
    std::vector<std::unique_ptr <Pizza>> pizzaOrders;
    pizzaOrders.emplace_back(new MeatNYStyle<LotsOfMeat<NYStyleCrust>>());
    pizzaOrders.emplace_back(new VeganDeepDish<Vegan<DeepDishCrust>>());

    for(auto &pizza: pizzaOrders)
    	pizza ->MakePizza();

    //delete pNums;
    return 0 ;
}
