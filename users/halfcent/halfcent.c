#include "halfcent.h"

__attribute__ ((weak))
layer_state_t layer_state_set_keymap (layer_state_t state) {
    return state;
}

layer_state_t layer_state_set_user (layer_state_t state) {
    state = update_tri_layer_state(state, 1, 2, 3);
    return layer_state_set_keymap (state);
}