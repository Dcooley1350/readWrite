#include <iostream>
#include <fstream>
#include "readWrite.hpp"

void drawDiamond(char character, int dimension) {
    int i,j;
    std::fstream appendfile(outfile, std::ios::app);
    //If even number, add 1 row
    if(dimension%2 == 0 ){
        dimension++;
    }
    //Draw top half of diamond
    for(i = 0; i <= dimension/2+1; i++){
        for(j = 1; j <= dimension/2+1-i; j++) {
            appendfile << " ";
        }
        for(j = 1; j <= 2*i-1; j++) {
            appendfile << character;
        }
        appendfile << std::endl;
    }
    //Draw bottom half of diamond
    for(i = dimension/2;i >= 1; i--){
        for(j = 1; j <= dimension/2+1-i; j++) {
            appendfile << " ";
        }
        for(j = 1;j <= 2*i-1; j++) {
            appendfile << character;
        }
            appendfile << std::endl;;
    }
    appendfile.close();
}

void drawRectangle(char character, int height, int width) {
    //Draw rectangle
    std::fstream appendfile(outfile, std::ios::app);
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++) {
            appendfile << character;
        }
        appendfile << std::endl;
    }
    appendfile.close();
}

void drawTriangle(char character, int dimension) {
    //Draw triangle
    std::fstream appendfile(outfile, std::ios::app);
    for(int i = 0; i <= dimension; i++){
        for(int j = 0; j < i; j++) {
            appendfile << character;
        }
        appendfile << std::endl;
    }
    appendfile.close();
}

void drawSquare(char character, int dimension) {
    //Draw square
    std::fstream appendfile(outfile, std::ios::app);
    for(int i = 0; i < dimension; i++){
        for(int j = 0; j < dimension; j++) {
            appendfile << character;
        }
        appendfile << std::endl;
    }
    appendfile.close();
}

