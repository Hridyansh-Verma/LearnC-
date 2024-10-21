// BDP is used to create complex object step by step
// Complex object :- attributes are more or/and complex

// Main classes
// 1 Final Concrete Class - Pizza
// 2 Builder Class : Have a layer of abstraction (abstract PizzaBuilder) and concrete implementation of
//                   the class (CustomPizzaBuilder)
// 3 Director Class: Its not necessary . You can build the concrete class object just through builder

class Pizza{
public:
    std::string size;
    std::string crust;
    std::vector<std::string> toppings;
    void showPizza()
    {
        std::cout << "Pizza size: " << size << std::endl;
        std::cout << "Pizza crust: " << crust << std::endl;
        std::cout << "Toppings: ";
        for (const auto& topping : toppings) {
            std::cout << topping << " ";
        }
        std::cout << std::endl;
    }
};

class PizzaBuilder
{
private:
    Pizza* pizza;

public:
    virtual ~PizzaBuilder() {}
    void setSize(cosnt std::string &size) = 0;
    void setCrust(cosnt std::string &crust) = 0;
    void setToppings(cosnt std::vector<std::string> &size) = 0;
    virtual Pizza* getPizza()=0;
};

// Concrete Builder class for building a custom pizza
class CustomPizzaBuilder : public PizzaBuilder 
{
public:
    CustomPizzaBuilder() {
        pizza = new Pizza();  // Create a new pizza object
    }

    ~CustomPizzaBuilder() {
        delete pizza;
    }

    void setSize(const std::string& size) override {
        pizza->size = size;
    }

    void setCrust(const std::string& crust) override {
        pizza->crust = crust;
    }

    void addTopping(const std::string& topping) override {
        pizza->toppings.push_back(topping);
    }

    Pizza* getPizza() override {
        return pizza;
    }
};


// Director class to construct pizza
class PizzaDirector {
public:
    // Construct a pizza by calling the appropriate builder methods
    void buildPizza(PizzaBuilder* builder) {
        builder->setSize("Large");
        builder->setCrust("Thin");
        builder->addTopping("Cheese");
        builder->addTopping("Pepperoni");
        builder->addTopping("Olives");
    }
};

int main() {
    // Create a director and a builder
    PizzaDirector director;
    CustomPizzaBuilder builder;

    // Construct the pizza
    director.buildPizza(&builder);

    // Get the constructed pizza
    Pizza* pizza = builder.getPizza();

    // Display the pizza details
    pizza->showPizza();

    // Clean up the pizza object
    delete pizza;

    return 0;
}

