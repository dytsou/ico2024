#include<iostream>
#include<string>
using namespace std;


int main(){
    string hex, mips;
    cin >> hex;
    for(int i = 0; i < hex.size(); i++){
        switch(hex[i]){
            case '0': mips += "0000"; break;
            case '1': mips += "0001"; break;
            case '2': mips += "0010"; break;
            case '3': mips += "0011"; break;
            case '4': mips += "0100"; break;
            case '5': mips += "0101"; break;
            case '6': mips += "0110"; break;
            case '7': mips += "0111"; break;
            case '8': mips += "1000"; break;
            case '9': mips += "1001"; break;
            case 'A': mips += "1010"; break;
            case 'B': mips += "1011"; break;
            case 'C': mips += "1100"; break;
            case 'D': mips += "1101"; break;
            case 'E': mips += "1110"; break;
            case 'F': mips += "1111"; break;
            case 'a': mips += "1010"; break;
            case 'b': mips += "1011"; break;
            case 'c': mips += "1100"; break;
            case 'd': mips += "1101"; break;
            case 'e': mips += "1110"; break;
            case 'f': mips += "1111"; break;
        }
    }
    for(int i = 0; i < mips.size(); i++){
        if(i == 6 || i == 11 || i == 16 || i == 21 || i == 26) cout << " ";
        cout << mips[i];
    }
    cout << endl;
    string opcode = mips.substr(0, 6);
    int op = stoi(opcode, 0, 2);
    string func = mips.substr(26, 6);
    int funct = stoi(func, 0, 2);
    switch(op){
        case 0:
            switch(funct){
                case 32:
                    cout << "add" << endl; break;
                case 33:
                    cout << "addu" << endl; break;
                case 34:
                    cout << "sub" << endl; break;
                case 35:
                    cout << "subu" << endl; break;
                case 36:
                    cout << "and" << endl; break;
                case 37:
                    cout << "or" << endl; break;
                case 38:
                    cout << "xor" << endl; break;
                case 39:
                    cout << "nor" << endl; break;
                case 42:
                    cout << "slt" << endl; break;
                case 43:
                    cout << "sltu" << endl; break;
            }
        case 2: 
            cout << "j" << endl; break;
        case 3: 
            cout << "jal" << endl; break;
        case 4: 
            cout << "beq" << endl; break;
        case 5:
            cout << "bne" << endl; break;
        case 8:
            cout << "addi" << endl; break;
        case 9:
            cout << "addiu" << endl; break;
        case 10:
            cout << "slti" << endl; break;
        case 11:
            cout << "sltiu" << endl; break;
        case 12:
            cout << "andi" << endl; break;
        case 13:
            cout << "ori" << endl; break;
        case 14:
            cout << "xori" << endl; break;
        case 15:
            cout << "lui" << endl; break;
        case 35:
            cout << "lw" << endl; break;
        case 43:
            cout << "sw" << endl; break;
    }
}