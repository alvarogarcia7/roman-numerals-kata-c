#include "theft.h"
#include <string.h>

int to_arabic(char *roman)
{
    return 0;
}

char *to_roman(int arabic)
{
    return "";
}

static enum theft_trial_res
back_and_forth(struct theft *t, void *x) {
    (void)t;
    int arabic = (int)x;

    int actual_arabic = to_arabic(to_roman(arabic));
    
    return arabic == actual_arabic ? THEFT_TRIAL_PASS : THEFT_TRIAL_FAIL ;
}


int roman_numbers_suite(void) {
    theft_seed seed = theft_seed_of_time();

    struct theft_run_config cfg = {
        .name = __func__,
        .prop1 = back_and_forth,
        .type_info = {
            theft_get_builtin_type_info(THEFT_BUILTIN_int),
        },
        .bloom_bits = 20,
        .seed = seed,
        .trials = 100,
    };

    theft_run(&cfg);
    return 0;
}

int main()
{
    roman_numbers_suite();
    return 0;
}