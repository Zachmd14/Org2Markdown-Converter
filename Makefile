CC       ?= cc
CFLAGS   ?= -std=c99 -Wall -Wextra -O2 -g
CPPFLAGS += -Iinclude
LDFLAGS  ?=

SRC_DIR   := src
INC_DIR   := include
BUILD_DIR := build

BIN := org2md

SRCS := $(wildcard $(SRC_DIR)/*.c)

OBJS := $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

DEPS := $(OBJS:.o=.d)

TEST_SRCS := $(wildcard tests/*.c)
TEST_BINS := $(TEST_SRCS:tests/%.c=$(BUILD_DIR)/tests/%)

LIB_OBJS := $(filter-out $(BUILD_DIR)/main.o,$(OBJS))

.PHONY: all clean test todo debug

all: $(BIN)

$(BIN): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $(OBJS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -MMD -MP -c $< -o $@

$(BUILD_DIR)/tests/%: tests/%.c $(LIB_OBJS)
	@mkdir -p $(BUILD_DIR)/tests
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $@ $< $(LIB_OBJS)

test: $(TEST_BINS)
	@for t in $(TEST_BINS); do \
		echo "== running $$t =="; \
		./$$t || exit 1; \
	done
	@echo "All tests passed."

clean:
	rm -rf $(BUILD_DIR) $(BIN)

debug:
	$(MAKE) clean
	$(MAKE) CFLAGS="-std=c99 -Wall -Wextra -O0 -g"

todo:
	@grep -rn -E "TODO|FIXME" $(SRC_DIR) $(INC_DIR) tests || echo "No TODO/FIXME markers found."

-include $(DEPS)
