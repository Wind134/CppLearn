/*
* 给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。
* 最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
* 你可以假设除了整数0之外，这个整数不会以零开头。
*/
#include <iostream>
#include <vector>
using namespace std;

vector<int> plusOne(vector<int>& digits)
{
    int size = digits.size();
    
    if (digits[size - 1] < 9)
    {
        digits[size - 1]++;
        return digits;
    }
    else
    {
        if (size == 1)
        {
            digits[size - 1] = 0;
            digits.insert(digits.begin(), 1);
            return digits;
        }

        digits[size - 1] = 0;
        int index = size - 2;

        while (index >= 0)
        {
            if (index == 0)
            {
                if(digits[0] == 9)
                {
                    digits[0] = 0;
                    digits.insert(digits.begin(), 1);
                    return digits;
                }
            }
            
            if (digits[index] < 9)
            {
                digits[index]++;
                return digits;
            }
            else
            {
                digits[index] = 0;
                index--;
            }

                
        }
        return digits;
    }
}

int main()
{
    vector<int> input;

    int input_data;

    while (cin >> input_data)
    {
        input.push_back(input_data);
        if (cin.get() == '\n')
        {
            cout << "Input Finished!\n";
            break;
        }
    }

    auto output = plusOne(input);

    for (auto elem : output)
    {
        cout << elem << " "; 
    }
    cout << endl;
    return 0;
}