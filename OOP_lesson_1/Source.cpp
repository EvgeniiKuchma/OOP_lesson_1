#include <iostream>
//классы 
//ооп - полииморфизм, наследование, инкапсуляция

class Vehicle 
{
public:
	//конструктор (параметризованный)
		/*Vehicle(int newMaxSpeed, const std::string& newColor, const std::string& newType) //вариант присвоения значений
			: maxSpeed(newMaxSpeed), 
			color(newColor), 
			type(newType) {};*/
		Vehicle(int newMaxSpeed, const std::string& newColor, const std::string& newType)
		{
			maxSpeed = newMaxSpeed;
			color = newColor;
			type = newType;
			s = new char[50];
		}
		//дефолтный конструктор (констр. оп умолчанию) он обьявляет перменные
		//Vehicle() = default; 2й  вариант
		//Vehicle() {}; 1й вариант
		/*Vehicle(int newMaxSpeed) //вариант присвоения значений
			: maxSpeed(newMaxSpeed),
			color("yellow"),
			type("bus") {};*/
		Vehicle(int newMaxSpeed)
		{
			 maxSpeed = newMaxSpeed;
			 color = "yellow";
			 type = "bus";
		}
		Vehicle() = delete;//удаляет конструктор по умлчанию
		 //конструктор копирования 
		Vehicle (Vehicle& obj)
		{
			maxSpeed = obj.getMaxSpeed();
			color = obj.getColor();
			type = obj.getType();
		
		}
		//деструктор 
		~Vehicle() 
		{
			std::cout << "Destructor Vehicle()" << std::endl;
			delete[] s;
		}
		std::string getColor() 
		{
			return color;
		}
		void setColor( const std::string& newColor)
		{
			color = newColor;
		}
		const std::string& getType()
		{
			return type;
		}
		void setType(const std::string& newType)
		{
			type = newType;
		}
		//getter
		int getMaxSpeed()
		{
		return maxSpeed;
		}
		//setter
		void setMaxSpeed(int  newSpeed)
		{
			maxSpeed = newSpeed;
		}
		bool operator ==(Vehicle& other)
		{
			if (maxSpeed == other.maxSpeed && //упрощает иправление ошибок
				color == other.color && 
				type == other.type)
			{
				return true;
			}
			return false;
		};
private:
	int counter;
	int maxSpeed;
	std::string color;
	std::string type;
	char* s;
};

int main ()
{
	setlocale(LC_ALL, "Russian");

	//Vehicle car; - конструктор по умолчанию
	Vehicle car(20, "black", "van");
	//car.setMaxSpeed(50);
	//std::cout << "Max speed is " << car.getMaxSpeed() << std::endl;
	Vehicle originalCar(15, "wite", "bus");
	Vehicle newCar(originalCar);
	Vehicle foreignCar(20, "wite", "bus");
	
	std::cout << (originalCar == newCar) << std::endl;
	std::cout << "-------------------" << std::endl;
	std::cout << (originalCar == foreignCar) << std::endl << '\n';

	std::cout << originalCar.getMaxSpeed() << " " << originalCar.getColor() << "  " << originalCar.getType() << std::endl;
	std::cout << "------------------------------------" << std::endl;
	std::cout << newCar.getMaxSpeed() << " " << newCar.getColor() << "  " << newCar.getType() << std::endl << '\n';
	
	std::string  carColor = car.getColor();
	std::cout << "car color ; " << carColor << " car.getColor()" << car.getColor() << std::endl;
	carColor = "green";
	std::cout << "car color ; " << carColor << " car.getColor()" << car.getColor() << std::endl <<'\n';
	
	const std::string& carType = car.getType();
	//carType = "abc"; переопределение невозможно так как ссылка в классе константная
	std::cout << carType << " " << car.getType() << std::endl << '\n';

	std::cout << "End of main()" << std::endl;
	return 0;
}