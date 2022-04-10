.PHONY=all
all: build test

.PHONY=test
test:
	carp -x test.carp

.PHONY=build
build:
	carp -b subprocess.carp
