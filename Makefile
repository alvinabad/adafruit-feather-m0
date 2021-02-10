# Creat a symlink to this Makefile from a project directory

# Set projects here
PROJECTS	:= Blink BlinkRelay

PLATFORMIO_INI		:= $(wildcard platformio.ini)

.PHONY:	all \
	compile \
	upload \
	list-targets \
	$(PROJECTS) \
	clean

all:
	@echo "Run this from a project directory."
	@echo "Usage:"
	@echo "    make compile"
	@echo "    make compiledb"
	@echo "    make upload"
	@echo "    make list-targets"
	@echo "    make clean"

compile:
    ifneq ($(PLATFORMIO_INI),)
	pio run
    else
	@for app in $(PROJECTS); do \
	    make -C $$app $@; \
	done
    endif

compiledb:
    ifneq ($(PLATFORMIO_INI),)
	pio run --target $@
    else
	@for app in $(PROJECTS); do \
	    make -C $$app $@; \
	done
    endif

upload:
    ifneq ($(PLATFORMIO_INI),)
	pio run --target $@
    else
	@echo cd to project and run make $@
    endif

list-targets:
    ifneq ($(PLATFORMIO_INI),)
	pio run --list-targets
    else
	@echo cd to project and run make $@
    endif

clean:
    ifneq ($(PLATFORMIO_INI),)
	pio run --target clean
    else
	@for app in $(PROJECTS); do \
	    make -C $$app $@; \
	done
    endif
