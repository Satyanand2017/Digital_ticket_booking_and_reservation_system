#include <iostream>
#include <fstream>  // For file handling
#include <string>
#include <vector>
#include <map>
#include <cstdlib>  // For random Booking ID
#include <ctime>

using namespace std;

// Structure for Ticket
struct Ticket {
    string name;
    string ticketType;
    string event;
    string seatType;
    int numTickets;
    int bookingID;
    string seatLocation;
};

// Function to generate a random booking ID
int generateBookingID() {
    return rand() % 90000 + 10000;  // Generates a 5-digit random number
}

// Function to save ticket details to a file
void saveTicketToFile(const Ticket &ticket) {
    ofstream file("ticket_booking.txt", ios::app);  // Open file in append mode
    if (file.is_open()) {
        file << "Booking ID   : " << ticket.bookingID << endl;
        file << "Name         : " << ticket.name << endl;
        file << "Ticket Type  : " << ticket.ticketType << endl;
        file << "Event        : " << ticket.event << endl;
        file << "Seat Type    : " << ticket.seatType << endl;
        file << "Seat Location: " << ticket.seatLocation << endl;
        file << "Tickets      : " << ticket.numTickets << endl;
        file << "===================================\n";
        file.close();
        cout << "\nTicket details saved to 'ticket_booking.txt'\n";
    } else {
        cout << "Error: Unable to open file for saving.\n";
    }
}

// Function to display available ticket options
void showTicketOptions() {
    cout << "\nTicket Booking System\n";
    cout << "1. Movie Ticket\n";
    cout << "2. Train Ticket\n";
    cout << "3. Bus Ticket\n";
    cout << "4. Concert Ticket\n";
    cout << "Enter your choice (1-4): ";
}

// Function to display seating options
void showSeatOptions() {
    cout << "\nSelect Seat Type:\n";
    cout << "1. General\n";
    cout << "2. VIP\n";
    cout << "3. First-Class\n";
    cout << "4. Economy\n";
    cout << "Enter your choice (1-4): ";
}

// Function to handle user registration
void registerUser(map<string, string> &users) {
    string username, password;
    cout << "Enter a new username: ";
    cin >> username;

    if (users.find(username) != users.end()) {
        cout << "Username already exists! Try again.\n";
        return;
    }

    cout << "Enter a password: ";
    cin >> password;

    users[username] = password;
    cout << "Registration successful! You can now log in.\n";
}

// Function to handle user login
bool loginUser(map<string, string> &users) {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    if (users.find(username) != users.end() && users[username] == password) {
        cout << "Login successful! Welcome, " << username << ".\n";
        return true;
    } else {
        cout << "Invalid username or password. Try again.\n";
        return false;
    }
}

int main() {
    srand(time(0));  // Seed for random number generation
    map<string, string> users;  // Store username-password pairs
    users["admin"] = "password123";  // Predefined users
    users["user1"] = "pass123";
    users["guest"] = "guest123";

    int choice;
    bool loggedIn = false;

    // Login or Register
    while (!loggedIn) {
        cout << "\n1. Register\n2. Login\n3. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: registerUser(users); break;
            case 2: loggedIn = loginUser(users); break;
            case 3: return 0;
            default: cout << "Invalid choice. Try again.\n";
        }
    }

    Ticket myTicket;
    int ticketChoice, seatChoice;

    // Get user details
    cout << "Enter your name: ";
    cin.ignore();
    getline(cin, myTicket.name);

    // Choose ticket type
    showTicketOptions();
    cin >> ticketChoice;

    // Assign ticket type
    switch (ticketChoice) {
        case 1: myTicket.ticketType = "Movie"; break;
        case 2: myTicket.ticketType = "Train"; break;
        case 3: myTicket.ticketType = "Bus"; break;
        case 4: myTicket.ticketType = "Concert"; break;
        default: cout << "Invalid choice! Exiting...\n"; return 1;
    }

    // Get event name
    cout << "Enter the name of " << myTicket.ticketType << ": ";
    cin.ignore();
    getline(cin, myTicket.event);

    // Choose seat type
    showSeatOptions();
    cin >> seatChoice;

    // Assign seat type
    switch (seatChoice) {
        case 1: myTicket.seatType = "General"; break;
        case 2: myTicket.seatType = "VIP"; break;
        case 3: myTicket.seatType = "First-Class"; break;
        case 4: myTicket.seatType = "Economy"; break;
        default: cout << "Invalid choice! Exiting...\n"; return 1;
    }

    // Get number of tickets
    cout << "Enter number of tickets: ";
    cin >> myTicket.numTickets;

    if (myTicket.numTickets <= 0) {
        cout << "Invalid number of tickets! Exiting...\n";
        return 1;
    }

    // Select seat location
    string row, seatNumber;
    cout << "Enter seat row (e.g., A, B, C...): ";
    cin >> row;
    cout << "Enter seat number: ";
    cin >> seatNumber;
    myTicket.seatLocation = row + seatNumber;

    // Generate Booking ID
    myTicket.bookingID = generateBookingID();

    // Display Ticket Summary
    cout << "\nTicket Booking Confirmation\n";
    cout << "Booking ID   : " << myTicket.bookingID << endl;
    cout << "Name         : " << myTicket.name << endl;
    cout << "Ticket Type  : " << myTicket.ticketType << endl;
    cout << "Event        : " << myTicket.event << endl;
    cout << "Seat Type    : " << myTicket.seatType << endl;
    cout << "Seat Location: " << myTicket.seatLocation << endl;
    cout << "Tickets      : " << myTicket.numTickets << endl;
    cout << "===================================\n";
    
    // Save ticket details to file
    saveTicketToFile(myTicket);

    cout << "\nThank you for booking with us!\n";

    return 0;
}

