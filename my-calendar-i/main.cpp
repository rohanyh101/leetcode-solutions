#include <iostream>
#include <vector>

class MyCalendar {
private:
    std::vector<std::pair<int, int>> bookings;
public:
    MyCalendar() {
    }
    
    bool book(int startTime, int endTime) {
        for (const auto& booking : bookings) {
            if (startTime < booking.second && endTime > booking.first) {
                return false;
            }
        }
        bookings.push_back({startTime, endTime});
        return true;
    }
};

int main() {
    MyCalendar* obj = new MyCalendar();
    std::cout << std::boolalpha << obj->book(10, 20) << std::endl; // returns true
    std::cout << std::boolalpha << obj->book(15, 25) << std::endl; // returns false
    std::cout << std::boolalpha << obj->book(20, 30) << std::endl; // returns true
    delete obj;
}