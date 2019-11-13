#include <Adder.h>

namespace libadder {

    int add(int sum1, int sum2) {
        return sum2 < 0 ? add(sum1 - 1, sum2 + 1)
                        : sum2 > 0 ? add(sum1 + 1, sum2 - 1)
                                   : sum1;
    }

}