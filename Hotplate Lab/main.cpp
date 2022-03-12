#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int main() {

    //declarations used in program(8-15)
    const int NUM_ROWS = 10;
    const int NUM_COLS = 10;
    double temperature[NUM_ROWS][NUM_COLS];
    double currentTemperature[NUM_ROWS][NUM_COLS];
    double largestChange = 1000;
    double difference = 0.0;
    ofstream output;
    ifstream temperatureInput;

    // Step1: initialize all the temperatures.
    for(int i = 0; i < NUM_ROWS; i++){
        for( int j = 0; j < NUM_COLS; j++){
            if(i == 0 || i == NUM_ROWS - 1){
                if(j == 0 || j == NUM_COLS - 1){
                    temperature[i][j] = 0.00;
                    currentTemperature[i][j] = 0.00;
                }
                else{
                    temperature[i][j] = 100.00;
                    currentTemperature[i][j] = 100.00;
                }
            }
            else{
                temperature[i][j] = 0.00;
                currentTemperature[i][j] = 0.00;
            }
        }
    }

    cout << "Hotplate simulator" << endl << endl;
    cout << "Printing the initial plate values..." << endl;

    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            cout << setw(9);
            if(j == 9) {
                cout << fixed << setprecision(3) << temperature[i][j]; //changed from current temp to temp
                continue;
            }
            cout << fixed << setprecision(3) << temperature[i][j] << "," ;
        }
        cout << endl;
    }

    cout << endl << endl;

    //Step2: print Temperature after the first iteration.
    for(int i = 1; i < 9; i++) {
        for (int j = 1; j < 9; j++) {
            currentTemperature[i][j] = (temperature[i][j - 1] + temperature[i][j + 1] + temperature[i - 1][j] + temperature[i + 1][j]) / 4;
        }
    }

    cout << "Printing plate after one iteration..." << endl;

    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            cout << setw(9);
            if(j == 9) {
                cout << fixed << setprecision(3) << currentTemperature[i][j];
                continue;
            }
            cout << fixed << setprecision(3) << currentTemperature[i][j] << "," ;
        }
        cout << endl;
    }

    cout << endl << endl;

    // Step3: Update until steady state is achieved
    while(largestChange > 0.1) {

        largestChange = 0.0;

        // Calculate changes in temperature
        for(int i = 1; i < 9; i++) {
            for (int j = 1; j < 9; j++) {
                currentTemperature[i][j] = (temperature[i][j - 1] + temperature[i][j + 1] + temperature[i - 1][j] + temperature[i + 1][j]) / 4;
                difference = abs(currentTemperature[i][j] - temperature[i][j]);
                if(difference > largestChange) {
                    largestChange = difference;
                }
            }
        }

        // Find the largest change of temperature
        for(int i = 0; i < NUM_ROWS; i++) {
            for(int j = 0; j < NUM_COLS; j++) {
                temperature[i][j] = currentTemperature[i][j];
            }
        }
    }

    cout << "Printing final plate..." << endl;

    // Print the stable temperatures.
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            if(j == 9) {
                cout << fixed << setprecision(3) << setw(9) << currentTemperature[i][j];
                continue;
            }
            cout << fixed << setprecision(3) << setw(9) << currentTemperature[i][j] << "," ;
        }
        cout << endl;
    }

    // Create and open a text file "Hotplate.csv"
    output.open("Hotplate.csv");

    if (!output.is_open()) {    //sends error message if the file could not be opened
        cout << "Could not open file Hotplate.csv" << endl;
        return 1;
    }
    cout << endl;
    cout << "Writing final plate to \"Hotplate.csv\"..." << endl << endl;

    // Write to the file the value of the stable state
    for(int i = 0; i < 10; ++ i) {
        for (int j = 0; j < 10; ++j) {
            output << setw(9);
            if(j == 9) {
                output << fixed << setprecision(3) << currentTemperature[i][j];
                continue;
            }
            output << fixed << setprecision(3) << currentTemperature[i][j] << "," ;
        }
        output << endl;
    }

    // Closes the hotplate output file
    output.close();

    temperatureInput.open("Inputplate.txt"); // opens the input file

    if (!temperatureInput.is_open()) { //sends error message if the file could not be opened
        cout << "Could not open file Inputplate.txt" << endl;
        return 1;
    }

    for(int i = 0; i < 10; ++ i) {
        for (int j = 0; j < 10; ++j) {
            temperatureInput >> currentTemperature[i][j];
            temperature[i][j] = currentTemperature[i][j];
        }
    }

    temperatureInput.close(); // closes the input file

    for(int iteration = 1; iteration < 4; iteration ++) {
        for(int i = 0; i < NUM_ROWS; i++) {
            for(int j = 0; j < NUM_COLS; j++) {
                temperature[i][j] = currentTemperature[i][j];
            }
        }
        for(int i = 1; i < 9; i++) {
            for (int j = 1; j < 9; j++) {
                currentTemperature[i][j] = (temperature[i][j - 1] + temperature[i][j + 1] + temperature[i - 1][j] + temperature[i + 1][j]) / 4;
            }
        }
    }

    //Printing out input plate after 3 iterations
    cout << "Printing input plate after 3 updates..." << endl;

    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            if(j == 9) {
                cout << fixed << setprecision(3) << setw(9) << currentTemperature[i][j];
                continue;
            }
            cout << fixed << setprecision(3) << setw(9) << currentTemperature[i][j] << "," ;
        }
        cout << endl;
    }

    return 0;
}