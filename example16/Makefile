# =====================================
# Cross toolchain
# =====================================
CROSS    = arm-none-eabi-
CC       = $(CROSS)gcc
OBJCOPY  = $(CROSS)objcopy
SIZE     = $(CROSS)size

# =====================================
# Directories
# =====================================
BUILDDIR = build
SRCDIR   = src
INCDIR   = include

# =====================================
# Files
# =====================================
SOURCES  = $(SRCDIR)/main.c \
           $(SRCDIR)/uart.c \
           $(SRCDIR)/startup.c

OBJECTS  = $(BUILDDIR)/main.o \
           $(BUILDDIR)/uart.o \
           $(BUILDDIR)/startup.o

ELF      = $(BUILDDIR)/firmware.elf
BIN      = $(BUILDDIR)/firmware.bin
HEX      = $(BUILDDIR)/firmware.hex

# =====================================
# Flags
# =====================================
CFLAGS   = -I$(INCDIR) -Wall -Wextra -O2 -ffreestanding -mcpu=cortex-m4 -mthumb
LDFLAGS  = -T linker.ld -nostdlib -Wl,--gc-sections -mcpu=cortex-m4 -mthumb

# =====================================
# Default target
# =====================================
all: $(ELF)

# =====================================
# Build directory
# =====================================
$(BUILDDIR):
	mkdir -p $(BUILDDIR)

# =====================================
# Object files
# =====================================
$(BUILDDIR)/main.o: $(SRCDIR)/main.c | $(BUILDDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILDDIR)/uart.o: $(SRCDIR)/uart.c | $(BUILDDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILDDIR)/startup.o: $(SRCDIR)/startup.c | $(BUILDDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# =====================================
# Final ELF
# =====================================
$(ELF): $(OBJECTS)
	$(CC) $^ $(LDFLAGS) -o $@

# =====================================
# Extra output formats
# =====================================
$(BIN): $(ELF)
	$(OBJCOPY) -O binary $< $@

$(HEX): $(ELF)
	$(OBJCOPY) -O ihex $< $@

size: $(ELF)
	$(SIZE) $<

# Convenience target
extras: $(BIN) $(HEX) size

# Clean
clean:
	rm -rf $(BUILDDIR)

.PHONY: all clean size extras
