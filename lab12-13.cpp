// Створити лінійний односпрямований список із цілих чисел. Видалити зі списку перший парний елемент, який знаходиться на непарній позиції
//

#include <iostream>
#include <forward_list>
#include <windows.h>


using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    forward_list<int> numberList = { 1, 4, 5, 8, 10, 12 };

    cout << "Список до видалення: ";
    for (int number : numberList) {
        cout << number << " ";
    }
    cout << endl;

    auto prev = numberList.before_begin(); 
    auto current = numberList.begin();     
    int position = 1;

    while (current != numberList.end()) {
        if (position % 2 != 0 && *current % 2 == 0) {  
            numberList.erase_after(prev);  
            break; 
        }
        prev = current;
        ++current;
        ++position;
    }

    cout << "Список після видалення: ";
    for (int number : numberList) {
        cout << number << " ";
    }
    cout << endl;

    return 0;
}
