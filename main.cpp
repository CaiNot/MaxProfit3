#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
public:
    int betterMaxProfit(vector<int> &prices) {
        /**
         * 喵啊~~
         * 利用两个方向的最大收益实现买卖两次的收入，
         * 时间复杂度只有O(n)
        **/
        int d = prices.size(), ans = 0;
        if (!d) return 0;
        int f[d], b[d];

        for (int i = 0; i < d; i++) {
            f[i] = 0;
            b[i] = 0;
        }

        int mn = prices[0], mx = prices[d - 1];
        for (int i = 1; i < d; i++) {
            f[i] = max(f[i - 1], prices[i] - mn);
            mn = min(mn, prices[i]);
        }
        for (int j = d - 2; j >= 0; j--) {
            b[j] = max(b[j + 1], mx - prices[j]);
            mx = max(mx, prices[j]);
        }

        ans = b[0];
        for (int k = 0; k < d - 1; k++)
            ans = max(ans, f[k] + b[k + 1]);
        return ans;
    }

    int maxProfit(vector<int> &prices) {
        if (prices.size() < 3) {
            return this->maxProfitPart(prices, 0, prices.size());
        }
        int maxValue = 0, maxPart1 = 0, maxPart2 = 0,
                lastValue = INT_MAX;
        maxValue = this->maxProfitPart(prices, 0, prices.size());
        if (maxValue == 0)
            return 0;
        for (int i = 2; i <= prices.size() - 2; i++) {
            if (prices[i] < lastValue) {
                maxPart1 = this->maxProfitPart(prices, 0, i);
                maxPart2 = this->maxProfitPart(prices, i, prices.size());
                maxValue = max(maxValue, maxPart1 + maxPart2);
            }
            lastValue = prices[i];
        }
        return maxValue;
    }

private:
    int maxProfitPart(vector<int> &prices, int start, int end) {
        int maxValue = 0, minValue = INT_MAX;
        for (int i = start; i < end; i++) {
            if (prices[i] < minValue) {
                minValue = prices[i];
            } else {
                if (maxValue < prices[i] - minValue)
                    maxValue = prices[i] - minValue;
            }
        }
        return maxValue;
    }
};

int main() {

    std::cout << "Hello, World!" << std::endl;
    vector<int> prices = {0, 4, 1, 5, 2, 7}, prives1 = {2, 1, 2, 0, 1};
    Solution s;
//    cout << s.maxProfit(prices) << endl;
    cout << s.maxProfit(prives1) << endl;
    return 0;
}