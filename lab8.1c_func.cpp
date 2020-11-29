// Дано літерний рядок, який містить послідовність символів s[0], ..., s[n], ...  
// 1.   Вияснити, чи є серед цих символів пара сусідні букв "aa" або "bb" або "cc".  
// 2.   Замінити кожну пару сусідніх букв "aa" або "bb" або "cc" трійкою зірочок "***". 
//      Lab 8.1 (3)

#define _CRT_SECURE_NO_WARNINGS 
#include <iostream> 

using namespace std;
bool Find(char* str) {
    char* strTail = str;
    while (true) {
        size_t pos = strcspn(strTail, "abc");
        char c = strTail[pos];
        if (c == 0) return false;
        strTail += pos;
        if (strncmp(strTail, "aa", 2) == 0 || strncmp(strTail, "bb", 2) == 0 || strncmp(strTail, "cc", 2) == 0) {
            return true;
        }
        else {
            strTail++;
        }
    }
}

void Process(char* str, char* newStr) {
    char* strTail = str;
    char* newStrTail = newStr;
    while (true) {
        // визначає та повертає довжину поч.сегменту рядка strTail, що містить лише ті символи, які не входять у рядок "abc"
        size_t pos = strcspn(strTail, "abc");
        // копіює pos символів
        strncpy_s(newStrTail, pos+1, strTail, pos);
        // c - символ у позиції, де функція пошуку знайшла 'a', 'b', 'c' або 0
        char c = strTail[pos];                      
        if (c == 0) break;
        // переміщує вказівники на pos символів
        newStrTail += pos;
        strTail += pos;
        // перевіряє, чи є подвоєні символи "aa", "bb" або "cc"
        if (strncmp(strTail, "aa", 2) == 0 || strncmp(strTail, "bb", 2) == 0 || strncmp(strTail, "cc", 2) == 0) {
            strncpy_s(newStrTail, 4, "***", 3);
            newStrTail += 3;
            strTail += 2;
        }
        else {
            strncpy_s(newStrTail++, 2, strTail++, 1);
        }
    }
    return;
}

int main() {
    char str[101];
    char newStr[151] = "";

    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    bool changed = Find(str);
    Process(str, newStr);

    cout << "String: " << str << endl << endl;
    if (changed) {
        cout << "String was modified." << endl;
        cout << "Modified string (result): " << newStr << endl;
    }
    else {
        cout << "String was not modified." << endl;
    }

    return 0;
}
