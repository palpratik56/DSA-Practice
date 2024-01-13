#include <stdio.h>
#include <stdlib.h>

// Structure to represent items
struct Item {
    int weight;
    int value;
};

// Function to compare items based on their value per unit weight
int compare(const void *a, const void *b) {
    double ratio1 = (double)(((struct Item *)a)->value) / (((struct Item *)a)->weight);
    double ratio2 = (double)(((struct Item *)b)->value) / (((struct Item *)b)->weight);
    return (ratio2 > ratio1) ? 1 : -1;
}

// Function to solve fractional knapsack using greedy approach
double fractionalKnapsack(int capacity, struct Item items[], int n) {
    // Sort items based on value per unit weight in descending order
    qsort(items, n, sizeof(struct Item), compare);

    double totalValue = 0.0;
    int currentWeight = 0;

    // Iterate through sorted items and add them to the knapsack
    for (int i = 0; i < n; ++i) {
        if (currentWeight + items[i].weight <= capacity) {
            // Add the whole item to the knapsack
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        } else {
            // Add a fraction of the item to the knapsack
            double remainingCapacity = capacity - currentWeight;
            totalValue += (remainingCapacity / items[i].weight) * items[i].value;
            break;
        }
    }

    return totalValue;
}

int main() {
    int n;
    printf("\n Enter the number of items: ");
    scanf("%d",&n);
    Item items[n];

    printf("Enter the weight and price of each item:\n");
    for (int i = 0; i < n; ++i) {
        printf("item %d: ",i+1);
        scanf("%d%d",&items[i].weight,&items[i].value);
        //items[i].ratio = static_cast<double>(items[i].price) / items[i].weight;
    }

    int capacity; // Knapsack capacity
    int c;
    do{
        printf("Enter the capacity of the knapsack: ");
        scanf("%d",&capacity);
        double totalValue = fractionalKnapsack(capacity, items,n);
        printf("\nMaximum profit is: %f",totalValue);
        printf("\npress 1 to run again else 0: ");
        scanf("%d",&c);
    }while(c==1);
    return 0;
}
