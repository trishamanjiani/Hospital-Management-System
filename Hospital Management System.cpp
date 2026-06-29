#include <iostream>
#include <queue>
using namespace std;

struct Patient {
    int id;
    string name;
    int age;
    string disease;
    Patient* next;
};

Patient* head = NULL;
queue<string> waitingQueue;

// Add Patient
void addPatient() {
    Patient* newPatient = new Patient();

    cout << "Enter Patient ID: ";
    cin >> newPatient->id;

    cout << "Enter Name: ";
    cin >> newPatient->name;

    cout << "Enter Age: ";
    cin >> newPatient->age;

    cout << "Enter Disease: ";
    cin >> newPatient->disease;

    newPatient->next = NULL;

    if (head == NULL) {
        head = newPatient;
    } else {
        Patient* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newPatient;
    }

    cout << "Patient added successfully!\n";
}

// Display Patients
void displayPatients() {
    if (head == NULL) {
        cout << "No patient records found.\n";
        return;
    }

    Patient* temp = head;

    cout << "\nPatient List:\n";
    while (temp != NULL) {
        cout << "ID: " << temp->id << endl;
        cout << "Name: " << temp->name << endl;
        cout << "Age: " << temp->age << endl;
        cout << "Disease: " << temp->disease << endl;
        cout << "-------------------\n";

        temp = temp->next;
    }
}

// Search Patient
void searchPatient() {
    int id;
    cout << "Enter Patient ID to search: ";
    cin >> id;

    Patient* temp = head;

    while (temp != NULL) {
        if (temp->id == id) {
            cout << "Patient Found!\n";
            cout << "Name: " << temp->name << endl;
            cout << "Age: " << temp->age << endl;
            cout << "Disease: " << temp->disease << endl;
            return;
        }
        temp = temp->next;
    }

    cout << "Patient not found.\n";
}

// Add to Waiting Queue
void addToQueue() {
    string name;
    cout << "Enter Patient Name for Queue: ";
    cin >> name;

    waitingQueue.push(name);
    cout << "Patient added to waiting queue.\n";
}

// Serve Next Patient
void servePatient() {
    if (waitingQueue.empty()) {
        cout << "No patients in queue.\n";
        return;
    }

    cout << "Next patient: " << waitingQueue.front() << endl;
    waitingQueue.pop();
}

int main() {
    int choice;

    do {
        cout << "\n---- Hospital Patient Management System ----\n";
        cout << "1. Add Patient\n";
        cout << "2. Display Patients\n";
        cout << "3. Search Patient\n";
        cout << "4. Add Patient to Waiting Queue\n";
        cout << "5. Serve Next Patient\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addPatient(); break;
            case 2: displayPatients(); break;
            case 3: searchPatient(); break;
            case 4: addToQueue(); break;
            case 5: servePatient(); break;
            case 6: cout << "Exiting program.\n"; break;
            default: cout << "Invalid choice.\n";
        }

    } while (choice != 6);

    return 0;
}
