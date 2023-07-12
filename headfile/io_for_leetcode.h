/*
* 该头文件包含了一些经常用到的输入输出处理函数，省得每次都要自行重写。

* 初始只针对输入输出是vector以及string的情形进行了封装，后续会不断增添
*/
#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <sstream>

class input {
public:
    // 按照默认执行构造与析构，省去

    // 输入数组的函数
    std::vector<int>& input_vector()
    {
        std::cout << "Please input the array(Enter To End): ";
        while (std::cin >> input_data)
        {
            input_vec.push_back(std::move(input_data));
            if(std::cin.get() == '\n')   break;
        }

        if (std::cin.fail())
        {
            // 输入错误处理逻辑
            std::cout << "Format wrong, invalid input, please input again!" << std::endl;

            // 清空输入流
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        return input_vec;
    }

    std::string& input_string()
    {
        std::getline(std::cin, input_str);
        return input_str;
    }

    // 输入一个二维数组
    std::vector<std::vector<int>>& input_matrix()
    {
        std::cout << "Please input the matrix(Enter to next row): \n";

        std::string row_input;

        while (std::getline(std::cin, row_input))
        {
            if (row_input == "q" || row_input == "Q")   break;
            std::vector<int> row_vec;
            std::istringstream iss(row_input);
            int elem;
            while (iss >> elem) row_vec.push_back(elem);
            input_mat.emplace_back(row_vec);
        }

        if (std::cin.fail())
        {
            // 输入错误处理逻辑
            std::cout << "Format wrong, invalid input, please input again!" << std::endl;

            // 清空输入流
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        return input_mat;
    }

private:
    std::vector<int> input_vec;
    std::vector<std::vector<int>> input_mat;
    std::string input_str;
    int input_data;
};


class output {
public:
    // 按照默认执行构造与析构，省去

    // 输出一维数组
    void output_array(const std::vector<int>& array)
    {
        for (auto& elem : array)
        {
            if (is_first)
            {
                std::cout << elem;
                is_first = false;
            }
            else    std::cout << " " << elem;
        }
        std::cout << std::endl;
        is_first = true;
    }

    // 输出二维数组
    void output_matrix(const std::vector<std::vector<int>>& matrix)
    {
        for (const auto& vec : matrix)
        {
            for(auto& elem : vec)
            {
                if (is_first)
                {
                    std::cout << elem;
                    is_first = false;
                }
                else    std::cout << " " << elem;
            }
            std::cout << std::endl;
            is_first = true;
        }
    }
private:
    bool is_first = true;    
};