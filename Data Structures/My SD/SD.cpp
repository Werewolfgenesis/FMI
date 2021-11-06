#include <iostream>
#include <stack>
#include <queue>
#include <string.h> 
#include <fstream>
#include <cmath>

int calculate(char * str)
{
    std::stack<int> nr; 
    std::stack<char> op;
    int i = strlen(str) - 1;
    
    while(i >= 0)
    {
        if(str[i] >= '0' && str[i] <= '9')
        {
            int j = i;
            int elem = str[i] - '0';
            while (str[j-1] >= '0' && str[j-1] <= '9')
            {
                elem = elem + (str[j-1] - '0') * 10;
            }
            
            int elem = str[i] - '0';
            nr.push(elem);
        }
        else
        {
            op.push(str[i]);
           if (op.top() == '(')
           {
               op.pop();
               char symbol = op.top();
               op.pop();
               op.pop();
               
               int temp = nr.top();
               nr.pop();
               int result;

               if (symbol == '+')
               {
                   result = temp + nr.top();
               }
               if (symbol == '*')
               {
                    result = temp * nr.top();
               }
               if (symbol == '/')
               {
                    result = temp / nr.top();
               }
               if (symbol == '-')
               {
                    result = temp * nr.top();
               }
               nr.pop();
               nr.push(result);
           } 
        } 
        i--;
    }
    return nr.top();
}
//task 3
//TODO

int main()
{
   
    std::ofstream fn;
    char arr[128];
    std::string line;
    fn.open("task2.txt");
    fn << "(17+(2*(3+4)))/n";
    fn.close();

    std::ifstream file("task2.txt");
    while (getline(file, line))
    {
        strcpy(arr,line.c_str());
    }
    file.close();

    fn.open("task2.txt");
    fn << "result is " << calculate(arr);
    return 0;


}