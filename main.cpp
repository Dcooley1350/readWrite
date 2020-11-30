#include <iostream>
#include <fstream>

#include "readWrite.hpp"
using namespace std;
int main() {
    int exitCode = 0;
    std::cout << "Initialized" << std::endl;
    //Open in stream
    ifstream infile(infileName);
    //if instream is functional, begin gathering from file
    if(infile.good()){
        char directive;
        bool reading = true;
        //Read loop until all input is gathered, or error state
        while(reading){
            infile >> directive;
            char symbol;
            int dimension;
            int dimension2;
            switch (directive) {
                case 'T':
                    infile >> symbol;
                    infile >> dimension;
                    drawTriangle(symbol, dimension);
                    break;
                case 'S':
                    infile >> symbol;
                    infile >> dimension;
                    drawSquare(symbol, dimension);
                    break;
                case 'R':
                    infile >> symbol;
                    infile >> dimension >> dimension2;
                    drawRectangle(symbol, dimension, dimension2);
                    break;
                case 'D':
                    infile >> symbol;
                    infile >> dimension;
                    drawDiamond(symbol, dimension);
                    break;
                case 'E':
                    std::cout << "End Code Encountered: exiting" << std::endl;
                    reading = false;
                    break;
                default:
                    //Notify user and exit on unexpected input
                    std::cout << "Unexpected character encountered" << std::endl;
                    reading = false;
            }
            //Notify user and exit on end of file
            if(infile.eof()){
                std::cout << "End of File encountered: exiting" << std::endl;
                reading = false;
            }
        }
        infile.close();
    }
    else {
        //Exit with error code if file could not be opened
        std::cout << "Error Opening File" << std::endl;
        exitCode = 1;
    }
    return exitCode;
}
