#include "fds132text.h"

fdsScreen::fdsScreen() {
    maxlength = 270;
    first = (fdsString*) calloc(1, sizeof(class fdsString));
}


fdsScreen::fdsScreen(char initialValue[], int position) {
    maxlength = 270;
    first = (fdsString*) malloc(sizeof(class fdsString));
    first -> startLocation = position;
    first -> firstNode = 0;
    first -> set(initialValue);
}


void fdsString::set(char value[]){
    if (firstNode == 0) {
        firstNode = (fdsStringNode*) malloc(sizeof(fdsStringNode));
        firstNode -> next = 0;
    }

    lastNode = firstNode -> set(value);

}

fdsStringNode* fdsStringNode::set(char *newValue){
    value = charTofdsChar(*newValue);

    if (*(newValue + sizeof(char))==0) {
        setEnd();
        return this;
    }
    if (next == 0){
        next = (fdsStringNode*) malloc(sizeof(fdsStringNode));
        next -> next = 0;
    }
    return next -> set(newValue + sizeof(char));
}

void fdsStringNode::setEnd(){

}

fdsChar fdsCharA;
fdsChar fdsCharB;
fdsChar fdsCharR;
fdsChar fdsCharColon;
fdsChar fdsCharSpace;

void initialiseLetters(){
    //include the seperating space
    fdsCharA.character_map[0]=B00000110;
    fdsCharA.character_map[1]=B00001001; 
    fdsCharA.character_map[2]=B00001001; 
    fdsCharA.character_map[3]=B00001111; 
    fdsCharA.character_map[4]=B00001001; 
    fdsCharA.character_map[5]=B00001001; 
    fdsCharA.character_map[6]=B00001001;
    fdsCharA.width=5;

    fdsCharB.character_map[0]=B00000111;
    fdsCharB.character_map[1]=B00001001; 
    fdsCharB.character_map[2]=B00001001; 
    fdsCharB.character_map[3]=B00000111; 
    fdsCharB.character_map[4]=B00001001; 
    fdsCharB.character_map[5]=B00001001; 
    fdsCharB.character_map[6]=B00000111;
    fdsCharB.width=5;

    fdsCharR.character_map[0]=B00000111;
    fdsCharR.character_map[1]=B00001001; 
    fdsCharR.character_map[2]=B00001001; 
    fdsCharR.character_map[3]=B00000111; 
    fdsCharR.character_map[4]=B00001001; 
    fdsCharR.character_map[5]=B00001001; 
    fdsCharR.character_map[6]=B00001001;
    fdsCharR.width=5;

    fdsCharColon.character_map[0]=B00000000;
    fdsCharColon.character_map[1]=B00000000;
    fdsCharColon.character_map[2]=B00000001;
    fdsCharColon.character_map[3]=B00000000;
    fdsCharColon.character_map[4]=B00000001;
    fdsCharColon.character_map[5]=B00000000;
    fdsCharColon.character_map[6]=B00000000;
    fdsCharColon.width=2;

    fdsCharSpace.width=2;
}

fdsChar* charTofdsChar(char value){
    switch (value){
        case 'a':
        case 'A':
            return &fdsCharA;
        case 'b':
        case 'B':
            return &fdsCharB;
        case 'r':
        case 'R':
            return &fdsCharR;
        case ':':
            return &fdsCharColon;
        case ' ':
            return &fdsCharSpace;
    }
}
