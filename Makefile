CC := clang -Wall
ARGS := -lSDL2main -lSDL2

SRC := src
OUT := out
TMP := $(OUT)/tmp
EXE := $(OUT)/main

SRCS := $(shell find $(SRC) -type f -name '*.c')
OBJS := $(patsubst $(SRC)/%.c, $(TMP)/%.o, $(SRCS))
ASMS := $(patsubst $(SRC)/%.c, $(TMP)/%.s, $(SRCS))
DEPS := $(patsubst %.o, %.d, $(OBJS))

.DEFAULT_GOAL := run
.PHONY: init run build asm clean
.PHONY: infoRun infoBuild infoAsm infoLink

init:
	mkdir -p $(SRC)

run: $(EXE) | infoRun
	@$(EXE)

build: $(EXE)

asm: $(ASMS) | infoAsm

clean:
	-$(RM) -r out/*

infoRun:
	$(info ******RUNNING******)

infoBuild:
	$(info ******BUILDING******)

infoAsm:
	$(info ******BUILDING ASM******)

infoLink:
	$(info ******LINKING******)

$(EXE): $(OBJS) | infoLink
	$(info $@)
	@$(CC) $^ -o $@ $(ARGS)

$(OBJS): $@ | infoBuild

-include $(DEPS)
$(TMP)/%.o: $(SRC)/%.c
	$(info $<)
	@mkdir -p $(@D)
	@$(CC) -MMD -c $< -o $@

$(TMP)/%.s: $(SRC)/%.c
	$(info $<)
	@mkdir -p $(@D)
	@$(CC) -MMD -S $< -o $@
