#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
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

int main()
{
    string path;
    int key, action;
    cout << "Welcome to AlgorythmicCake Encrypter/Decrypter v1.0!" << endl;
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
    system("pause");
    return 0;
}