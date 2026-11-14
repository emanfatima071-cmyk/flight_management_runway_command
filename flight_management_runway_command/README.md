# Runway Command -- Flight Management System

## Project Information

-   **Course:** Data Structures and Algorithms
-   **Language:** C++
-   **Data Structure:** Priority Queue (Max-Heap)
-   **Module:** Runway Command
-   **Implementation:** Array-Based Max-Heap

## 1. Project Overview

Runway Command is a C++-based Flight Departure Management System that
manages flights waiting for takeoff at an airport.

Since only one flight can take off at a time, the system uses a
**Max-Heap Priority Queue** to determine which flight should take off
first.

Each flight is assigned a priority score based on its status and delay
minutes. The flight with the highest priority is always selected first.

## 2. Flight Priority Rules

The priority score is calculated automatically by the program.

  Flight Status     Base Score
  --------------- ------------
  Emergency                300
  Delayed                  200
  Scheduled                100

**Priority Score = Base Score + Delay Minutes**

Additional rules:

-   Delay minutes cannot exceed 99.
-   Emergency flights have the highest priority.
-   If two flights have equal scores, the earlier departure time goes
    first.
-   If departure times are also equal, the lower Flight ID goes first.

## 3. Features

The system provides the following features:

1.  **Register Flight:** Add a new Scheduled or Delayed flight to the
    priority queue.
2.  **View Next Flight:** Display the flight with the highest priority
    without removing it.
3.  **Clear Flight for Takeoff:** Remove the highest-priority flight
    from the heap.
4.  **Declare Emergency:** Change a flight's status to Emergency and
    increase its priority.
5.  **Report Flight Delay:** Add additional delay minutes and update the
    flight's priority.
6.  **Display Departure Board:** Display all waiting flights in takeoff
    order.

The program also checks duplicate Flight IDs and rejects invalid delay
requests.

## 4. Heap Operations Used

The project implements the following operations based on Heaps and
Priority Queues (CLRS Chapter 6):

  Operation             Purpose
  --------------------- ------------------------------------------------
  `PARENT(i)`           Finds the parent of a node
  `LEFT(i)`             Finds the left child
  `RIGHT(i)`            Finds the right child
  `MAX-HEAPIFY`         Restores the max-heap property
  `BUILD-MAX-HEAP`      Builds a max-heap from an array
  `HEAP-MAXIMUM`        Returns the highest-priority flight
  `HEAP-EXTRACT-MAX`    Removes the highest-priority flight
  `HEAP-INCREASE-KEY`   Increases a flight's priority
  `MAX-HEAP-INSERT`     Inserts a new flight
  `HEAPSORT`            Sorts a temporary copy for the departure board

The heap is implemented manually using an array without using the STL
`priority_queue`.

## 5. Flight Record Information

Each flight contains the following information:

-   Flight ID
-   Source
-   Destination
-   Airline
-   Departure Time
-   Arrival Time
-   Flight Duration
-   Ticket Price
-   Status
-   Delay Minutes
-   Priority Score

## 6. File Handling

The program uses `priority_flights.txt` to store flight records.

-   Flights are loaded automatically when the program starts.
-   Each flight is stored on a separate line.
-   Flight information is separated by commas.
-   Waiting flights are saved when the user exits the program.

The file contains sample flight records for testing.

## 7. Project Structure

``` text
flight-management-system-runway-command/
├── main.cpp
├── priority_flights.txt
└── README.md
```

## 8. How to Run the Project

1.  Download or clone this repository.
2.  Open the project in Visual Studio or another C++ IDE.
3.  Make sure `priority_flights.txt` is in the program's working
    directory.
4.  Compile and run `main.cpp`.
5.  Use the displayed menu to manage flights.

## 9. Sample Menu

``` text
============== RUNWAY COMMAND ==============

1. Register Flight
2. View Next Flight
3. Clear Flight for Takeoff
4. Declare Emergency
5. Report Flight Delay
6. Display Departure Board
0. Exit

=============================================
Enter your choice:
```

## 10. Testing

The project can be tested using the six sample flights provided in
`priority_flights.txt`.

Expected initial takeoff order:

**205 → 203 → 206 → 202 → 201 → 204**

Additional tests include:

-   Reporting a 30-minute delay for Flight 201.
-   Declaring an emergency for Flight 204.
-   Clearing the highest-priority flight.
-   Attempting to register a duplicate Flight ID.
-   Reporting a delay of zero minutes.
-   Entering a Flight ID that does not exist.
-   Saving and loading flights after restarting the program.

## 11. Technologies Used

-   C++
-   Object-Oriented Programming
-   Arrays
-   Max-Heap
-   Priority Queue
-   File Handling

## 12. Author

**Student Project -- Data Structures and Algorithms**

**Project Name:** Runway Command -- Flight Management System
