////////////////////////////////////////////////////////////////////////////////////////////////
// Just exposing an interface to the ImageTexture functions reachable in GDNative
// Basically just ported some of the functions in the cpp_bindings for use in C
//
// Written by Bastiaan "Mux213" Olij and Paritosh Sharma,
// with loads of help from Thomas "Karroffel" Herzog

#ifndef OS_H
#define OS_H

#include "godot_calls.h"

#ifdef __cplusplus
extern "C" {
#endif

int64_t OS_get_ticks_msec();
godot_vector2 OS_get_screen_size(const int64_t screen = -1);

#ifdef __cplusplus
}
#endif

#endif /* !OS_H */
