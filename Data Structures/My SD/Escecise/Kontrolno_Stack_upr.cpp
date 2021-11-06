#include <iostream>
#include <stack>

//create a stack els from q AND p
std::stack<int> createAND(std::stack<int> p, std::stack<int> q)
{
    std::stack<int> newS;
    while (!p.empty())
    {
        /* code */
        std::stack<int> temp = q;
        while (!temp.empty())
        {
            /* code */
            if(p.top() == temp.top())
            {
                newS.push(temp.top());
            }
            temp.pop();
        }
        p.pop();
    }
}

void print(std::stack<int> s)
{
    while (!s.empty())
    {
        std::cout << s.top() << " ";
        s.pop();
    }
    
}
int main()
{
    std::stack<int> s1,s2,s3;
    s1.push(3);
    s1.push(6);
    s1.push(8);
    s1.push(2);
    s1.push(1);
    s1.push(12);
    s2.push(4);
    s2.push(5);
    s2.push(9);
    s2.push(11);
    print(s1);
    s3 = createAND(s1, s2);
    print(s3);

    return 0;
}