// 3 types of classes are needed
// 1 Abstract Class which would be derived by the concrete classes
// 2 Concrete Class which will implement the Abstract class
// 3 AbstractFactoryClass which will create onstance of concrete class based on input type

class Vehicle
{
    virtual void createVehicle()=0;
    virtual ~Vehicle() {}
};

class Car: public Vehicle
{
    void createVehicle()
    {
        std::cout << "Car cerated" << std::endl;
    }
}

class Bike: public Vehicle
{
    void createVehicle()
    {
        std::cout << "Bike cerated" << std::endl;
    }
}

class Truck: public Vehicle
{
    void createVehicle()
    {
        std::cout << "Truck cerated" << std::endl;
    }
}

class VehicleFactory
{
    std::unique_ptr<Vehicle> createVehicle(const std::string& type) {
        if (type == "Car") {
            return std::make_unique<Car>();
        } else if (type == "Truck") {
            return std::make_unique<Truck>();
        } else if (type == "Bike") {
            return std::make_unique<Bike>();
        } else {
            return nullptr;  // If the type is not recognized
        }
    }
}

