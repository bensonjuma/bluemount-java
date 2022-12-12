// Bluemont chain hotels
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    // declare room prices
    const double singleRoom = 60.00;
    const double doubleRoom = 75.0;
    const double kingRoom = 100.0;
    const double suitRoom = 150.0;

    // declare variables
    // hotel location
    string location;
    // no of rooms
    int noOfRooms;
    // total no of rooms
    int totalNoOfRooms = 0;
    // type of room
    char roomType;
    // no of floors
    int noOfFloors;
    // array to store no of rooms per floor
    int noOfRoomsPerFloor[10];
    // array to store no of occupied rooms per floor
    int noOfOccupiedRoomsPerFloor[10];
    // no of occupied room types per floor
    int noOfOccupiedSingleRoomsPerFloor[10];
    int noOfOccupiedDoubleRoomsPerFloor[10];
    int noOfOccupiedKingRoomsPerFloor[10];
    int noOfOccupiedSuitRoomsPerFloor[10];
    // total no of occupied rooms
    int noOfOccupiedSingleRooms = 0;
    int noOfOccupiedDoubleRooms = 0;
    int noOfOccupiedKingRooms = 0;
    int noOfOccupiedSuitRooms = 0;
    // total no of occupied rooms
    int totalNoOfOccupiedRooms = 0;
    // hotel income
    double hotelIncome = 0.0;
    // unoccupied rooms
    int unoccupiedRooms = 0;
    // rate of occupancy
    double rateOfOccupancy = 0.0;
    // floor no with max no of rooms
    int floorNoWithMinNoOfRooms = 1;

    // start of program
    cout << "==============================================================" << endl;
    // center text
    cout << setw(40) << "Bluemont chain hotels" << endl;
    cout << "==============================================================" << endl;
    // ask user where hotel is located
    cout << "Where is the hotel located?" << endl;
    cin >> location;
    // ask user no of floors
    cout << "How many floors does the hotel have?" << endl;
    cin >> noOfFloors;
    // ensure no of floors 1 <= 5
    while (noOfFloors < 1 || noOfFloors > 5)
    {
        cout << "The hotel can only have between 1 and 5 floors! Please try again." << endl;
        cout << "How many floors does the hotel have?" << endl;
        cin >> noOfFloors;
    }
    // user enter no of rooms on each floor
    for (int i = 0; i < noOfFloors; i++)
    {

        cout << "How many rooms are on floor " << i + 1 << "?" << endl;
        // check total no of rooms on each floor must be <= 30
        cin >> noOfRoomsPerFloor[i];
        while (noOfRoomsPerFloor[i] > 30)
        {
            cout << "The hotel can only have 30 rooms or less on each floor" << endl;
            cout << "How many rooms are on floor " << i + 1 << "?" << endl;
            cin >> noOfRoomsPerFloor[i];
        }
        // no of occupied rooms on each floor
        cout << "How many rooms are occupied on floor " << i + 1 << "?" << endl;
        cin >> noOfOccupiedRoomsPerFloor[i];
        // check total no of occupied rooms doesnt exceed total no of rooms per floor
        // no of SINGLE occupied rooms on each floor
        cout << "How many SINGLE rooms are occupied on floor " << i + 1 << "?" << endl;
        cin >> noOfOccupiedSingleRoomsPerFloor[i];
        // no of DOUBLE occupied rooms on each floor
        cout << "How many DOUBLE rooms are occupied on floor " << i + 1 << "?" << endl;
        cin >> noOfOccupiedDoubleRoomsPerFloor[i];
        // no of KING occupied rooms on each floor
        cout << "How many KING rooms are occupied on floor " << i + 1 << "?" << endl;
        cin >> noOfOccupiedKingRoomsPerFloor[i];
        // no of SUIT occupied rooms on each floor
        cout << "How many SUIT rooms are occupied on floor " << i + 1 << "?" << endl;
        cin >> noOfOccupiedSuitRoomsPerFloor[i];
        // check total no of occupied rooms doesnt exceed total no of rooms per floor
    }
    // test print no of occupied rooms
    /* for (int i = 0; i < noOfFloors; i++)
    {
        cout << "Floor " << i + 1 << " has " << noOfRoomsPerFloor[i] << " rooms" << endl;
        cout << "Floor " << i + 1 << " has " << noOfOccupiedRoomsPerFloor[i] << " occupied rooms" << endl;
        cout << "Floor " << i + 1 << " has " << noOfOccupiedSingleRoomsPerFloor[i] << " occupied SINGLE rooms" << endl;
        cout << "Floor " << i + 1 << " has " << noOfOccupiedDoubleRoomsPerFloor[i] << " occupied DOUBLE rooms" << endl;
        cout << "Floor " << i + 1 << " has " << noOfOccupiedKingRoomsPerFloor[i] << " occupied KING rooms" << endl;
        cout << "Floor " << i + 1 << " has " << noOfOccupiedSuitRoomsPerFloor[i] << " occupied SUIT rooms" << endl;
    } */
    // calculate hotel income
    for (int i = 0; i < noOfFloors; i++)
    {
        hotelIncome += noOfOccupiedSingleRoomsPerFloor[i] * singleRoom;
        hotelIncome += noOfOccupiedDoubleRoomsPerFloor[i] * doubleRoom;
        hotelIncome += noOfOccupiedKingRoomsPerFloor[i] * kingRoom;
        hotelIncome += noOfOccupiedSuitRoomsPerFloor[i] * suitRoom;
    }
    // calculate unoccupied rooms
    for (int i = 0; i < noOfFloors; i++)
    {
        unoccupiedRooms += (noOfRoomsPerFloor[i] - noOfOccupiedRoomsPerFloor[i]);
    }
    // calculate rate of occupancy
    for (int i = 0; i < noOfFloors; i++)
    {
        totalNoOfOccupiedRooms += noOfOccupiedRoomsPerFloor[i];
    }
    // calculate no of rooms
    for (int i = 0; i < noOfFloors; i++)
    {
        totalNoOfRooms += noOfRoomsPerFloor[i];
    }
    int min = noOfRoomsPerFloor[0];
    // calculate floor with least no of rooms
    for (int i = 0; i < noOfFloors; i++)
    {
        if (noOfRoomsPerFloor[i] < min)
        {
            min = noOfRoomsPerFloor[i];
            floorNoWithMinNoOfRooms = i + 1;
        }
    }
    // calculate rate of occupancy
    rateOfOccupancy = (totalNoOfOccupiedRooms / totalNoOfRooms * 100);
    /* // test print rate of occupancy
    cout << "Rate of occupancy is " << rateOfOccupancy << "%" << endl;
    // test print total no of rooms
    cout << "Total no of rooms is " << totalNoOfRooms << endl;
    // test print total no of occupied rooms
    cout << "Total no of occupied rooms is " << totalNoOfOccupiedRooms << endl; */

    // check occupancy < 60%
    if (rateOfOccupancy < 60)
    {
        cout << "The hotel is not doing well" << endl;
    }

    // display results
    cout << "==============================================================" << endl;
    cout << "Hotel " << location << " has " << totalNoOfRooms << " rooms" << endl;
    cout << "Hotel " << location << " has " << totalNoOfOccupiedRooms << " occupied rooms" << endl;
    cout << "Hotel " << location << " has " << unoccupiedRooms << " unoccupied rooms" << endl;
    cout << "Hotel " << location << " has " << rateOfOccupancy << "% occupancy rate" << endl;
    cout << "Hotel " << location << " has " << hotelIncome << " income" << endl;
    cout << "Floor " << floorNoWithMinNoOfRooms << " has the least no of rooms" << endl;
    cout << "==============================================================" << endl;
    
    /* cout << "Hotel location: " << location << endl;
    cout << "Total no of rooms: " << totalNoOfRooms << endl;
    cout << "Total no of occupied rooms: " << totalNoOfOccupiedRooms << endl;
    cout << "Total no of unoccupied rooms: " << unoccupiedRooms << endl;
    cout << "Hotel income: " << hotelIncome << endl;
    cout << "Rate of occupancy: " << rateOfOccupancy << "%" << endl;
    cout << "Floor with min no of rooms: " << floorNoWithMinNoOfRooms << endl;
    cout << "Thank you for using Bluemont chain hotels" << endl; */
    // end of program

    // pause program
    system("pause");
    return 0;
}