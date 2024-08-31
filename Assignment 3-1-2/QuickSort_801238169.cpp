//
//  QuickSort_Skeleton.cpp
//
//  Created by Bahamon, Julio on 6/25/19.
//  UNC Charlotte
//  Copyright © 2019 Bahamon, Julio. All rights reserved.
//
//  DeCristo Franceschini

#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

//  Declaring a new struct to store patient data
struct patient {
    int age;
    char name[20];
    float balance;
};

// Displays the contents of the array
void displayPatientList(patient* patient_list, int total_patients) {
    for (int i = 0; i < total_patients; i++) {
        cout << "Patient " << i + 1 << ": "
             << "Name: " << patient_list[i].name << ", "
             << "Age: " << patient_list[i].age << ", "
             << "Balance: " << patient_list[i].balance << endl;
    }
}

//  TODO:
//  IMPLEMENT A FUNCTION THAT COMPARES TWO PATIENTS BY AGE

//  THE FUNCTION RETURNS AN INTEGER AS FOLLOWS:
//      -1 IF THE AGE OF THE FIRST PATIENT IS LESS
//         THAN THE SECOND PATIENT'S AGE
//       0 IF THE AGES ARE EQUAL
//       1 OTHERWISE
int comparePatientsByAge(const void* a, const void* b) {
    const patient* patientA = static_cast<const patient*>(a);
    const patient* patientB = static_cast<const patient*>(b);

    if (patientA->age < patientB->age) return -1;
    if (patientA->age == patientB->age) return 0;
    return 1;
}


//  TODO:
//  IMPLEMENT A FUNCTION THAT COMPARES TWO PATIENTS BY BALANCE DUE

//  THE FUNCTION RETURNS AN INTEGER AS FOLLOWS:
//      -1 IF THE BALANCE FOR THE FIRST PATIENT IS LESS
//         THAN THE SECOND PATIENT'S BALANCE
//       0 IF THE BALANCES ARE EQUAL
//       1 OTHERWISE
int comparePatientsByBalance(const void* a, const void* b) {
    const patient* patientA = static_cast<const patient*>(a);
    const patient* patientB = static_cast<const patient*>(b);

    if (patientA->balance < patientB->balance) return -1;
    if (patientA->balance == patientB->balance) return 0;
    return 1;
}

//  TODO:
//  IMPLEMENT A FUNCTION THAT COMPARES TWO PATIENTS BY NAME

//  THE FUNCTION RETURNS AN INTEGER AS FOLLOWS:
//      -1 IF THE NAME OF THE FIRST PATIENT GOES BEFORE
//         THE SECOND PATIENT'S NAME
//       0 IF THE AGES ARE EQUAL
//       1 OTHERWISE
//
//  HINT: USE THE strncmp FUNCTION
//  (SEE http://www.cplusplus.com/reference/cstring/strncmp/)
int comparePatientsByName(const void* a, const void* b) {
    const patient* patientA = static_cast<const patient*>(a);
    const patient* patientB = static_cast<const patient*>(b);
    
    return strncmp(patientA->name, patientB->name, 20);
}

//  The main program
int main()
{
    int total_patients = 6;
    char userName[20];
    int userAge, userBalance;

    cout << "Enter Last Name: ";
    cin >> userName;

    cout << "Enter Age: ";
    cin >> userAge;

    cout << "Enter Balance: ";
    cin >> userBalance; 

    //  Storing some test data
    struct patient patient_list[6] = {
        {25, "Juan Valdez   ", 1250},
        {15, "James Morris  ", 2100},
        {32, "Tyra Banks    ", 750},
        {62, "Mario O'Donell", 375},
        {53, "Pablo Picasso ", 615},
        {userAge,"",userBalance}
    };
    strcpy(patient_list[5].name, userName);
    
    cout << "Patient List: " << endl;
    
    //  TODO:
    //  IMPLEMENT THE CODE TO DISPLAY THE CONTENTS
    //  OF THE ARRAY BEFORE SORTING
    displayPatientList(patient_list, total_patients);
    
    
    cout << "Sorting..." << endl;
    
    //  TODO:
    //  CALL THE qsort FUNCTION TO SORT THE ARRAY BY PATIENT AGE
    
    qsort(patient_list, total_patients, sizeof(patient), comparePatientsByAge); 

    cout << "Patient List - Sorted by Age: " << endl;
    
    //  TODO:
    //  DISPLAY THE CONTENTS OF THE ARRAY
    //  AFTER SORTING BY AGE
    displayPatientList(patient_list, total_patients);

    cout << endl;
    
    
    cout << "Sorting..." << endl;
    
    //  TODO:
    //  CALL THE qsort FUNCTION TO SORT THE ARRAY BY PATIENT BALANCE
    
    qsort(patient_list, total_patients, sizeof(patient), comparePatientsByBalance); 

    cout << "Patient List - Sorted by Balance Due: " << endl;
    
    //  TODO:
    //  DISPLAY THE CONTENTS OF THE ARRAY
    //  AFTER SORTING BY BALANCE
    displayPatientList(patient_list, total_patients);

    cout << endl;
    
    
    cout << "Sorting..." << endl;
    
    //  TODO:
    //  CALL THE qsort FUNCTION TO SORT THE ARRAY BY PATIENT NAME
    
    qsort(patient_list, total_patients, sizeof(patient), comparePatientsByName);

    cout << "Patient List - Sorted by Name: " << endl;
    
    //  TODO:
    //  DISPLAY THE CONTENTS OF THE ARRAY
    //  AFTER SORTING BY NAME
    displayPatientList(patient_list, total_patients);

    cout << endl;
    
    return 0;
}
