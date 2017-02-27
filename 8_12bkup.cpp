#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;


string userInput = "yes";


// readData: passes in the name of a file and two vectors and stores in the first vector the flight-path angles (first column) and in the second vector the corresponding coefficients of lift (2nd column).
// interpolation: passes in the requested flight-path angle along with the 2 vectors of data (flight-path angles and corresponding coefficients of lift) and returns the corresponding coefficient of lift.
// isOrdered: passes in the vector of flight-path angles and returns true if it stores the angles are in ascending order, otherwise returns false.
// reorder: passes in both vectors of data and then reorders the data so that the flight-path angles are in ascending order while maintaining the correspondence between the flight-path angles and their corresponding coefficients of lift.

// Ask the user for the name of file that contains the wind tunnel data.
// Read wind-tunnel data into two parallel vectors, one vector stores the flight-path angle and the other stores the corresponding coefficient of lift for that angle.
// Ask the user for a flight-path angle. If the angle is within the bounds of the data set, the program should then use linear interpolation (see explanation of linear interpolation below) to compute the corresponding coefficient of lift and output it.
// Finally, ask the user if they want to enter another flight-path angle. Repeat steps 3 and 4 if they answer yes, otherwise end the program if they answer no.




double interpolation(double flightAngle, vector<double> flightPathAngles, vector<double> coefficientOfLift){
    int indexAboveClosest = 0;
    int indexBelowClosest = 0;
    
    for(unsigned int x = 0; x < flightPathAngles.size(); x++){
        if(flightPathAngles.at(x) == flightAngle){     // coefficient has already been calculated for given flight angle
            return coefficientOfLift.at(x);
        }
    }
    
    for(unsigned int x = 0; x < flightPathAngles.size(); x++){
        if(flightPathAngles.at(x) - flightAngle > 0){
            indexAboveClosest = x;
        }
    }
     for (unsigned int x = flightPathAngles.size() - 1; x > 0; x--){       //find the index above and below that is closest to the given flight angle.
         if(flightPathAngles.at(x) - flightAngle < 0){
             indexBelowClosest = x;
         }
     }
    
    //one above is c 
    //one below is a
    //f(b) = f(a) + (b - a)/(c - a)*(f(c) - f(a))                              
    double fa = coefficientOfLift.at(indexBelowClosest);
    double fb = 0.0;
    double fc = coefficientOfLift.at(indexAboveClosest);
    double a = flightPathAngles.at(indexBelowClosest);
    double b = flightAngle;
    double c = flightPathAngles.at(indexAboveClosest);
    
    fb = fa + (b - a)/(c - a)*(fc-fa);
    
    return fb;
    
}


void readData(string fileName, vector<double>& v1, vector<double>& v2){
    ifstream inFS;
    inFS.open(fileName.c_str());
    if(!inFS.is_open()){
        cout << "Error opening " << fileName << endl;
        userInput = "no";
        return;
    }
    while(!inFS.eof()){
        double temp = 0.0;
        inFS >> temp;
        v1.push_back(temp);
        
        inFS >> temp;
        v2.push_back(temp);
        inFS.ignore();
    }
    inFS.close();
}

bool isOrdered(const vector<double>& flightPathAngles){
    for(unsigned int x = 1; x < flightPathAngles.size(); x++){
        if(flightPathAngles.at(x) < flightPathAngles.at(x - 1)){
            return false;
        }
    }
    return true;
}
void swap(vector<double>& v1, vector<double>& v2){        //swaps element w/ next one given index and vector, does for both vectors.
    
    for(unsigned int x = 1; x < v1.size(); x++){
        if(v1.at(x) < v1.at(x - 1)){
            double temp = 0.0;
            double temp2 = 0.0;
            temp = v1.at(x - 1);
            temp2 = v2.at(x - 1);
            
            v1.at(x-1) = v1.at(x);
            v2.at(x - 1) = v2.at(x);
            
            v1.at(x ) = temp;
            v2.at(x ) = temp2;
        }
    }
}
void reorder(vector<double>& flightPathAngles, vector<double>& coefficientOfLift){
    while(!isOrdered(flightPathAngles)){
		swap(flightPathAngles, coefficientOfLift);
		//swaps both so they don't get out of order
	}
}



int main(){
    string nameOfFile = "";
    
    double col = 0.0;
    double angle = 0.0;
    vector<double> flightPathAngles;
    vector<double> coefficientOfLift;
    bool invalidInput = false;
    
    cout << "Enter name of input data file:" << endl << endl;
    cin >> nameOfFile;
    
    readData(nameOfFile, flightPathAngles, coefficientOfLift);
    
    cout << endl;
    
    for(unsigned int x = 0; x < flightPathAngles.size(); x++){
        cout << flightPathAngles.at(x) << " ";
    }
    cout << endl;
    for(unsigned int x = 0; x < flightPathAngles.size(); x++){
        cout << coefficientOfLift.at(x) << " ";
    }
    cout << endl;
    
    
      if(!isOrdered(flightPathAngles)){
          reorder(flightPathAngles, coefficientOfLift);
      }
    
    while(userInput == "yes"){   
        
        cout << "Please enter the flight-path angle." << endl;
    
        cin >> angle;
        
        if(angle < flightPathAngles.at(0) || angle > flightPathAngles.at(flightPathAngles.size() - 1)){
            cout << "Error: angle is too high or too low to calculate coefficient of lift." << endl;
            invalidInput = true;
            userInput = "no";
        }
        if(!invalidInput){
    
            col = interpolation(angle, flightPathAngles, coefficientOfLift);
    
            cout << "Coefficient of lift: " << col << endl;
    
            cout << "Do you want to enter another flight path angle?" << endl;
    
            cin >> userInput;
        }
    }

    
    
    
    
    return 0;
}