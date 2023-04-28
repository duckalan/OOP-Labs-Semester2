#include <iostream>
#include <string.h>
#include "StackNode.h"
#include "Stack.h"

int ConvertSubstringToInt(const char* substring);

int ParseRpnString(const char* rpnString) 
{
    Stack operandStack;
    int currentIndex = 0;
    char currentChar = rpnString[0];
    int firstOperand;
    int secondOperand;

    while (currentChar != '\0')
    {
        switch (currentChar)
        {
        case '+':
            // Вынимаем два первых операнда из стека, 
            // добавляем в него результат операции
            secondOperand = operandStack.Pop();
            firstOperand = operandStack.Pop();
            operandStack.Push(firstOperand + secondOperand);
            break;
        case '-':
            secondOperand = operandStack.Pop();
            firstOperand = operandStack.Pop();
            operandStack.Push(firstOperand - secondOperand);
            break;
        case '*':
            secondOperand = operandStack.Pop();
            firstOperand = operandStack.Pop();
            operandStack.Push(firstOperand * secondOperand);
            break;
        case '/':
            secondOperand = operandStack.Pop();
            firstOperand = operandStack.Pop();
            operandStack.Push(firstOperand / secondOperand);
            break;
        default:
            // Если текущий символ - цифра, то добавляем 
            // полное число в стек
            if (isdigit(currentChar))
            {
                // rpnString + currentIndex - индекс начала числа в строке
                operandStack.Push(ConvertSubstringToInt(rpnString + currentIndex));
            }
            break;
        }

        currentIndex++;
        currentChar = rpnString[currentIndex];
    }

    // Возвращаем результат операций из стека
    return operandStack.Pop();
}

int main()
{
    setlocale(LC_ALL, "ru-RU");
    char rpnString[255];
    //std::cout << ParseRpnString("8 2 5 * + 1 3 2 * + 4 - /") << '\n';

    std::cout << "Введите строку в форме обратной польской записи\n";
    std::cin.getline(rpnString, 255);
    std::cout << "Результат вычислений: " << ParseRpnString(rpnString) << '\n';

    system("pause");
}

int ConvertSubstringToInt(const char* substring)
{
    int currentIndex = 0;
    char currentChar = substring[0];
    size_t numLength = 0;

    // Считаем длину числа, чтобы затем сразу скопировать его 
    // в строку и перевести в число
    while (isdigit(currentChar))
    {
        numLength++;
        currentIndex++;
        currentChar = substring[currentIndex];
    }

    // Длина числа + символ '\0'
    char* strNumber = new char[numLength + 1] {};

    // Копируем строковое представление числа в 
    // адрес strNumber
    memcpy(strNumber, substring, numLength);

    // Конвертируем его в число и возвращаем
    return atoi(strNumber);
}