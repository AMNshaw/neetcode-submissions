class Person {
private:
    string lastName;
    int age;
    bool married;

public:
    Person(string lastName, int age, bool married) 
        : lastName(lastName), age(age), married(married) {}

    string getLastName() {
        return lastName;
    }

    int getAge() {
        return age;
    }

    bool isMarried() {
        return married;
    }
};

class PersonFilter {
public:
    virtual ~PersonFilter() {}
    virtual bool apply(Person& person) = 0;
};

class AdultFilter : public PersonFilter {
    public:
    AdultFilter(){};
    bool apply(Person& person) override{
        return person.getAge() >= 18;
    }
};

class SeniorFilter : public PersonFilter {
    public:
    SeniorFilter(){};
    bool apply(Person& person) override{
        return person.getAge() >= 65;
    }
};

class MarriedFilter : public PersonFilter {
    public:
    MarriedFilter(){}
    bool apply(Person& person) override{
        return person.isMarried();
    }
};

class PeopleCounter {
private:
    PersonFilter* filter;

public:
    void setFilter(PersonFilter& filter) {
        this->filter = &filter;
    }

    int count(vector<Person>& people) {
        int num = 0;
        for(auto& p : people){
            if(filter->apply(p)){
                num++;
            }
        }   
        return num;
    }
};
