#include <stdio.h>
int tool(int x) 
{
    return x * 2;
}
int main() 
{
    int result = tool(5);
    printf("Result: %d\n", result);
    return result;
}