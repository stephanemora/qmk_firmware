COMBO_ENABLE = yes
CAPS_WORD_ENABLE = yes

INTROSPECTION_KEYMAP_C = combos.c

ifneq ($(strip $(NO_SECRETS)), yes)
    ifneq ("$(wildcard $(USER_PATH)/secrets.c)","")
        SRC += secrets.c
    endif
endif

ifeq ($(strip $(AUDIO_ENABLE)), yes)
    SRC += muse.c
endif
