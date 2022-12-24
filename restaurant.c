#include <stdio.h>
#include <stdlib.h>

int again;
int total=0;
float gst,sgst,cgst;

int beverages_rate[5][2] = { {0,20},
                             {1,30},
                             {2,60},
                             {3,30},
                             {4,50}
                            };
int starter_rate[4][2] = {  {0,80},
                            {1,120},
                            {2,90},
                            {3,130}
                            };
int mcourse_rate[7][2] = {  {0,165},
                            {1,150},
                            {2,170},
                            {3,180},
                            {4,120},
                            {5,100},
                            {6,30}
                         };
int dessert_rate[4][2] = {  {0,60},
                            {1,20},
                            {2,50},
                            {3,80}
                            };

int purchased[][3]={{0,0},
                        {0,0},
                        {0,0},
                        {0,0},
                        {0,0},
                        {0,0},
                        {0,0}
                        };

void beverages(char beverages_menu[][100]);
void starters(char starters_menu[][100]);
void mcourse(char mcourse_menu[][100]);
void dessert(char dessert_menu[][100]);

void repeat_beverages(char beverages_menu[][100]);
void repeat_starters(char starters_menu[][100]);
void repeat_mcourse(char mcourse_menu[][100]);
void repeat_dessert(char dessert_menu[][100]);

void display_beverages_bill(char beverages_menu[][100]);
void display_starters_bill(char starters_menu[][100]);
void display_mcourse_bill(char mcourse_menu[][100]);
void display_dessert_bill(char dessert_menu[][100]);

void display_beverages_menu();
void display_starters_menu();
void display_mcourse_menu();
void display_dessert_menu();
void display();

int main()
{
    char beverages_menu[][100] = {"Tea", "Hot coffee", "Cold Coffee", "Fresh Lime Soda", "Fruit Juice"};
    char starters_menu[][100] = {"French fries", "Chilly Potato", "Cheese balls", "Pasta"};
    char mcourse_menu[][100] = {"Shahi Paneer", "veg-Munchurian", "Paneer Butter Masala", "Chilly Paneer","Dal Tadka", "Jeera Rice", "Butter Naan"};
    char dessert_menu[][100] = {"Brownie", "Gulab Jamuun", "Ice-Cream", "Chocolava-cake"};
      char choice;
    display();
        printf("\n\nEnter your choice here : ");
        scanf("%c", &choice);
        getchar();
        while(choice!='e')
        {
            switch(choice)
        {
            enter:
            case 'A':
            case 'a':printf("\nBeverages\n");
                    beverages(beverages_menu);
                    break;
            case 'B':
            case 'b':printf("\nStarters\n");
                    starters(starters_menu);
                    break;
            case 'C':
            case 'c':printf("\nMain Course\n");
                    mcourse(mcourse_menu);
                    break;
            case 'D':
            case 'd':
                printf("\nDessert\n");
                dessert(dessert_menu);
                break;
           default:printf("\nInvalid Choice!!\n");
                    goto enter;
        }
      }
    return 0;
}
void display()
{
    printf("                The Royal Foods Restaurant.          \n ");
    printf("             ******************************         \n\n");
    printf("              -- Please select a choice -- \n\n");
    printf("\t\t      [A] Beverages\n");
    printf("\t\t      [B] Starters\n");
    printf("\t\t      [C] Main Course\n");
    printf("\t\t      [D] Desserts\n");
}
void display_beverages_menu()
{
    printf("                  $  Beverages  $ \n\n");
    printf("  -- Please select among the following -- \n\n");
    printf("\t\t   [0] Tea - Rs 20.00\n");
    printf("\t\t   [1] Hot Coffee - Rs 30.00\n");
    printf("\t\t   [2] Cold Coffee - Rs 60.00\n");
    printf("\t\t   [3] Fresh Lime Soda Rs 30.00\n");
    printf("\t\t   [4] Fruit Juice- Rs 50.00\n");

}
void beverages(char beverages_menu[][100])
{
    int choice = 0,i;
    int quantity = 0;
    int again = 0,amt=0;
    int code;
    display_beverages_menu();
    printf("\nEnter the choice : ");
    scanf("%d", &code);
    getchar();

    if(code>=0&&code<=4)
    {
        printf("\nEnter the quantity : ");
        scanf("%d",&quantity);
        purchased[code][1]= quantity*beverages_rate[code][1];
        total= total + purchased[code][1];
        gst=total*0.15;
        cgst=gst/2;
        sgst=gst/2;
        total = total + gst;
        printf("Total is %d\n\n",total);
    }
    else
    {
        printf("\nInvalid code entered, Please enter the code again!!!!\n\n");
        beverages(beverages_menu);
    }
    repeat_beverages(beverages_menu);

}
void repeat_beverages(char beverages_menu[][100])
{
    printf("\nWould you like to buy anything else?\n[1] Yes , [2] No : ");
    scanf("%d",&again);
    if (again == 1)
            beverages(beverages_menu);
    else if (again == 2 )
    {
        display_beverages_bill(beverages_menu);
        exit(0);
    }
    else
    {
        printf("\n\n\t\tSorry Invalid Decision Entered\n");
        repeat_beverages(beverages_menu);
    }
}
void display_beverages_bill(char beverages_menu[][100])
{
    int i;
    printf("  +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+          \n\n");
    printf("                      The Royal Foods RESTAURANT                   \n");
    printf("                          BILLING INFORMATION                \n");
    printf("\t\t ITEMS\t\tPrice(in Rs.)\n");
    for(i=0;i<5;i++)
    {
        if(purchased[i][1]!=0)
        {
            printf("\t\t%s\t\t",beverages_menu[i]);
            printf("%d\n",purchased[i][1]);
        }
    }
    printf("\t\tGST=Rs.%0.2f\n",gst);
    printf("\t\tC-GST=Rs.%0.2f\n",cgst);
    printf("\t\tS-GST=Rs.%0.2f\n",sgst);
    printf("\t\t\n\nTotal=Rs.%d\n",total);
    printf("\n\n  +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+          \n\n");

}
void display_starters_menu()
{
    printf("                   $  Starters  $ \n\n");
    printf("  -- Please select among the following -- \n\n");
    printf("\t\t   [0] French fries - Rs 80.00\n");
    printf("\t\t   [1] Chilli Potato- Rs 120.00\n");
    printf("\t\t   [2] Cheese Balls - Rs 90.00\n");
    printf("\t\t   [3] Pasta - Rs 130.00\n");
    printf("Enter your choice here : ");

}
void starters(char starters_menu[][100])
{
    int choice = 0,i;
    int quantity = 0;
    int again = 0,amt=0;
    int code;
    display_starters_menu();
    printf("\nEnter the code : ");
    scanf("%d", &code);
    getchar();
    if(code>=0&&code<=3)
    {
        printf("\nEnter the quantity : ");
        scanf("%d",&quantity);
        purchased[code][1]= quantity*starter_rate[code][1];
         total+=purchased[code][1];
        gst=total*0.15;
        cgst=gst/2;
        sgst=gst/2;
        total = total + gst;
    }
    else
    {
        printf("\nInvalid code entered, Please try again!!!!\n\n");
         starters(starters_menu);
    }
    repeat_starters(starters_menu);

}

