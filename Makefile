.PHONY=all
all: test build build-example

.PHONY=test
test:
	MallocNanoZone=0 carp -x tests.carp

.PHONY=build
build:
	carp -b subprocess.carp

.PHONY=build-example
build-example:
	carp -b example.carp
