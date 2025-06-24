#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Room {
public:
    int room_number;
    string room_type;
    double price;
    bool room_is_booked;
    Room(int number, string type, double p) {
        room_number = number;
        room_type = type;
        price = p;
        room_is_booked = false;
    }
    void book() {
        if (!room_is_booked) {
            room_is_booked = true;
            cout << "Room is booked." << endl;
        } else {
            cout << "Room cannot be booked." << endl;
        }
    }
    void cancel_booking() {
        if (room_is_booked) {
            room_is_booked = false;
            cout << "Room booking has been canceled." << endl;
        } else {
            cout << "Cannot cancel booking." << endl;
        }
    }
    void display() const {
        string status = room_is_booked ? "Booked" : "Available";
        cout << room_number << " - " << room_type << " - " << price << " - " << status << endl;
    }
};
class Guest {
public:
    string name;
    string phone_number;
    Guest(string n, string p) {
        name = n;
        phone_number = p;
    }
    void display() const {
        cout << name << " - " << phone_number << endl;
    }
};
class Hotel {
private:
    string name;
    vector<Room> rooms;
    vector<Guest> guests;
public:
    Hotel(string hotel_name) {
        name = hotel_name;
    }
    void add_room(int room_number, string room_type, double price) {
        Room room(room_number, room_type, price);
        rooms.push_back(room);
        cout << "Room " << room_number << " added." << endl;
    }
    void add_guest(string guest_name, string phone_number) {
        Guest guest(guest_name, phone_number);
        guests.push_back(guest);
        cout << "Guest " << guest_name << " added." << endl;
    }
    void check_availability() const {
        bool found = false;
        for (const Room& room : rooms) {
            if (!room.room_is_booked) {
                if (!found) {
                    cout << "Available Rooms:\n";
                    found = true;
                }
                room.display();
            }
        }
        if (!found) {
            cout << "No rooms available." << endl;
        }
    }
    void book_room(int room_number) {
        for (Room& room : rooms) {
            if (room.room_number == room_number) {
                room.book();
                return;
            }
        }
        cout << "Room not found." << endl;
    }
    void cancel_booking(int room_number) {
        for (Room& room : rooms) {
            if (room.room_number == room_number) {
                room.cancel_booking();
                return;
            }
        }
        cout << "Room not found." << endl;
    }
    void show_guests() const {
        if (guests.empty()) {
            cout << "No guests found." << endl;
        } else {
            for (const Guest& guest : guests) {
                guest.display();
            }
        }
    }
};
int main() {
    Hotel hotel("Enigmatix");
    hotel.add_room(101, "Single", 10000);
    hotel.add_guest("Ali", "123-456-789-10");
    hotel.check_availability();
    return 0;
}