void repeat_starters(char starters_menu[][100])
{
    printf("\nWould you like to buy anything else?\n[1] Yes , [2] No : ");
    scanf("%d",&again);
    if (again == 1)
            starters(starters_menu);
    else if (again == 2 )
    {
        display_starters_bill(starters_menu);
        exit(0);
    }
    else
    {
        printf("\n\n\t\tSorry Invalid Decision Entered\n");
        repeat_starters(starters_menu);
    }
}

void display_starters_bill(char starters_menu[][100])
{
    int i;
    printf("  +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+          \n\n");
    printf("                      The Royal Foods RESTAURANT                   \n");
    printf("                        BILLING INFORMATION                \n");
    printf("\t\t ITEMS\t\t\tPrice(in Rs.)\n");
    for(i=0;i<4;i++)
    {
        if(purchased[i][1]!=0)
        {
            printf("\t\t %s \t\t",starters_menu[i]);
            printf("%d\n",purchased[i][1]);
        }
    }
    printf("\t\tGST=Rs.%0.2f\n",gst);
    printf("\t\tC-GST=Rs.%0.2f\n",cgst);
    printf("\t\tS-GST=Rs.%0.2f\n",sgst);
    printf("\t\tTotal=Rs.%d\n",total);
    printf("\n\n  +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+          \n\n");
}


void display_mcourse_menu()
{
    printf("                    $  Main Course  $ \n\n");
    printf("  && Please select among the following && \n\n");
    printf("\t\t   [0] Shahi Paneer - Rs 165.00\n");
    printf("\t\t   [1] veg-Munchurian- Rs 150\n");
    printf("\t\t   [2] Paneer Butter Masala - Rs 170.00\n");
    printf("\t\t   [3] Chilli Paneer - Rs 180.00\n");
    printf("\t\t   [4] Dal Tadka - Rs 120.00\n");
    printf("\t\t   [5] Jeera Rice - Rs 100.00\n");
    printf("\t\t   [6] Butter Naan - Rs 30.00\n");

}
void mcourse(char mcourse_menu[][100])
{
    int choice = 0,i;
    int quantity = 0;
    int again = 0,amt=0;
    int code;
    display_mcourse_menu();

    printf("\nEnter the code : ");
    scanf("%d", &code);
    getchar();
    if(code>=0&&code<=6)
    {
        printf("\nEnter the quantity : ");
        scanf("%d",&quantity);
        purchased[code][1]= quantity*mcourse_rate[code][1];
        total+=purchased[code][1];
        gst=total*0.12;
        cgst=gst/2;
        sgst=gst/2;
        total = total + gst;
    }
    else
    {
        printf("\nInvalid code, Please enter again!!\n\n");
        mcourse(mcourse_menu);
    }
    repeat_mcourse(mcourse_menu);

}

