#include <iostream>
using std::cout;

/*
�������� ��������� ��� ����������� � ���������� ������� ��������
������ �������� ������������� ����� �� ���������� ����.
*/

int main()
{
    setlocale(LC_ALL, "Russian");
        
    // ���������� �����
    const int stringsCount = 2;
    // ���������� �������� � ������
    const int stringLength = 50;

    // ������ ����� ����������� �������, �����������
    // ��� ������ ��� '\0' ����� ����
    const int fullLength = stringsCount * stringLength - (stringsCount - 1);

    // �������� ������
    char strings[stringsCount][stringLength] = 
    {
        "abc dkkkkd nnnnn  nnnnnnn",
        "  aa     jjjjjjj jjj787jjj"
    };

    cout << "�������� ������:\n";
    for (int i = 0; i < stringsCount; i++)
    {
        for (int j = 0; j < stringLength; j++)
        {
            cout << strings[i][j];
        }
    }

    // ���������� ������, ���������� ��� ������ 
    // ��� '\0' ����� ����
    char concatStrings[fullLength] = {};

    // ��������� �� ������ ������ ������ ���������� �������
    char* pString = &strings[0][0];

    // ���������� ����������� �������
    for (int i = 0, j = 0; i < fullLength; i++)
    {
        if (pString[i] != '\0')
        {
            concatStrings[j] = pString[i];
            j++;
        }
    }

    // ������������ ����� ������������� �����
    int maxPalindromeLength = 0;

    // ������ ������ �������� ������������� ����� � 
    // ���������� �������
    int maxPalindromeIndex = 0;

    // ����� �������� ����� 
    int wordLength = 0;

    // ���� �� ���� ������
    // wordLength + 1 - ��� ����� ����� + ������ ����� ����
    // ��� �� ����� ����� �������� �� ���������� �����
    for (int i = 0; i < fullLength; i += wordLength + 1)
    {
        wordLength = 0;
        int currentCharIndex = i;
        bool isEndOfWord = false;

        // ������� ����� �����
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

        // �������� �� ��������������
        bool isPalindrome = true;
        int temp = wordLength - 1;
        for (int j = i; j < i + (wordLength - 1) / 2; j++)
        {
            // j - ������ �����, ������� � ����� ����� �����
            // � �� �����������. 
            // (i + temp--) - ������ �����, ������� � �����
            // ������ ����� � �� �����������
            if (concatStrings[j] != concatStrings[i + temp--])
            {
                isPalindrome = false;
            }
        }

        // ����������� ������������ ����� � ������� �����
        if (isPalindrome && maxPalindromeLength < wordLength)
        {
            maxPalindromeLength = wordLength;
            maxPalindromeIndex = i;
        }
    }

    cout << "\n����� ������� ������������ �����:\n";
    for (int i = maxPalindromeIndex; i < maxPalindromeIndex + maxPalindromeLength; i++)
    {
        cout << concatStrings[i];
    }

    cout << "\n";
    system("pause");
}