#include <iostream>
#include <fstream>

using namespace std;

int commonSubstringLength(string str1, string str2)
{
    //Counter for common letters
    int commonLength = 0;
    //Determination of minimum allowable common size
    int delimiter = min(str1.length(), str2.length());
    //Iterate over minimum length to check for char equality
    for (int i = 0; i < delimiter; i++)
    {
        if (str1[i] == str2[i]) //Evaluate for equality and increase counter if equals
            commonLength++;
        else //No char in commons means the max common length has been acheived and forces the  end of evaluation
            return commonLength;
    }
}

bool canConvert(string str1, string str2, int k)
{
    //Delete all of string str1 and append str2 in k operations
    //If necessary, consider deletion in empty string to reach quota
    if ((str1.length() + str2.length()) < k)
        return true;

    //Common string length determination
    int commonLength = commonSubstringLength(str1, str2);

    //Letters count to be removed
    int removeCount = str1.length() - commonLength;
    //Letters count to be appended
    int addCount = str2.length() - commonLength;

    //Check if is divisible by 2 since two operations for transformation are necessary,
    //one to remove and other to append.
    //Check if positive or zero since a negative value indicates not enough operations
    //available for transformation
    if ((k - removeCount - addCount) >= 0 &&
        ((k - removeCount - addCount) % 2 == 0))
        return true;

    //Cannot execute the tranformation in number of operations used
    return false;
}

//Check if input value is allowed to be parsed to int
int parse2int(string str, int line)
{
    try
    {
        return stoi(str);
    }
    catch (const std::invalid_argument &e)
    {
        cout << "Exception occurred: Failed to parse '" << str << "' in line " << line << " of the input file." << endl;
    }
}

//Print output result to terminal
void printResult(bool result)
{
    if (result)
        cout << "sim" << endl;
    else
        cout << "n\u00E3o" << endl;
}

//Main routine
int main()
{
    //File open
    ifstream file("inputs.txt");
    string str;

    //Iterate over input file
    int line = 0;
    while (getline(file, str))
    {
        line++;
        //First line read
        string str1 = str;
        //Read second line
        getline(file, str);
        line++;
        string str2 = str;
        //Read third line
        getline(file, str);
        line++;
        int k = parse2int(str, line);
        //Verify the conversion
        bool convert = canConvert(str1, str2, k);
        //Print result
        printResult(convert);
    }
}