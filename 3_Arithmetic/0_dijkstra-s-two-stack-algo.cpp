#include <cassert>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <unordered_map>
#include <functional>
#include <stack>
#include <string_view>
#include <charconv>

struct operation
{
    uint32_t priority;
    std::function<int(int, int)> make_operation;
};

int solve_equation(std::string_view equation)
{
    static const std::unordered_map<char, operation> operations = {
        {'(', {0, [](auto&&...){ assert(false); return -1; }}},
        {'+', {1, [](int a, int b){ return a + b; }}},
        {'-', {1, [](int a, int b){ return a - b; }}},
        {'*', {2, [](int a, int b){ return a * b; }}},
        {'/', {2, [](int a, int b){ return a / b; }}},
        {'^', {3, [](int a, int b){ return std::pow(a, b); }}}
    };
    std::stack<int>  nums;
    std::stack<char> ops;
    
    auto make_operation = [&]{
        int b = nums.top(); nums.pop();
        int a = nums.top(); nums.pop();
        char operation = ops.top(); ops.pop();
        int result = operations.at(operation).make_operation(a, b);
        nums.push(result);
    };

    while (equation.size())
    {
        size_t size_of_prefix_to_remove = 1u;
        char current_symbol = equation[0];
        if (current_symbol == '(')
        {
            ops.push('(');
        }
        else if (current_symbol == ')')
        {
            while (ops.top() != '(')
                make_operation();
            ops.pop();
        }
        else if (operations.contains(current_symbol))
        {
            auto current_op_priority = operations.at(current_symbol).priority;
            while (ops.size() != 0 && operations.at(ops.top()).priority >= current_op_priority)
                make_operation();
            ops.push(current_symbol);
        }
        else if (std::isalnum(current_symbol))
        {
            int number;
            auto res = std::from_chars(equation.data(), equation.data() + equation.size(), number);
            if (res.ec != std::errc())
            {
                std::cerr << "integer number parse failed" << std::endl;
                exit(1);
            }
            nums.push(number);
            size_of_prefix_to_remove = equation.find_first_not_of("0123456789");
            if (size_of_prefix_to_remove == std::string_view::npos)
                size_of_prefix_to_remove = equation.size();
        }
        else if (!std::isspace(current_symbol))
        {
            std::cerr << "unrecognized current_symbol" << std::endl;
            exit(2);
        }
        equation.remove_prefix(size_of_prefix_to_remove);
    }
    
    while (ops.size())
        make_operation();
    return nums.top();
}

int main(int argc, char* argv[])
{
    if (argc != 2)
        std::cerr << "invalid number of arguments, please provide only one equation as string" << std::endl;
    
    std::cout << "The anwser is: " << solve_equation(argv[1]) << std::endl;

    return 0;
}