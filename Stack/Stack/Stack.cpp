#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string>


using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

// Определяем емкость stack по умолчанию
#define SIZE 10

template <typename T>
class Stack
{
    T* arr;
    int top;
    int capacity;

public:
    Stack(int); // конструктор
    ~Stack(); // деструктор

    void push(T); //добавление элемента в stack
    T pop(); //удаление последнего элемента из stack
    T peek(); //возвращает верхний элемент stack

    int size();
    bool isEmpty();
    bool isFull();
    void print();
};

template <typename T>
Stack<T>::Stack(int size)
{
    if (size != 0)
        arr = new T[size];
    else
        arr = 0;
    capacity = size;
    top = -1;
}

template <typename T>
Stack<T>::~Stack() {
    delete[] arr;
}

template <typename T>
void Stack<T>::push(T data) {
    if (isFull()) {
        cout << "Overflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }

    cout << "Добавлен элемент " << data << endl;
    arr[++top] = data;
}

template <typename T>
T Stack<T>::pop() {
    if (isEmpty()) {
        cout << "Underflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }

    cout << "Удаленный элемент " << peek() << endl;

    return arr[top--];
}

template <typename T>
T Stack<T>::peek() {
    if (!isEmpty()) {
        return arr[top];
    }
    else {
        exit(EXIT_FAILURE);
    }
}

template <typename T>
int Stack<T>::size() {
    return top + 1;
}

template <typename T>
bool Stack<T>::isEmpty() {
    return top == -1;              
}

template <typename T>
bool Stack<T>::isFull() {
    return top == capacity - 1;
}

template <typename T>
void Stack<T>::print() {
    cout << "Stack: ";
    
    if (!isFull()) {
        cout << "пустой((\n";
        return;
    }
    for (int i = 0; i < (top+1); i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    
    Stack<string> Stack(SIZE);

    string el;
    int index;
    while (true) {
        system("cls");

        cout << "Выберите действие, которое хотите совершить со списком\n\n";
        SetConsoleTextAttribute(hConsole, 11);
        cout << "<1> - Вернуть верхний элемент стека\n\n";
        cout << "<2> - Добавить элемент в конец\n\n";
        cout << "<3> - Удалить последний элемент\n\n";
        cout << "<4> - Вывести размер стека (кол-во элементов в нем)\n\n";
        cout << "<5> - Очистить стек\n\n";
        cout << "<6> - Вывод стека\n\n";
        SetConsoleTextAttribute(hConsole, 12);
        cout << "<0> - Выход из программы\n\n";
        SetConsoleTextAttribute(hConsole, 15);

        switch (_getch()) {
        case '0':
            return 0;

        case '1':
            cout << "Верхний элемент стека: ";
            cout << Stack.peek();
            cout << "\n\n";
            system("pause");
            break;

        case '2':
            cout << "Введите тот элемент, который хотите добавить: ";
            cin >> el;
            Stack.push(el);
            cout << "\n\n";
            system("pause");
            break;
                    
        case '3':
            Stack.pop();
            cout << "\n\n";
            system("pause");
            break;

        case '4':
            cout << Stack.size();
            cout << "\n\n";
            system("pause");
            break;
                    
        case '5':
            Stack.~Stack();
            cout << "\n\n";
            system("pause");
            break;

        case '6':
            Stack.print();
            cout << "\n\n";
            system("pause");
            break;

        default:
            continue;
            break;
        }
    }
}
