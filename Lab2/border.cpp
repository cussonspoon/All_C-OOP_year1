#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
    cout << "Please enter P1 name: ";
    string name;
    std::cin >> name;

    cout << "Please enter P2 name: ";
    string name2;
    std::cin >> name2;

    const string greeting = "Player 1: " + name;
    const string greeting2 = "Player 2: " + name2;


    int pad = 1;
    int rows = pad * 2 + 3;
    string::size_type cols = greeting.size() + pad * 2 + 2 + greeting2.size() + pad * 2 + 2;


    cout << endl;

    for (int r = 0; r != rows; ++r) {
        string::size_type c = 0;
        while (c != cols - 1) {
            if (r == pad + 1 && c == pad + 1) {
                cout << greeting;
                c += greeting.size();
            }else if(c == greeting.size() + pad + 4  && r == 2){
                cout << greeting2;
                c += greeting2.size();
            
                
            } else {
                if (r == 0 || r == rows - 1 || c == 0 || c == cols - 2 || c == greeting.size() + pad * 2 + 1) {
                    cout << "*";
                } else {
                    cout << " ";
                }
                ++c;
            }
        }
        cout << endl;
    }

    rows = 9;
    if (greeting2.length() > greeting.length()) {
        cols = greeting2.size() + pad * 2 + 2;
    } else {
        cols = greeting.size() + pad * 2 + 2;
    }

    cout << endl;

    for (int r = 0; r != rows; ++r) {
        string::size_type c = 0;
        while (c != cols) {
            if (r == pad + 1 && c == pad + 1) {
                cout << greeting;
                c += greeting.size();
            }else if (r == 6 && c == pad + 1) {
                cout << greeting2;
                c += greeting2.size();
            } else {
                if((r == 0 || r == 4 || r == 8) && (c == 0|| c == cols - 1)){
                    cout << "*";
                }else if((r != 0 || r!= 4 || r != 8) && (c == 0|| c == cols - 1)){
                    cout << "*";
                }else if (r == 4){
                    cout << "*";
                }
                else if(r == 0 || r == rows - 1 || c == 0 || c == cols - 1) {
                    cout << "*";
                } else {
                    cout << " ";
                }
                ++c;
            }
        }
        cout << endl;
    }

    for (int r = 0; r != rows; ++r) {
        string::size_type c = 0;
        while (c != cols) {
            if (r == pad + 1 && c == pad + 1) {
                cout << greeting;
                c += greeting.size();
            }else if (r == 6 && c == pad + 1) {
                cout << greeting2;
                c += greeting2.size();
            } else {
                if((r == 0 || r == 4 || r == 8) && (c == 0|| c == cols - 1)){
                    cout << "+";
                }else if((r != 0 || r!= 4 || r != 8) && (c == 0|| c == cols - 1)){
                    cout << "|";
                }else if (r == 4){
                    cout << "-";
                }
                else if(r == 0 || r == rows - 1 || c == 0 || c == cols - 1) {
                    cout << "-";
                } else {
                    cout << " ";
                }
                ++c;
            }
        }
        cout << endl;
    }

  
    for (int r = 0; r != rows; ++r) {
        string::size_type c = 0;
        while (c != cols) {
            if (r == pad + 1 && c == pad + 1) {
                cout << greeting;
                c += greeting.size();
            }else if (r == 6 && c == pad + 1) {
                cout << greeting2;
                c += greeting2.size();
            } else {
                if((r == 0 || r == 4 || r == 8) && (c == 0|| c == cols - 1)){
                    cout << "+";
                }else if((r != 0 || r!= 4 || r != 8) && (c == 0|| c == cols - 1)){
                    cout << "|";
                }else if (r == 4){
                    cout << "-";
                }
                else if(r == 0 || r == rows - 1 || c == 0 || c == cols - 1) {
                    cout << "=";
                } else {
                    cout << " ";
                }
                ++c;
            }
        }
        cout << endl;
    }

    return 0;
}
