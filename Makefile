# Master Makefile for Advanced C Foundry
# This Makefile is designed to orchestrate builds across the entire project.

.PHONY: all clean

# List of all sub-directories containing a Makefile
DIRS = \
    common \
    module-00-foundations \
    module-01-memory \
    module-02-performance \
    module-03-concurrency \
    project

# Default target: build everything
all: 
	@for dir in $(DIRS); do \
		$(MAKE) -C $$dir; \
		done

# Clean up all build artifacts
clean:
	@for dir in $(DIRS); do \
		$(MAKE) -C $$dir clean; \
		done
	@echo "Cleaned all modules and project."
