.PHONY: all clean

OBJS := queue.o bfs_traversal.o
TEST_OBJS := bfs_test.o queue_tests.o
TARGET := bfs
TEST_TARGET := bfs_test

CFLAGS := -g

all: tests

clean:
	rm -f $(OBJS) $(TEST_OBJS) main.o $(TEST_TARGET) $(TARGET)

tests: $(TARGET) $(TEST_TARGET)
	./$(TEST_TARGET)

$(TARGET): main.o $(OBJS)
	$(CC) main.o $(OBJS) $(LDFLAGS) -o $@

$(TEST_TARGET): $(TEST_OBJS) $(OBJS)
