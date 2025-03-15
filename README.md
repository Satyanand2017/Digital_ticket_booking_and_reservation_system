# Digital_ticket_booking_and_reservation_system

## Introduction
The Digital Ticket Booking System is a C++ console-based application that allows users to register, log in, and book different types of tickets. The system supports ticket types like movies, trains, buses, and concerts, with various seat types. The booking details are stored in a file for future reference.

## Features
- User registration and login system
- Booking tickets for movies, trains, buses, and concerts
- Seat selection with different seat types (General, VIP, First-Class, Economy)
- Random Booking ID generation
- Saves ticket details to a file (`ticket_booking.txt`)

## Prerequisites
- C++ Compiler (MinGW-w64 for Windows)
- VS Code (or any C++ compatible IDE)

## Installation
1. **Install MinGW-w64 (GCC Compiler)**
   - Download from [WinLibs](https://winlibs.com/).
   - Add `C:\MinGW-w64\bin` to system PATH.

2. **Clone or Download the Project**
   ```sh
   git clone https://github.com/your-repository/ticket-booking-system.git
   cd ticket-booking-system
   ```

3. **Compile the Program**
   ```sh
   g++ ticket_booking.cpp -o ticket_booking.exe
   ```

4. **Run the Program**
   ```sh
   ./ticket_booking.exe
   ```

## Usage
1. **Register or Login**
   - New users can register with a username and password.
   - Existing users can log in with their credentials.
2. **Book a Ticket**
   - Choose a ticket type (Movie, Train, Bus, Concert).
   - Provide event details.
   - Select seat type and location.
   - Enter the number of tickets.
   - Confirm booking.
3. **View Booking Details**
   - Booking details are displayed on-screen.
   - A record is saved in `ticket_booking.txt`.

## File Structure
```
Ticket-Booking-System/
│── ticket_booking.cpp    # Main source code
│── ticket_booking.txt    # Stored ticket details
│── README.md             # Documentation
```

## Example Output
```
1. Register
2. Login
3. Exit
Enter choice: 2
Enter username: user1
Enter password: pass123
Login successful! Welcome, user1.

Enter your name: John Doe
1. Movie Ticket
2. Train Ticket
3. Bus Ticket
4. Concert Ticket
Enter your choice (1-4): 1
Enter the name of Movie: Avengers: Endgame

Select Seat Type:
1. General
2. VIP
3. First-Class
4. Economy
Enter your choice (1-4): 2
Enter number of tickets: 2
Enter seat row (e.g., A, B, C...): A
Enter seat number: 10

Ticket Booking Confirmation
Booking ID   : 54321
Name         : John Doe
Ticket Type  : Movie
Event        : Avengers: Endgame
Seat Type    : VIP
Seat Location: A10
Tickets      : 2
===================================
Ticket details saved to 'ticket_booking.txt'
Thank you for booking with us!
```

## Future Enhancements
- Add graphical user interface (GUI)
- Implement online payment integration
- Enable database storage for better record management

## License
This project is open-source and free to use. Feel free to modify and enhance it!

