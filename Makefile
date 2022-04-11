.PHONY=all
all: test build build-example

.PHONY=test
test:
	carp -x test.carp

.PHONY=build
build:
	carp -b subprocess.carp

.PHONY=build-example
build-example:
	carp -b example.carp
