#include <iostream> 
#include <string.h> 
using namespace std;
#define size 30

int dictionaryContains(string word)
{
    string dictionary[] = { "mobile","samsung","sam","sung","man","mango",
                           "icecream","and","go","i","like","ice","cream"};
    int dictsize = sizeof(dictionary) / sizeof(dictionary[0]);
    for (int i = 0; i < dictsize; i++)
        if (dictionary[i].compare(word) == 0)
            return true;
    return false;
}

bool wordBreak(string str)
{
    //int size = str.size();
    if (size == 0)   return true;

    bool wb[size + 1];
    memset(wb, 0, sizeof(wb)); // Initialize all values as false. 

    for (int i = 1; i <= size; i++)
    {
        if (wb[i] == false && dictionaryContains(str.substr(0, i)))
            wb[i] = true;

        if (wb[i] == true)
        {
            // If we reached the last prefix 
            if (i == size)
                return true;

            for (int j = i + 1; j <= size; j++)
            {
                if (wb[j] == false && dictionaryContains(str.substr(i, j - i)))
                    wb[j] = true;

                if (j == size && wb[j] == true)
                    return true;
            }
        }
    }

    return false;
}

// Driver program to test above functions 
int main()
{
    wordBreak("ilikesamsung") ? cout << "Yes\n" : cout << "No\n";
    wordBreak("iiiiiiii") ? cout << "Yes\n" : cout << "No\n";
    wordBreak("ilikelikeimangoiii") ? cout << "Yes\n" : cout << "No\n";
    wordBreak("samsungandmango") ? cout << "Yes\n" : cout << "No\n";
    wordBreak("samsungandmangok") ? cout << "Yes\n" : cout << "No\n";
    return 0;
}