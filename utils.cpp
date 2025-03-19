#include "utils.h"

void formatReadmeTable(double** allTestsTimes, int numberOfRows, int numberOfColumns, int strategyNumber, string& containerType){
    ofstream fileStream("rezultatai.md", std::ios::app);

    fileStream << "## " << "Strategija" << " " << "#" << strategyNumber << endl << endl;
    fileStream << "# " << containerType << endl << endl;
    
    for(int i = 0; i < numberOfColumns+3; i++){
        fileStream << "|";
    }
    fileStream << endl;
    
    for(int i = 0; i < numberOfColumns+3; i++){
        if(i == numberOfColumns + 2) {
            fileStream << "|";
        }else{
            fileStream << "|-";
        }
    }
    fileStream << endl;

    // Writing the table headers
    fileStream << "|" << "Studentu kiekis" << "|"
               << "Skaitymas" << "|"
               << "Rikiavimas" << "|"
               << "Skirstymas" << "|"
               << endl;
    
    // writing the data to a file
    for(int i = 0; i < numberOfRows; i++){
        fileStream << "|" << getNumberOfStudents(i) << "|";
        for(int j = 0; j < numberOfColumns; j++){
            fileStream << allTestsTimes[i][j] << " " << "s" << "|";
        }
        fileStream << endl;
    }
    
    fileStream.close();
}

int getNumberOfStudents(int index){
    switch (index){
        case 0:
            return 1000;
        case 1:
            return 10000;
        case 2:
            return 100000;
        case 3:
            return 1000000;
        case 4:
            return 10000000;
    }
}