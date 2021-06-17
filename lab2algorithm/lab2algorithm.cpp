//key scheduling algorithm in C++ to understand lab 2

#include <iostream>
#include <string>
#include <array>
using namespace std;

int main() {
    
    int s [255];
    int key [3];
    int i = 0, j = 0, k = 0, n = 0;
    int message_length;
    int ciphertext [6] = {6,3,5,'F',3,'C'}; 
    int plaintext [6];
    int pad[6];

    // key-scheduling algorithm: initialize the s array

    for (i = 0; i < 255; i++)
        s[i] = i;

    j = 0;
    
    for (i = 0; i < 255; i++)
        j = (j + s[i] + key[i % sizeof(key)]) % 256; // for us, keylength is 3
        s[i] = s[j];    


    // pseudo-random generation algorithm: generate byte stream (“pad”)
    // to be xor'd with the ciphertext

    i = 0, j = 0;
    message_length = ciphertext[0];
    for (k = 1; k < message_length; k++) {
        i = (i+1) % 256;
        j = (j+s[i]) % 256;
        s[i] = s[j];
        pad[k] = s[(s[i]+s[j]) % 256];
        cout << pad[k];
    }

   cout << endl; 
  
    // ciphertext xor pad --> plaintext

    plaintext[0] = message_length;
    for (n = 1; n < message_length; n++){
        plaintext[n] = pad[n] ^ ciphertext[n];
        cout << plaintext [n];
    }

    cout << endl;

return 0;

}

