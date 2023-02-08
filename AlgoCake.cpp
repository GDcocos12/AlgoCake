#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
#include <bitset>
#include <sstream>
using namespace std;

void encrypt(string path, int key)
{
    try
    {
        cout << "The path of file : " << path << endl;
        cout << "Key for encryption : " << key << endl;

        ifstream fin(path, ios::binary);

        vector<char> image((istreambuf_iterator<char>(fin)), istreambuf_iterator<char>());
        fin.close();

        for (int i = 0; i < image.size(); i++)
        {
            image[i] = image[i] ^ key;
        }

        ofstream fout(path, ios::binary);
        fout.write(image.data(), image.size());
        fout.close();
        cout << "Encryption Done..." << endl;


    }
    catch (exception e)
    {
        cout << "Error caught : " << e.what() << endl;
    }
}

void decrypt(string path, int key)
{
    try
    {
        cout << "The path of file : " << path << endl;
        cout << "Note : Encryption key and Decryption key must be same." << endl;
        cout << "Key for Decryption : " << key << endl;

        ifstream fin(path, ios::binary);

        vector<char> image((istreambuf_iterator<char>(fin)), istreambuf_iterator<char>());
        fin.close();

        for (int i = 0; i < image.size(); i++)
        {
            image[i] = image[i] ^ key;
        }

        ofstream fout(path, ios::binary);

        fout.write(image.data(), image.size());
        fout.close();
        cout << "Decryption Done..." << endl;


    }
    catch (exception e)
    {
        cout << "Error caught : " << e.what() << endl;
    }
}

string decode_binary_string(string s)
{
    stringstream sstream(s);
    string output;
    while (sstream.good())
    {
        bitset<8> bits;
        sstream >> bits;
        char c = char(bits.to_ulong());
        output += c;
    }

    return output;
}

int main()
{
    string path;
    int key, action, mode;
    cout << "Welcome to AlgorythmicCake Encrypter/Decrypter v1.5!" << endl;
    cout << "Mode(1 - Image encrypter, 2 - Text to Binary): ";
    cin >> mode;
    if (mode == 1) {
        cout << " " << endl;
        cout << "Enter path of Image: ";
        cin >> path;
        cout << "Enter key: ";
        cin >> key;
        cout << "Action(1 - encrypt, 2 - decrypt): ";
        cin >> action;
        if (action == 1)
        {
            encrypt(path, key);
        }
        else if (action == 2)
        {
            decrypt(path, key);
        }
        else
        {
            cout << "Command not found.";
        }
    }
    else if (mode == 2) {
        int act;
        cout << "Action(1 - encrypt, 2 - decrypt):";
        cin >> act;
        if (act == 1) {
            string stri;
            cout << "Text: ";
            cin.ignore();
            getline(cin, stri);
            for (int i = 0; i < stri.length(); i++)
            {
                cout << bitset<8>(stri.c_str()[i]) << " ";
            }
            cout << endl;
        }
        else if (act == 2) {
            string bin;
            cout << "Binary: ";
            cin.ignore();
            getline(cin, bin);
            cout << decode_binary_string(bin) << endl;
        }
    }
    
    system("pause");
    return 0;
}
