#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>

using namespace std;
int hexadecimalToDecimal(char hexVal[]);
int main() {
    string s;
    cin >> s;
    char char_array[s.length() + 1];

    // copying the contents of the
    // string to char array
    strcpy(char_array, s.c_str());
    cout << hexadecimalToDecimal(char_array) % 2 << endl;
    return 0;
}

int hexadecimalToDecimal(char hexVal[])
{
    int len = strlen(hexVal);

    // Initializing base value to 1, i.e 16^0
    int base = 1;

    int dec_val = 0;

    // Extracting characters as digits from last character
    for (int i=len-1; i>=0; i--)
    {
        // if character lies in '0'-'9', converting
        // it to integral 0-9 by subtracting 48 from
        // ASCII value.
        if (hexVal[i]>='0' && hexVal[i]<='9')
        {
            dec_val += (hexVal[i] - 48)*base;

            // incrementing base by power
            base = base * 16;
        }

            // if character lies in 'A'-'F' , converting
            // it to integral 10 - 15 by subtracting 55
            // from ASCII value
        else if (hexVal[i]>='A' && hexVal[i]<='F')
        {
            dec_val += (hexVal[i] - 55)*base;

            // incrementing base by power
            base = base*16;
        }
    }

    return dec_val;
}