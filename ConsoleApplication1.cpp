/*
�������� ���������� "�����". ���������� ������ ������������� ���������
����������������:
���������� ������ �� �����.
�������� ������ �� ������.
������ ������.

����� ������:
�� ��������.
�� �������������.
�� ����.
�� ������ ������ (��������, "����������� ����" ��� "��������").
�� ���� ����������� �� �����.
�� ����� ��������.

���������� ������:
�� ����.
�� ������ ������.
*/
#include <iostream>
#include "Header.h"// ����������� ������������� ����� "Header.h" ��� ������������� ���������������� ������� � �������
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    const char PATH[] = "data.txt";//������������� ���� � �����
    FILE* file;
    // int N = 255; 
    int choice; // ���������� ���������� 'choice' ��� �������� ������ ������������
    int howManyitems = 0; // ������������� ���������� 'howManyitems' ��� ������������ ���������� ���������, ������� � 0
    bool isTrue = true; // ������������� ���������� 'isTrue' ��� �������� ������ ����������� ��������� �� ������

    // ���� ������������ �� ��� ���, ���� ������������ �� ������ ��������� ���������� ���������
    while (howManyitems == 0) {
        if (!isTrue) {
            cout << "������, ���������� ��� ���" << endl; // ���� 'isTrue' �����, ��������� ��������� �� ������
            isTrue = true;
        }
        cout << "================================\n";
        cout << "������� ������� ��������� �����: ";
        cin >> howManyitems;
        isTrue = false;
    }
    Product* storage = new Product[howManyitems];
    cout << "\n================================\n";
    for (int i = 0; i < howManyitems; i++) {
        storage[i] = input();
        cout << "================================\n";
    }
    while (true)
    {
        cout << "\n================================\n";
        choice = Menu();
        cout << "\n================================\n";

        switch (choice) {
        case 0:
            delete[] storage; // ����������� ������ ����� �������
            return 0; // ��������� ��������� ���������

        case 1: {
            Product newElement = input();
            storage = add(storage, howManyitems, newElement);// ���������� ������ �������� � ������
            break;
        }
        case 2:
            for (int i = 0; i < howManyitems; i++) {
                cout << "\n====================\n";
                cout << "el: " << i << endl;
                Print(storage[i]);// ����� ���������� �� ��������
                cout << "\n====================\n";
            }
            break;
        case 3: {
            int whichItemDelete;
            cout << "����� ������� �� ������ �������: ";
            cin >> whichItemDelete;
            if (whichItemDelete >= 0 && whichItemDelete < howManyitems) {
                remove(storage, howManyitems, whichItemDelete);// �������� ��������, ���� ������ ���������
            }
            else {
                cout << "�������� ������\n";
            }
            break;
        }
        case 4: {
            int whichItemChange;
            cout << "����� ������� �� ������ ��������: ";
            cin >> whichItemChange;
            if (whichItemChange >= 0 && whichItemChange < howManyitems) {
                Product newElement = input();
                storage = change(storage, howManyitems, newElement, whichItemChange);// ������ �������� �� �����, ��������� �������������
            }
            else {
                cout << "�������� ������\n";
            }
            break;
        }

        case 5:
            char whichTitle[255];
            cout << "������� �������� ������: ";
            cin.ignore();
            cin.getline(whichTitle, 255);
            cout << "\n====================\n";
            searchOfTitle(storage, howManyitems, whichTitle);// ����� ������ �� ��������
            cout << "\n====================\n";
            break;
        case 6:
            char whichMaker[255];
            cout << "������� ������������� ������: ";
            cin.ignore();
            cin.getline(whichMaker, 255);
            cout << "\n====================\n";
            searchOfMaker(storage, howManyitems, whichMaker);// ����� ������ �� �������������
            cout << "\n====================\n";
            break;
        case 7:
            int whichPrice;
            cout << "������� ���� ������: ";
            cin >> whichPrice;
            cout << "\n====================\n";
            searchOfPrice(storage, howManyitems, whichPrice);// ����� ������ �� ����
            cout << "\n====================\n";
            break;
        case 8:
            char whichProductClass[255];
            cout << "������� ������������� ������: ";
            cin.ignore();
            cin.getline(whichProductClass, 255);
            cout << "\n====================\n";
            searchOfProductClass(storage, howManyitems, whichProductClass);// ����� ������ �� ������
            cout << "\n====================\n";
            break;
        case 9: {
            int whichDay1, whichMonth1, whichYear1;
            cout << "������� ���� ����������� �� ����� (�� �� ����): ";
            cin >> whichDay1 >> whichMonth1 >> whichYear1;
            searchOfdate(storage, howManyitems, whichDay1, whichMonth1, whichYear1);// ����� ������ �� ���� �����������
            break;
        }
        case 10: {
            int whichDay2, whichMonth2, whichYear2;
            cout << "������� ���� ����� �������� (�� �� ����): ";
            cin >> whichDay2 >> whichMonth2 >> whichYear2;
            searchOfdate(storage, howManyitems, whichDay2, whichMonth2, whichYear2);// ����� ������ �� ����� ��������
            break;
        }

        case 11:
            storage = sortingOfPrice(storage, howManyitems);// ���������� ������� �� ����
            break;
        case 12:
            storage = sortingOfproduct_class(storage, howManyitems);// ���������� ������� �� ������
            break;


        }
    }
}