void repeat_mcourse(char mcourse_menu[][100])
{

    printf("\nWould you like to buy anything else?\n[1] Yes , [2] No : ");
    scanf("%d",&again);
    if (again == 1)
    {
        mcourse(mcourse_menu);
    }
    else if (again == 2 )
    {
        display_mcourse_bill(mcourse_menu);
        exit(0);
    }
    else
    {
        printf("\n\n\t\tSorry Invalid Decision Entered\n");
        repeat_mcourse(mcourse_menu);
    }
}

void display_mcourse_bill(char mcourse_menu[][100])
{
    int i;
    printf("  +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+          \n\n");
    printf("                      The Royal Foods RESTAURANT                   \n");
    printf("                         BILLING INFORMATION                \n");
    printf("\t\t ITEMS\t\t\tPrice(in Rs.)\n");
    for(i=0;i<7;i++)
    {
        if(purchased[i][1]!=0)
        {
            printf("\t\t %s \t\t",mcourse_menu[i]);
            printf("%d\n",purchased[i][1]);
        }

    }
    printf("\t\tGST=Rs.%0.2f\n",gst);
    printf("\t\tC-GST=Rs.%0.2f\n",cgst);
    printf("\t\tS-GST=Rs.%0.2f\n",sgst);
    printf("\t\tTotal=Rs.%d\n\n",total);
    printf("\n\n  +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+          \n\n");
}


void display_dessert_menu()
{
    printf("                   $  Desserts  $ \n\n");
    printf("     -- Please select among the following -- \n\n");
    printf("\t\t   [0] Brownie - Rs 60.00\n");
    printf("\t\t   [1] Gulab Jamun- Rs 20.00\n");
    printf("\t\t   [2] Ice-Cream(Chocolate/Vanilla/Strawberry) - Rs 50.00\n");
    printf("\t\t   [3] Chocolava-cake - Rs 80.00\n");

}
void dessert(char dessert_menu[][100])
{
    int choice = 0,i;
    int quantity = 0;
    int again = 0,amt=0;
    int code;
    display_dessert_menu();

    printf("\nEnter the code : ");
    scanf("%d", &code);
    getchar();
    if(code>=0&&code<=3)
    {
        printf("\nEnter the quantity : ");
        scanf("%d",&quantity);
        purchased[code][1]= quantity*dessert_rate[code][1];
        total+=purchased[code][1];
        gst=total*0.12;
        cgst=gst/2;
        cgst=gst/2;
        total = total + gst;
    }
    else
    {
        printf("\nInvalid code, Please enter again!!\n\n");
        dessert(dessert_menu);
    }
    repeat_dessert(dessert_menu);
}

void repeat_dessert(char dessert_menu[][100])
{

    printf("\nWould you like to buy anything else?\n[1] Yes , [2] No : ");
    scanf("%d",&again);
    if (again == 1)
    {
        dessert(dessert_menu);
    }
    else if (again == 2 )
    {
        display_dessert_bill(dessert_menu);
        exit(0);
    }
    else
    {
        printf("\n\n\t\tSorry Invalid Decision Entered\n");
        repeat_dessert(dessert_menu);

    }
}

void display_dessert_bill(char dessert_menu[][100])
{
    int i;
    printf("  +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+          \n\n");
    printf("                      The Royal Foods RESTAURANT                   \n");
    printf("                    BILLING INFORMATION                \n");
    printf("\t\t ITEMS\t\t\tPrice(in Rs.)\n");
    for(i=0;i<4;i++)
    {
        if(purchased[i][1]!=0)
        {
            printf("\t\t %s \t\t",dessert_menu[i]);
            printf("%d\n",purchased[i][1]);
        }

    }
    printf("\t\tGST=Rs.%0.2f\n",gst);
    printf("\t\tC-GST=Rs.%0.2f\n",cgst);
    printf("\t\tS-GST=Rs.%0.2f\n",sgst);
    printf("\t\tTotal=Rs.%d\n\n",total);
    printf("\n\n  +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+          \n\n");
}



