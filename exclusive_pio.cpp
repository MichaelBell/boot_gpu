#include "hardware/pio.h"

static const pio_program* pio_prog[2] = {nullptr, nullptr};
static uint16_t pio_offset[2] = {0xffff, 0xffff};

const void pio_remove_exclusive_program(PIO pio) {
    uint8_t pio_index = pio == pio0 ? 0 : 1;
    const pio_program* current_program = pio_prog[pio_index];
    uint16_t current_offset = pio_offset[pio_index];
    if(current_program) {
        pio_remove_program(pio, current_program, current_offset);
        pio_prog[pio_index] = nullptr;
        pio_offset[pio_index] = 0xffff;
    }
}

const uint16_t pio_change_exclusive_program(PIO pio, const pio_program* prog) {
    pio_remove_exclusive_program(pio);
    uint8_t pio_index = pio == pio0 ? 0 : 1;
    pio_prog[pio_index] = prog;
    pio_offset[pio_index] = pio_add_program(pio, prog);
    return pio_offset[pio_index];
};

