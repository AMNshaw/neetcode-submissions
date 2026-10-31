class Singleton {
private:
    string val_;

    Singleton() {}

public:
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    static Singleton *getInstance() {
        static Singleton instance;
        return &instance;
    }

    string getValue() {
        return val_;
    }

    void setValue(string &value) {
        val_ = value;
    }
};
