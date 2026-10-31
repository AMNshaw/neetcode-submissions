class Meal {
private:
    double cost;
    bool takeOut;
    string main;
    string drink;

public:
    double getCost() {
        return cost;
    }

    bool getTakeOut() {
        return takeOut;
    }

    string getMain() {
        return main;
    }

    string getDrink() {
        return drink;
    }

    void setCost(double cost) {
        this->cost = cost;
    }

    void setTakeOut(bool takeOut) {
        this->takeOut = takeOut;
    }

    void setMain(string main) {
        this->main = main;
    }

    void setDrink(string drink) {
        this->drink = drink;
    }
};

class MealBuilder {
public:
    Meal meal_;

    MealBuilder() {

    }

    MealBuilder& addCost(double cost) {
        meal_.setCost(cost);
        return *this;
    }

    MealBuilder& addTakeOut(bool takeOut) {
        meal_.setTakeOut(takeOut);
        return *this;
    }

    MealBuilder& addMainCourse(string main) {
        meal_.setMain(main);
        return *this;
    }

    MealBuilder& addDrink(string drink) {
        meal_.setDrink(drink);
        return *this;
    }

    Meal build() {
        return meal_;
    }
};
