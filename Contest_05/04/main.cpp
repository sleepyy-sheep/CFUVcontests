#include <cmath>
using json = nlohmann::json;

class Point {
public:
    Point(double x, double y) : x(x), y(y) {
        update_polar();
    }
    
    double get_x() const { return x; }
    double get_y() const { return y; }
    double get_r() const { return r; }
    double get_a() const { return a; }
    
    void set_x(double new_x) {
        x = new_x;
        update_polar();
    }
    
    void set_y(double new_y) {
        y = new_y;
        update_polar();
    }
    
    void set_r(double new_r) {
        r = new_r;
        update_cartesian();
    }
    
    void set_a(double new_a) {
        a = new_a;
        update_cartesian();
    }

private:
    double x, y, r, a;
    
    void update_polar() {
        r = sqrt(x * x + y * y);
        a = atan2(y, x);
    }
    
    void update_cartesian() {
        x = r * cos(a);
        y = r * sin(a);
    }
};
