
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int max_item = 50;

class Flight
{
private:

    int flightID;
    string source;
    string destination;
    string airline;

    int departureHour;
    int departureMinute;

    int arrivalHour;
    int arrivalMinute;

    int durationHours;
    int durationMinutes;

    double ticketPrice;
    string status;

    int delayMinutes;
    int priorityScore;

public:

    Flight()
    {
        flightID = 0;

        departureHour = 0;
        departureMinute = 0;

        arrivalHour = 0;
        arrivalMinute = 0;

        durationHours = 0;
        durationMinutes = 0;

        ticketPrice = 0;

        status = "Scheduled";

        delayMinutes = 0;
        priorityScore = 100;
    }

    void CalculateDuration()
    {
        int departureTotal =
            departureHour * 60 + departureMinute;

        int arrivalTotal =
            arrivalHour * 60 + arrivalMinute;

        if (arrivalTotal < departureTotal)
        {
            arrivalTotal = arrivalTotal + 1440;
        }

        int total = arrivalTotal - departureTotal;

        durationHours = total / 60;
        durationMinutes = total % 60;
    }

    void CalculatePriority()
    {
        int baseScore;

        if (status == "Emergency")
        {
            baseScore = 300;
        }
        else if (status == "Delayed")
        {
            baseScore = 200;
        }
        else
        {
            baseScore = 100;
        }

        priorityScore = baseScore + delayMinutes;
    }

    // Compare two flights according to priority

    bool HigherPriority(Flight other)
    {
        if (priorityScore > other.priorityScore)
            return true;

        if (priorityScore < other.priorityScore)
            return false;

        int time1 =
            departureHour * 60 + departureMinute;

        int time2 =
            other.departureHour * 60 + other.departureMinute;

        if (time1 < time2)
            return true;

        if (time1 > time2)
            return false;

        return flightID < other.flightID;
    }

    bool initialize()
    {
        cout << "Enter Flight ID: ";
        cin >> flightID;

        cout << "Enter Source: ";
        cin >> source;

        cout << "Enter Destination: ";
        cin >> destination;

        cout << "Enter Airline: ";
        cin >> airline;

        cout << "Enter Departure Hour: ";
        cin >> departureHour;

        if (departureHour < 0 || departureHour > 23)
        {
            cout << "Invalid hour!" << endl;
            return false;
        }

        cout << "Enter Departure Minute: ";
        cin >> departureMinute;

        if (departureMinute < 0 || departureMinute > 59)
        {
            cout << "Invalid minute!" << endl;
            return false;
        }

        cout << "Enter Arrival Hour: ";
        cin >> arrivalHour;

        if (arrivalHour < 0 || arrivalHour > 23)
        {
            cout << "Invalid hour!" << endl;
            return false;
        }

        cout << "Enter Arrival Minute: ";
        cin >> arrivalMinute;

        if (arrivalMinute < 0 || arrivalMinute > 59)
        {
            cout << "Invalid minute!" << endl;
            return false;
        }

        cout << "Enter Ticket Price: ";
        cin >> ticketPrice;

        if (ticketPrice < 0)
        {
            cout << "Invalid price!" << endl;
            return false;
        }

        int choice;

        cout << "1. Scheduled" << endl;
        cout << "2. Delayed" << endl;
        cout << "Select Status: ";
        cin >> choice;

        if (choice == 1)
        {
            status = "Scheduled";
            delayMinutes = 0;
        }
        else if (choice == 2)
        {
            status = "Delayed";

            cout << "Enter Delay Minutes (1-99): ";
            cin >> delayMinutes;

            if (delayMinutes < 1 || delayMinutes > 99)
            {
                cout << "Invalid delay!" << endl;
                return false;
            }
        }
        else
        {
            cout << "Invalid status!" << endl;
            return false;
        }

        CalculateDuration();
        CalculatePriority();

        return true;
    }

    void setFlightData(
        int id, string src, string dest, string air,
        int dh, int dm, int ah, int am,
        double price, string st, int delay)
    {
        flightID = id;
        source = src;
        destination = dest;
        airline = air;

        departureHour = dh;
        departureMinute = dm;

        arrivalHour = ah;
        arrivalMinute = am;

        ticketPrice = price;
        status = st;
        delayMinutes = delay;

        CalculateDuration();
        CalculatePriority();
    }

    void setStatus(string st)
    {
        status = st;
        CalculatePriority();
    }

    void setDelayMinutes(int d)
    {
        delayMinutes = d;
        CalculatePriority();
    }

