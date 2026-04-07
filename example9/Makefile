# example9/
# ├── Makefile
# ├── src/
# │   ├── main.c
# │   ├── app.c
# │   └── uart.c
# ├── include/
# │   ├── app.h
# │   └── uart.h
# └── build/
#     ├── debug/
#     └── release/
# =========================================================
# Project name
# =========================================================
PROJECT := demo_app

# =========================================================
# Directory layout
# =========================================================
SRC_DIR     := src
INC_DIR     := include
BUILD_DIR   := build

# =========================================================
# Build configuration
# Usage:
#   make
#   make CONFIG=release
#   make CROSS_COMPILE=arm-none-eabi-
# =========================================================
CONFIG ?= debug
CROSS_COMPILE ?=

# =========================================================
# Toolchain
# =========================================================
CC      := $(CROSS_COMPILE)gcc
AR      := $(CROSS_COMPILE)ar
OBJCOPY := $(CROSS_COMPILE)objcopy
SIZE    := $(CROSS_COMPILE)size
RM      := rm -rf
MKDIR_P := mkdir -p

# =========================================================
# Output directories depend on build config
# =========================================================
OBJ_DIR := $(BUILD_DIR)/$(CONFIG)/obj
BIN_DIR := $(BUILD_DIR)/$(CONFIG)/bin
DEP_DIR := $(BUILD_DIR)/$(CONFIG)/dep

TARGET  := $(BIN_DIR)/$(PROJECT)
ELF     := $(TARGET).elf
HEX     := $(TARGET).hex
BIN     := $(TARGET).bin

# =========================================================
# Source files
# =========================================================
SRCS := \
	$(SRC_DIR)/main.c \
	$(SRC_DIR)/app.c \
	$(SRC_DIR)/uart.c

# Convert src/foo.c -> build/debug/obj/src/foo.o
OBJS := $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRCS))
DEPS := $(patsubst $(OBJ_DIR)/%.o,$(DEP_DIR)/%.d,$(OBJS))

# =========================================================
# Common flags
# =========================================================
CPPFLAGS := -I$(INC_DIR)
CFLAGS   := -Wall -Wextra -Wpedantic -std=c11
LDFLAGS  :=
LDLIBS   :=

# =========================================================
# Config-specific flags
# =========================================================
ifeq ($(CONFIG),debug)
	CFLAGS += -O0 -g -DDEBUG
else ifeq ($(CONFIG),release)
	CFLAGS += -O2 -DNDEBUG
else
	$(error Unsupported CONFIG='$(CONFIG)'. Use debug or release)
endif

# # =========================================================
# # Example cross-compilation / embedded section
# # Uncomment and adapt for bare-metal ARM
# # =========================================================
ifneq ($(CROSS_COMPILE),)
	CFLAGS  += -mcpu=cortex-m4 -mthumb
	LDFLAGS += --specs=nosys.specs -mcpu=cortex-m4 -mthumb
endif

# =========================================================
# Default target
# =========================================================
.PHONY: all
all: $(ELF)

# =========================================================
# Link final ELF
# $@ = target
# $^ = all prerequisites
# =========================================================
$(ELF): $(OBJS) | $(BIN_DIR)
	@echo "LINK    $@"
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@
	@$(SIZE) $@

# =========================================================
# Optional binary formats
# Useful in embedded systems
# =========================================================
$(HEX): $(ELF)
	@echo "OBJCOPY $@"
	$(OBJCOPY) -O ihex $< $@

$(BIN): $(ELF)
	@echo "OBJCOPY $@"
	$(OBJCOPY) -O binary $< $@

# =========================================================
# Compile rule
# $< = first prerequisite
# $@ = target object
# $(@D) = target directory
# =========================================================
$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR) $(DEP_DIR)
	@echo "CC      $< -> $@"
	@$(MKDIR_P) $(@D) $(DEP_DIR)/$(dir $*)
	$(CC) $(CPPFLAGS) $(CFLAGS) -MMD -MP -MF $(DEP_DIR)/$*.d -c $< -o $@

# =========================================================
# Directory creation
# =========================================================
$(OBJ_DIR):
	@$(MKDIR_P) $@

$(BIN_DIR):
	@$(MKDIR_P) $@

$(DEP_DIR):
	@$(MKDIR_P) $@

# =========================================================
# Convenience targets
# =========================================================
.PHONY: clean
clean:
	@echo "CLEAN"
	$(RM) $(BUILD_DIR)

.PHONY: rebuild
rebuild: clean all

.PHONY: debug
debug:
	@$(MAKE) CONFIG=debug

.PHONY: release
release:
	@$(MAKE) CONFIG=release

.PHONY: hex
hex: $(HEX)

.PHONY: bin
bin: $(BIN)

.PHONY: run
run: $(ELF)
	@echo "RUN     $<"
	./$<

.PHONY: print
print:
	@echo "PROJECT       = $(PROJECT)"
	@echo "CONFIG        = $(CONFIG)"
	@echo "CROSS_COMPILE = $(CROSS_COMPILE)"
	@echo "CC            = $(CC)"
	@echo "CPPFLAGS      = $(CPPFLAGS)"
	@echo "CFLAGS        = $(CFLAGS)"
	@echo "LDFLAGS       = $(LDFLAGS)"
	@echo "LDLIBS        = $(LDLIBS)"
	@echo "SRCS          = $(SRCS)"
	@echo "OBJS          = $(OBJS)"
	@echo "DEPS          = $(DEPS)"
	@echo "ELF           = $(ELF)"
	@echo "HEX           = $(HEX)"
	@echo "BIN           = $(BIN)"

# =========================================================
# Include auto-generated dependency files
# =========================================================
-include $(DEPS)






#make
#make CONFIG=debug
#make CONFIG=release
#make CROSS_COMPILE=arm-none-eabi-
