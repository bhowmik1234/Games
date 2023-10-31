#include <stdio.h>

void printing(char arr[], int num);
int user_input();
int AI(int num);
void decor();

int flag = 1;
int main()
{
    int stick = 21, num=0;
    char arr[stick];
    
    // adding '|' element to the array
    for(int i=0; i<stick; i++)
    {
        arr[i] = '|';
    }

    printing(arr, stick);

    // main body part
    while(stick > 0)
    {
        if(stick > 0)
        {
            int n = AI(stick);
            printf("Computer turn. \nIt choose: %d\n", n);
            stick -= n;
            printing(arr, stick);
        }
        if(stick > 0)
        {
            int m = user_input();
            printf("\e[1;1H\e[2J");     // it clear the terminal
            printing(arr, stick-m);
            stick -= m;
        }
        if(stick == 0)
        {
            if(flag == 1)
            {
                printf("Your Computer AI wins!!!");
            }
            else
            {
                printf("You win the game!!!");
            }
        }  
        
    }

    return 0;
}

// for decoration
void decor()
{
    printf("\n");
    printf("---------------------------------------------------------------");
    printf("\n");
}

// user entry
int user_input()
{
    int num;
    printf("Enter the number of sticks to pick up from(1-4) : ");
    scanf("%d", &num);
    while(num > 4 && num < 1)
    {
        printf("\e[1;1H\e[2J");         
        printf("Enter the number of sticks to pick up from(1-4) : ");
        scanf("%d", &num);
    }
        
    flag = 0;
    return num;

}

// printing of sticks
void printing(char arr[], int num)
{
    for(int i=0; i<num; i++)
    {
        printf("%c ", arr[i]);
    }
    printf("\n");
}

// computer input
int AI(int num)
{
    flag = 1;
    if(num <= 4 && num>=1)
    {
        return num;
    }

    else
    {
        for(int i=1; i<=4; i++)
        {  
            if((num-i)%5==0)
            {   
                return i;
            }
        }
    }  
}
