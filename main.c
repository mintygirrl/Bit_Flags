#include <stdio.h>
#include "bit_flags.h"
#include "status.h"

int main(int argc, char* argv[]) {
    // Initialize bit flags with a certain number of bits
    BIT_FLAGS flags = bit_flags_init_number_of_bits(2000000000U);
    if (flags == NULL) {
        printf("Failed to initialize bit flags.\n");
        return 1;
    }

    printf("Initial size: %d\n", bit_flags_get_size(flags));
    printf("Initial capacity: %d\n", bit_flags_get_capacity(flags));

    // Set some flags
    if (bit_flags_set_flag(flags, 100) == SUCCESS) {
        printf("Flag 100 set successfully.\n");
    } else {
        printf("Failed to set flag 100.\n");
    }

    if (bit_flags_set_flag(flags, 23) == SUCCESS) {
        printf("Flag 23 set successfully.\n");
    } else {
        printf("Failed to set flag 23.\n");
    }

    // Check some flags
    printf("Flag 100 is %s\n", bit_flags_check_flag(flags, 100) ? "set" : "not set");
    printf("Flag 23 is %s\n", bit_flags_check_flag(flags, 23) ? "set" : "not set");
    printf("Flag 7 is %s\n", bit_flags_check_flag(flags, 7) ? "set" : "not set");

    printf("After set size: %d\n", bit_flags_get_size(flags));
    printf("After set capacity: %d\n", bit_flags_get_capacity(flags));

    // Unset a flag
    if (bit_flags_unset_flag(flags, 100) == SUCCESS) {
        printf("Flag 100 unset successfully.\n");
    } else {
        printf("Failed to unset flag 100.\n");
    }

    printf("Flag 100 is now %s\n", bit_flags_check_flag(flags, 100) ? "set" : "not set");

    // Print final size and capacity
    printf("Final size: %d\n", bit_flags_get_size(flags));
    printf("Final capacity: %d\n", bit_flags_get_capacity(flags));

    // Destroy the bit flags
    bit_flags_destroy(&flags);

    if (flags == NULL) {
        printf("Bit flags successfully destroyed.\n");
    } else {
        printf("Failed to destroy bit flags.\n");
    }

    return 0;
}
