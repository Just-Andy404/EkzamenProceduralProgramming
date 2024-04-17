#pragma once
#include <iostream>
#include <cstring> // for strcpy
using namespace std;



struct Date {
    int year;
    int month;
    int day;
};

struct Product {
    char title[255];
    char maker[255];
    double price;
    char product_class[255];
    Date arrival_date_in_stock; // ���� ����������� �� �����
    Date shelf_life; // ���� ��������
};


// ���������� ������ �� �����.
Product input() {
    Product aProduct; // �������� ������ ������� ��������� Product
    int day, month, year;
    cin.ignore();
    cout << "������� ��������: ";
    cin.getline(aProduct.title, 255);
    cout << "������� �������������: ";
    cin.getline(aProduct.maker, 255);
    cout << "������� ����: ";
    cin >> aProduct.price;
    cin.ignore();
    cout << "������� ����� ��������: ";
    cin.getline(aProduct.product_class, 255);
    cout << "������� ���� ����������� �� ����� (�� �� ����): ";
    cin >> day >> month >> year;
    aProduct.arrival_date_in_stock = { day, month, year };
    cout << "������� ���� ��������� ����� ��������: ";
    cin >> day >> month >> year;
    aProduct.shelf_life = { day, month, year };

    return aProduct;
}

//����
int Menu() {
    int choice;
    cout << "1)���������� ������ �� �����\n"
        << "2)������ ���� ����\n"
        << "3)�������� ������ �� ������\n"
        << "4)������ ������\n"
        << "5)����� ������ �� ��������\n"
        << "6)����� ������ �� �������������\n"
        << "7)����� ������ �� ����\n"
        << "8)����� ������ �� ������ ������\n"
        << "9)����� ������ �� ���� ����������� �� �����\n"
        << "10)����� ������ �� ����� ��������\n"
        << "11)���������� ������ �� ����\n"
        << "12)��������� � ������ �� ������ ������\n"
        << "0)exit\n"
        << "Choice what do you need: \n";
    cin >> choice;
    return choice;
}


// ����� ������ �� ������
void Print(Product aProduct) {
    cout << "��������: " << aProduct.title << endl;
    cout << "�������������: " << aProduct.maker << endl;
    cout << "����: " << aProduct.price << endl;
    cout << "����� ��������: " << aProduct.product_class << endl;
    cout << "���� ����������� �� �����: " << aProduct.arrival_date_in_stock.day << "." <<
        aProduct.arrival_date_in_stock.month << "." << aProduct.arrival_date_in_stock.year << endl;
    cout << "���� �� ����� ��������: " << aProduct.shelf_life.day << "." <<
        aProduct.shelf_life.month << "." << aProduct.shelf_life.year << endl;
}

Product* add(Product*& array, int& size, Product newElement) {
    Product* newArray = new Product[size + 1];

    for (int i = 0; i < size; ++i) {
        newArray[i] = array[i];
    }

    newArray[size] = newElement;

    delete[] array;

    ++size;

    return newArray;
}

// �������� ������ �� ������
void remove(Product aProduct[], int& size, int indexToDelete) {
    if (indexToDelete < 0 || indexToDelete >= size) {
        std::cerr << "�������� ������" << std::endl;
        return;
    }

    // ������� ����� ������ �������� �������
    Product* newProducts = new Product[size - 1];

    // �������� �������� � ����� ������, ��������� ��������� �������
    for (int i = 0, j = 0; i < size; ++i) {
        if (i != indexToDelete) {
            newProducts[j++] = aProduct[i];
        }
    }

    // ����������� ������ ������
    delete[] aProduct;

    // ��������� ��������� �� ����� ������
    aProduct = newProducts;

    // ��������� ������ �������
    size--;

}

Product* change(Product*& array, int& size, Product newElement, int& whichItemChange) {
    // ������� ����� ������ 
    Product* newArray = new Product[size];

    // �������� ������������ �������� � ����� ������
    for (int i = 0; i < size; ++i) {
        newArray[i] = array[i];
    }

    // ��������� ����� �������
    newArray[whichItemChange] = newElement;

    // ������� ������ ������
    delete[] array;

    return newArray;
}

// ����� ������: �� ��������
void searchOfTitle(Product aProduct[], int size, const char* whichTitle) {
    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (strcmp(aProduct[i].title, whichTitle) == 0) {
            Print(aProduct[i]);
            found = true;
        }
    }
    if (!found) {
        cout << "����� �� �������� �� �������: " << whichTitle << endl;
    }
}

//����� ������: �� �������������
void searchOfMaker(Product aProduct[], int size, const char* whichMaker) {
    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (strcmp(aProduct[i].maker, whichMaker) == 0) {
            Print(aProduct[i]);
            found = true;
        }
    }
    if (!found) {
        cout << "����� �� ������������� �� �������: " << whichMaker << endl;
    }
}

//����� ������: �� ����
void searchOfPrice(Product aProduct[], int size, int whichPrice) {
    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (aProduct[i].price == whichPrice) {
            Print(aProduct[i]);
            found = true;
        }
    }
    if (!found) {
        cout << "����� �� ���� �� �������: " << whichPrice << endl;
    }
}

//����� ������: �� ������ ������
void searchOfProductClass(Product aProduct[], int size, const char* whichProductClass) {
    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (strcmp(aProduct[i].product_class, whichProductClass) == 0) {
            Print(aProduct[i]);
            found = true;
        }
    }
    if (!found) {
        cout << " ����� ������ �� �������: " << whichProductClass << endl;
    }
}

//����� ������: �� ���� �����������
void searchOfdate(Product aProduct[], int size, int whichDay, int whichMonth, int whichYear) {
    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (aProduct[i].arrival_date_in_stock.day == whichDay) {
            if (aProduct[i].arrival_date_in_stock.month == whichMonth) {
                if (aProduct[i].arrival_date_in_stock.year == whichYear) {
                    Print(aProduct[i]);
                    found = true;
                }
            }
        }
    }
    if (!found) {
        cout << "����� �� ���� �� �������: " << whichDay << "." << whichMonth << "." << whichYear << endl;
    }
}

//���������� ������:�� ����
Product* sortingOfPrice(Product aProduct[], int ROWS) {
    for (int i = 0; i < ROWS - 1; i++) {
        if (aProduct[i].price < aProduct[i + 1].price) {
            Product temp = aProduct[i];
            aProduct[i] = aProduct[i + 1];
            aProduct[i + 1] = temp;
        }
    }
    return aProduct;
}

//���������� ������:�� ������ ������
Product* sortingOfproduct_class(Product* aProduct, int ROWS) {
    bool swapped = true;
    while (swapped) {
        swapped = false;
        for (int i = 0; i < ROWS - 1; i++) {
            // ���������, ����� �� ������ ������� �������� ��������
            if (strcmp(aProduct[i].product_class, aProduct[i + 1].product_class) > 0) {
                // ������ �������
                Product temp = aProduct[i];
                aProduct[i] = aProduct[i + 1];
                aProduct[i + 1] = temp;
                swapped = true;
            }
        }
    }
    return aProduct;
}
