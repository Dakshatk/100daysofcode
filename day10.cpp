#include <iostream>
#include <string>

using namespace std;

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        string date;
        cin >> date;
        
        int day = stoi(date.substr(0, 2));
        string month = date.substr(2, 3);
        
        int dayOfYear = 0;
        
        // Sum days based on the month
        if (month == "JAN") dayOfYear = day;
        else if (month == "FEB") dayOfYear = 31 + day;
        else if (month == "MAR") dayOfYear = 59 + day;
        else if (month == "APR") dayOfYear = 90 + day;
        else if (month == "MAY") dayOfYear = 120 + day;
        else if (month == "JUN") dayOfYear = 151 + day;
        else if (month == "JUL") dayOfYear = 181 + day;
        else if (month == "AUG") dayOfYear = 212 + day;
        else if (month == "SEP") dayOfYear = 243 + day;
        else if (month == "OCT") dayOfYear = 273 + day;
        else if (month == "NOV") dayOfYear = 304 + day;
        else if (month == "DEC") dayOfYear = 334 + day;

        cout << dayOfYear << endl;
    }
    
    return 0;
}
