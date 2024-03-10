#include <iostream>
#include <string>
#include <limits>
#include <cctype>

using namespace std;

int main() {
     string choice ;
     
     cout << "==========================  Welcome to this Route cipher program  =========================="<<endl ;
     cout <<  "A) Encipher" <<endl ;
     cout <<  "B) Decipher" <<endl ;
     cout << "please choose avalid  what you want: " <<endl;
     getline(cin,choice)  ;
     
    while (true) {

        if (choice != "A" && choice != "a" && choice != "B" && choice != "b" ){

        cin.clear();
        cin. ignore();
        cout << "Invalid input.\n Please enter a valid choice: ";
        cin >> choice  ;

                }
          else{
            break;
          }
         }

     if (choice == "A" || choice == "a" ){   
        string message ,  message_t;
        int row, column, top, bottom, right, left;
    
    cout << "Please enter your message: " ;
    getline(cin, message);

    cout << "Please enter your secret key: ";
    cin >> column;

    while (true) {
        if (cin.fail() || column <= 0 || column > (message.size() / 2)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input.\n Please enter a valid positive integer: ";
            cin >> column;
        } else {
            break;
        }
    }
    
    // Convert characters to uppercase
    for (char &i : message) {
        if (isalpha(i)) {
            message_t += toupper(i);
        }
       
    }

    // Calculate the number of rows
    if (message_t.length() % column == 0) {
        row = message_t.length() / column;
    } 
    else {
        row = (message_t.length() / column) + 1;
     }
    // Allocate the array dynamically
    char** messages = new char*[row];
    for (int i = 0; i < row; ++i) {
        messages[i] = new char[column];
    }

    // Fill in matrix
    int index = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (index < message_t.length()) {
                messages[i][j] = message_t[index++];
            } else {
                messages[i][j] = 'X'; // Padding with 'X' if the message doesn't fill the entire array
            }
        }
    }
    
    // Initialize indices
    top = 0;
    bottom = row - 1;
    right = column - 1;
    left = 0;

    // Printing the encrypted message
    cout << "Encrypted message is :  ";
      while (true) {
        if (left > right || top > bottom) {
            break;
        }

        // Print from top to bottom
        for (int i = top; i <= bottom; i++) {
            cout << messages[i][right];
        }
        right--;

        // Check if left is greater than right before proceeding
        if (left > right) {
            break;
        }

        // Print from right to left
        for (int i = right; i >= left; i--) {
            cout << messages[bottom][i];
        }
        bottom--;

        // Check if bottom is greater than top before proceeding
        if (bottom < top) {
            break;
        }

        // Print from bottom to top
        for (int i = bottom; i >= top; i--) {
            cout << messages[i][left];
        }
        left ++;

        // Check if right is less than left before proceeding
        if (right < left) {
            break;
        }

        // Print from right to left
        for (int i = left; i <= right; i++) {
            cout << messages[top][i];
        }
        top ++;
    }
     }
    if (choice == "B" || choice == "b"){

          string message, message_T , decipher_message ;
    int row, column, top, bottom, right, left;
    
    cout << "Please enter your encrypted message: ";
    getline(cin, message);

    cout << "Please enter your secret key: ";
    cin >> column;

    while (true) {
        if (cin.fail() || column <= 0 || column > (message.size() / 2)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input.\n Please enter a valid positive integer to decipher your message:  ";
            cin >> column;
        } else {
            break;
        }
    }
     for (int i = 0 ; i < message.size() ; i++)
        if (isalpha(message[i])){
            message_T += toupper(message[i]);
        }
    // Calculate the number of rows
    if (message_T.length() % column == 0) {
        row = message_T.length() / column;
    } 
    else {
        row = (message_T.length() / column) + 1;
    }
    
    // Allocate the array dynamically
    char** messages = new char*[row];
    for (int i = 0; i < row; ++i) {
        messages[i] = new char[column];
    }

    // Initialize indices
    top = 0;
    bottom = row - 1;
    right = column - 1;
    left = 0;

    // Initialize index for traversing the encrypted message
    int index = 0;

    // Decipher the message and fill in the array
    while (true) {
        if (left > right || top > bottom) {
            break;
        }

        // Fill from top to bottom
        for (int i = top; i <= bottom; i++) {
            messages[i][right] = message_T[index++];
        }
        right--;

        // Check if left is greater than right before proceeding
        if (left > right) {
            break;
        }

        // Fill from right to left
        for (int i = right; i >= left; i--) {
            messages[bottom][i] = message_T[index++];
        }
        bottom--;

        // Check if bottom is greater than top before proceeding
        if (bottom < top) {
            break;
        }

        // Fill from bottom to top
        for (int i = bottom; i >= top; i--) {
            messages[i][left] = message_T[index++];
        }
        left++;

        // Check if right is less than left before proceeding
        if (right < left) {
            break;
        }

        // Fill from left to right
        for (int i = left; i <= right; i++) {
            messages[top][i] = message_T[index++];
        }
        top++;
    }

    // Print the deciphered message
    cout << "Deciphered message is: ";
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            decipher_message += messages[i][j];
        }
    }

    return 0 ;
}