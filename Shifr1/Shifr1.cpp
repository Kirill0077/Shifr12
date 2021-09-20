#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
using namespace std;

template <typename T>
T GetCorrectNumber(std::string text, T min, T max)
{
    T param;
    std::cout << text;
    while (!(std::cin >> param) || param < min || param > max)
    {
        std::cin.clear();
        std::cin.ignore(1000000, '\n');
        std::cout << text;
    }
    return param;
}

void increept(string &key,char* &fielname1, char* &fielname2)
{
    int length = key.length();
    std::ifstream fin;
    std::ofstream fout;
    fin.open(fielname1, std::ios::binary);
    fout.open(fielname2, std::ios::binary);
    if (fin.is_open() && fout.is_open())
    {
        int i = 0;
        unsigned char incr;
        while (fin >> std::noskipws >> incr)
        {
            fout << (unsigned char)((incr + (unsigned char)key[i]));
            if (++i == length) i = 0;
        };
    };
}

void descreept(string& key, char*& fielname1, char*& fielname2)
{
    int length = key.length();
    std::ifstream fin;
    std::ofstream fout;
    fin.open(fielname1, std::ios::binary);
    fout.open(fielname2, std::ios::binary);
    if (fin.is_open() && fout.is_open())
    {
        int i = 0;
        unsigned char incr;
        while (fin >> std::noskipws >> incr)
        {
            fout << (unsigned char)((incr - (unsigned char)key[i]));
            if (++i == length) i = 0;
        };
    };
}


void Menu()
{
    cout << "+++++++++++++++++++++++++++++++++++++++++++\n"
        << " 1. Шифрование             " << "\n"
        << " 2. Дешифровка             " << "\n"
        << " 3. Чистка консоли         " << "\n"
        << " 0. Выход                  " << "\n"
        << "+++++++++++++++++++++++++++++++++++++++++++" << endl;
}


int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "Russian");
    system("chcp 1251");
    string key = string(argv[4]);
    while (true)
    {
        Menu();
        int i = GetCorrectNumber("Выберите от 0 до 5: ", 0, 5);
        cout << '\n';
        switch (i)
        {
        case 1:
        {
            increept(key,argv[1], argv[2]);
            break;
        }
        case 2:
        {
            descreept(key, argv[2], argv[3]);
            break;
        }
        case 3:
        {
            system("cls");
            break;
        }
        case 0:
        {
            return 0;
            break;
        }
        default:
        {
            cout << "Ошибка: введите значение 0 до 5" << endl;
            break;
        }
        }
    }
    return 0;
}