    int getFlightID()
    {
        return flightID;
    }

    int getPriorityScore()
    {
        return priorityScore;
    }

    int getDelayMinutes()
    {
        return delayMinutes;
    }

    string getDestination()
    {
        return destination;
    }

    string getAirline()
    {
        return airline;
    }

    string getStatus()
    {
        return status;
    }

    void print()
    {
        cout << "\nFlight ID: " << flightID;
        cout << "\nSource: " << source;
        cout << "\nDestination: " << destination;
        cout << "\nAirline: " << airline;

        cout << "\nDeparture Time: ";

        if (departureHour < 10)
            cout << "0";

        cout << departureHour << ":";

        if (departureMinute < 10)
            cout << "0";

        cout << departureMinute;

        cout << "\nArrival Time: ";

        if (arrivalHour < 10)
            cout << "0";

        cout << arrivalHour << ":";

        if (arrivalMinute < 10)
            cout << "0";

        cout << arrivalMinute;

        cout << "\nDuration: "
            << durationHours << " hours "
            << durationMinutes << " minutes";

        cout << "\nTicket Price: PKR " << ticketPrice;
        cout << "\nStatus: " << status;
        cout << "\nDelay Minutes: " << delayMinutes;
        cout << "\nPriority Score: " << priorityScore << endl;
    }

    void Save(ofstream& fout)
    {
        fout << flightID << ","
            << source << ","
            << destination << ","
            << airline << ",";

        if (departureHour < 10)
            fout << "0";

        fout << departureHour << ":";

        if (departureMinute < 10)
            fout << "0";

        fout << departureMinute << ",";

        if (arrivalHour < 10)
            fout << "0";

        fout << arrivalHour << ":";

        if (arrivalMinute < 10)
            fout << "0";

        fout << arrivalMinute << ",";

        int fraction = (durationMinutes * 100 + 30) / 60;
        int hours = durationHours;

        if (fraction == 100)
        {
            hours++;
            fraction = 0;
        }

        fout << hours << ".";

        if (fraction < 10)
            fout << "0";

        fout << fraction << ","
            << ticketPrice << ","
            << status << ","
            << delayMinutes << ","
            << priorityScore << endl;
    }
};


class maxheap
{
private:

    Flight A[max_item + 1];

    int heap_size;


    // PARENT(i)

    int PARENT(int i)
    {
        return i / 2;
    }


    // LEFT(i)

    int LEFT(int i)
    {
        return 2 * i;
    }


    // RIGHT(i)

    int RIGHT(int i)
    {
        return 2 * i + 1;
    }


    // EXCHANGE

    void EXCHANGE(int i, int j)
    {
        Flight temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }


    // Search Flight ID

    int SEARCH(int id)
    {
        for (int i = 1; i <= heap_size; i++)
        {
            if (A[i].getFlightID() == id)
                return i;
        }

        return 0;
    }


    // HEAP-INCREASE-KEY

    void HEAP_INCREASE_KEY(int i, Flight key)
    {
        if (key.getPriorityScore() <
            A[i].getPriorityScore())
        {
            cout << "New priority cannot be smaller!" << endl;
            return;
        }

        A[i] = key;

        while (i > 1 &&
            A[i].HigherPriority(A[PARENT(i)]))
        {
            EXCHANGE(i, PARENT(i));

            i = PARENT(i);
        }
    }


    // MAX-HEAPIFY

    void MAX_HEAPIFY(int i)
    {
        int l = LEFT(i);
        int r = RIGHT(i);

        int largest = i;

        if (l <= heap_size &&
            A[l].HigherPriority(A[largest]))
        {
            largest = l;
        }

        if (r <= heap_size &&
            A[r].HigherPriority(A[largest]))
        {
            largest = r;
        }

        if (largest != i)
        {
            EXCHANGE(i, largest);

            MAX_HEAPIFY(largest);
        }
    }


    // MAX-HEAPIFY for temporary board array

    void BOARD_MAX_HEAPIFY(
        Flight B[], int size, int i)
    {
        int l = 2 * i;
        int r = 2 * i + 1;

        int largest = i;

        if (l <= size &&
            B[l].HigherPriority(B[largest]))
        {
            largest = l;
        }

        if (r <= size &&
            B[r].HigherPriority(B[largest]))
        {
            largest = r;
        }

        if (largest != i)
        {
            Flight temp = B[i];
            B[i] = B[largest];
            B[largest] = temp;

            BOARD_MAX_HEAPIFY(B, size, largest);
        }
    }


    // HEAPSORT for departure board

