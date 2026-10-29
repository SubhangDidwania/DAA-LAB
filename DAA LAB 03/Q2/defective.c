#include <stdio.h>

int weigh(int coins[], int left, int right) {
    int weight = 0;

    for (int i = left; i <= right; i++)
        weight += coins[i];

    return weight;
}

int findDefective(int coins[],
                  int left,
                  int right,
                  int normalWeight,
                  int *weighings) {

    int n = right - left + 1;

    /*
     * One coin remains.
     */
    if (n == 1) {

        if (coins[left] < normalWeight)
            return left;

        return -1;
    }

    /*
     * Two coins remain.
     */
    if (n == 2) {

        (*weighings)++;

        if (coins[left] < coins[right])
            return left;

        if (coins[right] < coins[left])
            return right;

        return -1;
    }

    /*
     * Number of coins is odd.
     *
     * Keep one coin aside.
     */
    if (n % 2 != 0) {

        int middle = left + n / 2;

        int leftEnd = middle - 1;
        int rightStart = middle + 1;

        int leftWeight =
            weigh(coins, left, leftEnd);

        int rightWeight =
            weigh(coins, rightStart, right);

        (*weighings)++;

        /*
         * Left group is lighter.
         */
        if (leftWeight < rightWeight) {

            return findDefective(
                coins,
                left,
                leftEnd,
                normalWeight,
                weighings
            );
        }

        /*
         * Right group is lighter.
         */
        if (rightWeight < leftWeight) {

            return findDefective(
                coins,
                rightStart,
                right,
                normalWeight,
                weighings
            );
        }

        /*
         * Both groups have equal weight.
         *
         * Therefore the set-aside coin
         * must be defective if it is lighter.
         */
        if (coins[middle] < normalWeight)
            return middle;

        return -1;
    }

    /*
     * Even number of coins.
     */
    int mid = left + n / 2 - 1;

    int leftWeight =
        weigh(coins, left, mid);

    int rightWeight =
        weigh(coins, mid + 1, right);

    (*weighings)++;

    /*
     * Left group is lighter.
     */
    if (leftWeight < rightWeight) {

        return findDefective(
            coins,
            left,
            mid,
            normalWeight,
            weighings
        );
    }

    /*
     * Right group is lighter.
     */
    if (rightWeight < leftWeight) {

        return findDefective(
            coins,
            mid + 1,
            right,
            normalWeight,
            weighings
        );
    }

    /*
     * Equal weights.
     *
     * No defective coin exists among
     * these coins.
     */
    return -1;
}

int main() {

    int n;

    printf("Enter number of coins: ");
    scanf("%d", &n);

    int coins[n];

    printf("Enter the normal weight of a coin: ");
    int normalWeight;
    scanf("%d", &normalWeight);

    printf("Enter the weights of the coins:\n");

    for (int i = 0; i < n; i++) {
        printf("Coin %d: ", i + 1);
        scanf("%d", &coins[i]);
    }

    int weighings = 0;

    int result = findDefective(
        coins,
        0,
        n - 1,
        normalWeight,
        &weighings
    );

    printf("\n-----------------------------\n");

    if (result == -1) {
        printf("No defective coin found.\n");
    }
    else {
        printf("Defective coin: %d\n",
               result + 1);

        printf("Weight: %d\n",
               coins[result]);
    }

    printf("Number of weighings: %d\n",
           weighings);

    printf("-----------------------------\n");

    return 0;
}