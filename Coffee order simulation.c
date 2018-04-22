//This program simulates ordering a coffee at a local coffee shop for anyone to enjoy and read
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


double coffee_prices[3][2] =
{
    {2.65,2.95},
    {3.35,3.95},
    {3.85,4.45}
};

double getPrice(int coffeeType, int size)
{
    return coffee_prices[coffeeType-1][size-1];
}

int getCoffeeType()
{
    int espresso_type;
    printf("What type (1: Americano, 2: Latte, 3: Mocha): ");
    scanf("%d", &espresso_type);
    return espresso_type;
}

int getCoffeeSize()
{
    int espresso_size;
    printf("What size (1: Tall, 2: Grande):");
    scanf("%d", &espresso_size);
    return espresso_size;
}

double handleOrder(i)
{
    int espresso_type, espresso_size;
    double espresso_price;

    printf("Getting order for espresso drink #%d\n",i);
    espresso_type = getCoffeeType();
    espresso_size = getCoffeeSize();
    espresso_price = getPrice(espresso_type, espresso_size);
    return espresso_price;
}

int main()
{

    int number_of_espresso_drinks;
    double espresso_total = 0.0;

    printf("Welcome to CoffeeOrder 3000.\n");
    printf("How many espresso drinks would you like today (0-3):");
    scanf("%d",&number_of_espresso_drinks );

    assert(number_of_espresso_drinks<4);

    if (number_of_espresso_drinks == 0)
    {
        printf("OK, so you do not want any espressos today!\n");
        return 0;
    }
    double espresso_price;
    for (int i= 1; i<=number_of_espresso_drinks; i++)
    {
        espresso_price = handleOrder(i);
        espresso_total = espresso_total+espresso_price;
    }

    printf("Your total is: %.2f\n", espresso_total);
    printf("Thank you for using CoffeeOrder 3000\n");
    return 0;
}
