#include "Sample.hpp"

int main(void)
{
    Sample  sample;

    sample.test('a');
    sample.test(12);
    sample.test(8.2f);
    sample.test(sample);
    return (0);
}