    void HEAPSORT(Flight B[], int n)
    {
        int size = n;

        // BUILD-MAX-HEAP

        for (int i = n / 2; i >= 1; i--)
        {
            BOARD_MAX_HEAPIFY(B, size, i);
        }

        // HEAPSORT

        for (int i = n; i >= 2; i--)
        {
            Flight temp = B[1];
            B[1] = B[i];
            B[i] = temp;

            size--;

            BOARD_MAX_HEAPIFY(B, size, 1);
        }
    }


    // Convert string to integer

    int ToInt(string s)
    {
        int number = 0;

        for (int i = 0; i < s.length(); i++)
        {
            number = number * 10 + (s[i] - '0');
        }

        return number;
    }


    // Convert string to decimal

    double ToDouble(string s)
    {
        double number = 0;
        double decimal = 0.1;

        bool point = false;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '.')
            {
                point = true;
            }
            else if (!point)
            {
                number = number * 10 + (s[i] - '0');
            }
            else
            {
                number = number + (s[i] - '0') * decimal;
                decimal = decimal / 10;
            }
        }

        return number;
    }


public:

    maxheap()
    {
        heap_size = 0;
    }


    // MAX-HEAP-INSERT

    void MAX_HEAP_INSERT(Flight key)
    {
        if (heap_size == max_item)
        {
            cout << "Heap is full!" << endl;
            return;
        }

        if (SEARCH(key.getFlightID()) != 0)
        {
            cout << "Duplicate Flight ID!" << endl;
            return;
        }

        heap_size++;

        A[heap_size] = key;

        HEAP_INCREASE_KEY(heap_size, key);

        cout << "Flight inserted successfully!" << endl;

        cout << "Priority Score: "
            << key.getPriorityScore() << endl;
    }


    // HEAP-MAXIMUM

    void HEAP_MAXIMUM()
    {
        if (heap_size == 0)
        {
            cout << "Heap is empty!" << endl;
            return;
        }

        cout << "\nHighest Priority Flight:" << endl;

        A[1].print();
    }


    // HEAP-EXTRACT-MAX

    void HEAP_EXTRACT_MAX()
    {
        if (heap_size == 0)
        {
            cout << "Heap is empty!" << endl;
            return;
        }

        Flight maximum = A[1];

        cout << "\nFlight cleared for takeoff:" << endl;

        maximum.print();

        A[1] = A[heap_size];

        heap_size--;

        if (heap_size > 0)
        {
            MAX_HEAPIFY(1);
        }
    }


    // Declare Emergency using HEAP-INCREASE-KEY

    void DECLARE_EMERGENCY(int id)
    {
        int i = SEARCH(id);

        if (i == 0)
        {
            cout << "Flight not found!" << endl;
            return;
        }

        if (A[i].getStatus() == "Emergency")
        {
            cout << "Already an Emergency flight!" << endl;
            return;
        }

        A[i].setStatus("Emergency");

        Flight key = A[i];

        HEAP_INCREASE_KEY(i, key);

        cout << "Emergency declared successfully!" << endl;

        cout << "New Priority Score: "
            << key.getPriorityScore() << endl;
    }


    // Report Delay using HEAP-INCREASE-KEY

    void REPORT_DELAY(int id, int minutes)
    {
        int i = SEARCH(id);

        if (i == 0)
        {
            cout << "Flight not found!" << endl;
            return;
        }

        if (minutes < 1)
        {
            cout << "Delay must be at least 1 minute!" << endl;
            return;
        }

        int newDelay =
            A[i].getDelayMinutes() + minutes;

        if (newDelay > 99)
        {
            cout << "Delay cannot exceed 99 minutes!" << endl;
            return;
        }

        A[i].setDelayMinutes(newDelay);

        if (A[i].getStatus() == "Scheduled")
        {
            A[i].setStatus("Delayed");
        }

        Flight key = A[i];

        HEAP_INCREASE_KEY(i, key);

        cout << "Delay reported successfully!" << endl;

        cout << "New Priority Score: "
            << key.getPriorityScore() << endl;
    }


    // Display Departure Board

    void DISPLAY_BOARD()
    {
        if (heap_size == 0)
        {
            cout << "No flights waiting!" << endl;
            return;
        }

        Flight B[max_item + 1];

        for (int i = 1; i <= heap_size; i++)
        {
            B[i] = A[i];
        }

        HEAPSORT(B, heap_size);


        cout << "Position\tFlight ID\tDestination"
            << "\tAirline\tStatus\tScore" << endl;

        // HEAPSORT gives ascending order.
        // Display backwards for highest priority first.

        int position = 1;

        for (int i = heap_size; i >= 1; i--)
        {
            cout << position << "\t\t"
                << B[i].getFlightID() << "\t\t"
                << B[i].getDestination() << "\t\t"
                << B[i].getAirline() << "\t"
                << B[i].getStatus() << "\t"
                << B[i].getPriorityScore()
                << endl;

            position++;
        }

    }


    // BUILD-MAX-HEAP

    void BUILD_MAX_HEAP()
    {
        for (int i = heap_size / 2; i >= 1; i--)
        {
            MAX_HEAPIFY(i);
        }
    }


    // Load flights from file

    void LOAD_FROM_FILE()
    {
        ifstream fin("priority_flights.txt");

        if (!fin)
        {
            cout << "File not found. Starting empty." << endl;
            return;
        }

        string line;

        while (getline(fin, line))
        {
            string fields[11];

            int field = 0;
            int start = 0;

            for (int i = 0; i <= line.length(); i++)
            {
                if (i == line.length() || line[i] == ',')
                {
                    if (field < 11)
                    {
                        fields[field] = line.substr(start, i - start);
                        field++;
                    }

                    start = i + 1;
                }
            }

            if (field != 11)
            {
                cout << "Invalid record skipped!" << endl;
                continue;
            }

            int id = ToInt(fields[0]);

            int dh = ToInt(fields[4].substr(0, 2));
            int dm = ToInt(fields[4].substr(3, 2));

            int ah = ToInt(fields[5].substr(0, 2));
            int am = ToInt(fields[5].substr(3, 2));

            double price = ToDouble(fields[7]);

            int delay = ToInt(fields[9]);

            if (id <= 0 || dh > 23 || dm > 59 ||
                ah > 23 || am > 59 ||
                delay > 99 || price < 0)
            {
                cout << "Invalid flight data!" << endl;
                continue;
            }

            if (fields[8] != "Scheduled" &&
                fields[8] != "Delayed" &&
                fields[8] != "Emergency")
            {
                cout << "Invalid status!" << endl;
                continue;
            }

            Flight flight;

            flight.setFlightData(
                id,
                fields[1],
                fields[2],
                fields[3],
                dh,
                dm,
                ah,
                am,
                price,
                fields[8],
                delay
            );

            if (heap_size < max_item &&
                SEARCH(id) == 0)
            {
                heap_size++;

                A[heap_size] = flight;
            }
        }

        fin.close();

        BUILD_MAX_HEAP();

        cout << "Flights loaded successfully!" << endl;
    }


    // Save flights to file

    void SAVE_TO_FILE()
    {
        ofstream fout("priority_flights.txt");

        if (!fout)
        {
            cout << "Cannot open file!" << endl;
            return;
        }

        for (int i = 1; i <= heap_size; i++)
        {
            A[i].Save(fout);
        }

        fout.close();

        cout << "Flights saved successfully!" << endl;
    }

};


