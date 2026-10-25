# IBM 3477 terminal Model M -> splitkb Liatris (RP2040) converter
# Replaces the stock AVR rules.mk of converter/ibm_terminal wholesale.

# Protocol-level pseudo-matrix lives in matrix.c
CUSTOM_MATRIX = yes
SRC += matrix.c

# PS/2 host via RP2040 PIO state machine
PS2_ENABLE = yes
PS2_DRIVER = vendor

# Bring-up aids: hid_listen / `qmk console` shows the dprintf stream
# (reset handshake, keyboard ID, every scancode). Disable after mapping.
CONSOLE_ENABLE = yes

# Explicitly off; enable Vial bits in the keymap-level rules.mk later.
NKRO_ENABLE = yes
MOUSEKEY_ENABLE = yes
EXTRAKEY_ENABLE = yes
