#include <iostream>
#include "BST.h"
#include "Linkedlist.h"
#include "PriorityQueue.h"
#include "Stack.h"
using namespace std;
// Patient Records:
//  Use Linked Lists to maintain a history of patient //visits for easy record //retrieval.

class Main {
private:
    LinkedList list[10];
    Stack stack;
    Queue appointments;
    BinarySearchtree trees[10];

    bool DoctorAvailability() {
        if (stack.Top == NULL || stack.Count() <= 10) {
            cout << "Doctor is Available! \n";
            return true;
        }
        cout << "Doctor is not Available! \n";
        return false;
    }

    void PatientHistory(string value, int index, int urgency) {
        list[index].insertNode(value, index);
        Reporting(index, urgency, value);
    }

    void AppointmentScheduling(string value, int urgency, int index) {
        if (DoctorAvailability()) {
            appointments.Enqueue(value, urgency);
            stack.Push(index);
            
           // list[0].insertNode(value,0);
        }
    }

    void Reporting(int index, int value, string disease) {
        if (trees[index].GetRoot() != nullptr) {
            trees[index].InsertNode(trees[index].GetRoot(), value, disease);
            return;
        }
        trees[index].InitialTree(value, disease);
    }

public:
    void Implementation() {
        int choice = 0;
        int i = 0;
        string reason;
        int urgencyLevel = 0;
        int patientHistoryIndex = 0;
        int patientReport = 0;

        while (true) {
            cout << "\nPress 1 to determine Doctor Availability\n";
            cout << "Press 2 to Schedule appointments\n";
            cout << "Press 3 to see History of a patient\n";
            cout << "Press 4 to generate report on patient statistics\n";
            cout << "Press 5 to exit program\n";
            cout << "Enter your choice: ";
            cin >> choice;
            cin.ignore();

            switch (choice) {
            case 1:
                DoctorAvailability();
                break;
            case 2:
                cout << "What brings you here today? ";
                getline(cin, reason);
                cout << "Enter urgency level (1-10): ";
                cin >> urgencyLevel;
                cout << "Patient Number : \n";
                cin >> i;
                AppointmentScheduling(reason, urgencyLevel,i);
                PatientHistory(reason,i,urgencyLevel);

                
                break;
            case 3:
                
                list[i].PrintList();
             
                break;
            case 4:
                cout << "Generating Report\n";
                cout << "Which Patient Report? ";
                
                cin >> patientReport;
                

                trees[i].Display(trees[i].GetRoot());
                i++;

                break;
            case 5:
                cout << "Exiting Program! \n";
                return;
            default:
                cout << "Invalid choice, please try again.\n";
            }
        }
    }
};

int main() {
    Main obj;
    obj.Implementation();
    return 0;
}