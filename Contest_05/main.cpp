class Cat {
public:
    bool is_alive() {
        return alive;
    }

    void set_alive(bool alive) {
        this->alive = alive;
    }

private:
    bool alive;
};

class Box {
public:
    Cat open() {
        Cat cat;
        cat.set_alive(rand() % 2 == 0); // 50% chance of being alive
        return cat;
    }
};
