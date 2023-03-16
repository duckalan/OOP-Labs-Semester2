#include <iostream>
using std::cout;

/*
Написать программу для определения в двухмерном массиве символов
самого длинного симметричного слова из английских букв.
*/

int main()
{
    setlocale(LC_ALL, "Russian");
        
    // Количество строк
    const int stringsCount = 2;
    // Количество символов в строке
    const int stringLength = 50;

    // Полная длина одномерного массива, содержащего
    // все строки без '\0' между ними
    const int fullLength = stringsCount * stringLength - (stringsCount - 1);

    // Исходный массив
    char strings[stringsCount][stringLength] = 
    {
        "abc dkkkkd nnnnn  nnnnnnn",
        "  aa     jjjjjjj jjj787jjj"
    };

    cout << "Исходный массив:\n";
    for (int i = 0; i < stringsCount; i++)
    {
        for (int j = 0; j < stringLength; j++)
        {
            cout << strings[i][j];
        }
    }

    // Одномерный массив, содержащий все строки 
    // без '\0' между ними
    char concatStrings[fullLength] = {};

    // Указатель на начало первой строки двумерного массива
    char* pString = &strings[0][0];

    // Заполнение одномерного массива
    for (int i = 0, j = 0; i < fullLength; i++)
    {
        if (pString[i] != '\0')
        {
            concatStrings[j] = pString[i];
            j++;
        }
    }

    // Максимальная длина симметричного слова
    int maxPalindromeLength = 0;

    // Индекс самого длинного симметричного слова в 
    // одномерном массиве
    int maxPalindromeIndex = 0;

    // Длина текущего слова 
    int wordLength = 0;

    // Цикл по всем словам
    // wordLength + 1 - это длина слова + пробел после него
    // Так мы будем сразу начинать со следующего слова
    for (int i = 0; i < fullLength; i += wordLength + 1)
    {
        wordLength = 0;
        int currentCharIndex = i;
        bool isEndOfWord = false;

        // Подсчёт длины слова
        while (!isEndOfWord)
        {
            if (concatStrings[currentCharIndex] != ' ' &&
                concatStrings[currentCharIndex] != '\0')
            {
                wordLength++;
            }
            else 
            {
                isEndOfWord = true;
            }
            currentCharIndex++;
        }

        // Проверка на симметричность
        bool isPalindrome = true;
        int temp = wordLength - 1;
        for (int j = i; j < i + (wordLength - 1) / 2; j++)
        {
            // j - индекс буквы, начиная с самой левой буквы
            // и до центральной. 
            // (i + temp--) - индекс буквы, начиная с самой
            // правой буквы и до центральной
            if (concatStrings[j] != concatStrings[i + temp--])
            {
                isPalindrome = false;
            }
        }

        // Определение максимальной длины и индекса слова
        if (isPalindrome && maxPalindromeLength < wordLength)
        {
            maxPalindromeLength = wordLength;
            maxPalindromeIndex = i;
        }
    }

    cout << "\nСамое длинное симметричное слово:\n";
    for (int i = maxPalindromeIndex; i < maxPalindromeIndex + maxPalindromeLength; i++)
    {
        cout << concatStrings[i];
    }

    cout << "\n";
    system("pause");
}