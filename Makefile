.PHONY: compile
compile:
	clang property1.c libs/libtheft.a -Iinc/ -o roman

.PHONY: clean
clean:
	rm -rf roman

.PHONY: test
test:
	./roman