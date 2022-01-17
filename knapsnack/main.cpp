#include <iostream>
#include <fstream>

typedef unsigned int uint;

uint max(uint a, uint b);

struct items {
    uint id;
    uint weight;
    uint price;
};

struct DP {
    uint total_cost;
    uint* item_count;
};

class Backpack {
private:
    uint W, n;
    items* item;

public:

    void unbounded();
    void _0_1();
    Backpack() {
        FILE* input;

        input = fopen("input.txt", "r");

        if (input == NULL) {
            perror("Error: file wasn't open!\n");
            exit(-1);
        }
        else {
            printf("Info: file was open!\n");
        }

        fscanf_s(input, "%u %u", &W, &n);

        printf("Backpack weight - %u Items count - %u\n", W, n);

        item = (items*)calloc(n, sizeof(items));

        for (uint i = 0; i < n; i++) {
            item[i].id = i;
            fscanf_s(input, "%u %u", &item[i].weight, &item[i].price);
        }

        for (uint i = 0; i < n; i++) {
            printf("id - %2u, weight - %2u, price - %2u\n", item[i].id, item[i].weight, item[i].price);
        }
        fclose(input);
    }
    ~Backpack() {
        free(item);
    }
};

void Backpack::unbounded() {
    // memotable
    DP* dp;

    dp = (DP*)calloc(W + 1, sizeof(DP));
    for (int i = 0; i != W + 1; i++) {
        dp[i].item_count = (uint*)calloc(n, sizeof(uint));
    }

    for (uint w = 1; w <= W; w++) {
        for (uint i = 0; i < n && item[i].weight <= w; i++) {
            uint old_cost = dp[w].total_cost;
            dp[w].total_cost = max(old_cost, dp[w - item[i].weight].total_cost + item[i].price);
            if (dp[w].total_cost > old_cost) {
                //for (uint j = 0; j < n; j++) {
                //    dp[w].item_count[j] = dp[w - item[i].weight].item_count[j];
                //}
                memcpy(dp[w].item_count, dp[w - item[i].weight].item_count, sizeof(uint) * n);
                dp[w].item_count[i]++;
            }
        }
    }

    // weight
    uint totalW = 0;
    for (uint i = 0; i < n; i++) {
        totalW += dp[W].item_count[i] * item[i].weight;
    }

    //
    printf("\n");
    for (uint i = 0; i < n; i++) {
        printf("Item id - %u; Count - %u\n", i, dp[W].item_count[i]);
    }
    printf("Optimal weight - %u\n", totalW);
    printf("Best cost - %u\n", dp[W].total_cost);

    for (uint i = 0; i < W + 1; i++) {
        free(dp[i].item_count);
    }
    free(dp);
}

void Backpack::_0_1() {
    // memotable
    DP* dp;

    dp = (DP*)calloc(W + 1, sizeof(DP));
    for (int i = 0; i != W + 1; i++) {
        dp[i].item_count = (uint*)calloc(n, sizeof(uint));
    }

    int w;
    for (uint i = 0; i < n; i++) {
        for (w = W; w >= 0; w--) {
            if (item[i].weight <= w) {
                uint old_cost = dp[w].total_cost;
                dp[w].total_cost = max(old_cost, dp[w - item[i].weight].total_cost + item[i].price);
                if (dp[w].total_cost > old_cost) {
                    memcpy(dp[w].item_count, dp[w - item[i].weight].item_count, sizeof(uint) * n);
                    dp[w].item_count[i]++;
                }
            }
        }
    }

    // weight
    uint totalW = 0;
    for (int i = 0; i < n; i++) {
        totalW += dp[W].item_count[i] * item[i].weight;
    }

    printf("\n");
    for (int i = 0; i < n; i++) {
        if (dp[W].item_count[i]) {
            printf("Item %d in backpack\n", i);
        }
    }
    printf("Optimal weight - %u\n", totalW);
    printf("Best cost - %u\n", dp[W].total_cost);

    for (uint i = 0; i < W + 1; i++) {
        free(dp[i].item_count);
    }
    free(dp);
}

int main()
{
    Backpack backpack;
    backpack.unbounded();
   // backpack._0_1();
    return 0;
}

uint max(uint a, uint b) {
    return a > b ? a : b;
}
