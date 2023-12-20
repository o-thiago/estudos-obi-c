#include <iostream>

/**
 * The problem goes like that, we have two numbers, amountWealth and maxInvestment. We must count up the minimal N
 * investments that we can make with our wealth based on the fact that each investment must have at most maxInvestment
 * size.
 * The logic flow for solving this problem used by me is that, we have a recursive divide function that takes both
 * maxInvestment and amountWealth as an argument. First of all there is the base case, if the amountWealth is less or
 * equal to the maxInvestment that we should do this means that we won't divide this thing further so we return 1, that
 * indicates the end of the divisions. Then we recursively keep applying to this function a sum of the left side of the
 * division "ceil" and the right side of the division "floor", with the base case this should give us the amount of
 * times that we were able to divide the number in integer parts till our amountWealth is divided in parts that do not
 * go over maxInvestment and are also integers.
 */


#pragma clang diagnostic push
#pragma ide diagnostic ignored "misc-no-recursion"

int divide(int maxInvestment, double amountWealth) {
    if (amountWealth <= maxInvestment) {
        return 1;
    }

    auto partial = [maxInvestment](int amountWealth) {
        return divide(maxInvestment, amountWealth);
    };

    double dividedWealth = amountWealth / 2;
    return partial(std::ceil(dividedWealth)) + partial(std::floor(dividedWealth));
}

#pragma clang diagnostic pop

int ACOES1MG() {
    int amountWealth = -1;
    int maxInvestment = -1;

    while (amountWealth + maxInvestment) {
        std::cin >> amountWealth >> maxInvestment;
        std::cout << divide(amountWealth, maxInvestment) << std::endl;
    }

    return 0;
}