int main()
{
    maxheap runway;

    runway.LOAD_FROM_FILE();

    int choice;

    do
    {

        cout << "1. Register Flight" << endl;
        cout << "2. View Next Flight" << endl;
        cout << "3. Clear Flight for Takeoff" << endl;
        cout << "4. Declare Emergency" << endl;
        cout << "5. Report Flight Delay" << endl;
        cout << "6. Display Departure Board" << endl;
        cout << "0. Exit" << endl;


        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            Flight flight;

            if (flight.initialize())
            {
                runway.MAX_HEAP_INSERT(flight);
            }

            break;
        }

        case 2:
        {
            runway.HEAP_MAXIMUM();
            break;
        }

        case 3:
        {
            runway.HEAP_EXTRACT_MAX();
            break;
        }

        case 4:
        {
            int id;

            cout << "Enter Flight ID:";
            cin >> id;

            runway.DECLARE_EMERGENCY(id);

            break;
        }

        case 5:
        {
            int id, minutes;

            cout << "Enter Flight ID:";
            cin >> id;

            cout << "Enter additional delay minutes: ";
            cin >> minutes;

            runway.REPORT_DELAY(id, minutes);

            break;
        }

        case 6:
        {
            runway.DISPLAY_BOARD();
            break;
        }

        case 0:
        {
            runway.SAVE_TO_FILE();

            cout << "Exiting Runway Command!" << endl;

            break;
        }

        default:
        {
            cout << "Invalid choice!" << endl;
        }

        }

    } while (choice != 0);

    return 0;
}
