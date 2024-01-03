class Water {
public:
    Water(int initial_temperature) : temperature(initial_temperature) {}
    int get_temperature() const {
        return temperature;
    }
    void set_temperature(int new_temperature) {
        temperature = new_temperature;
    }
    
private:
    int temperature;
};

class Teapot {
public:
    Teapot(Water& water_ref) : water(water_ref) {}
    bool is_boiling() const {
        return water.get_temperature() >= 100;
    }
    void heat_up(int increase_temperature) {
        int new_temperature = water.get_temperature() + increase_temperature;
        water.set_temperature(new_temperature);
    }
    
private:
    Water& water;
};
