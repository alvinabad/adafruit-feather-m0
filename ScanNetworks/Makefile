# Creat a symlink to this Makefile from a project directory

# Set projects here
PROJECTS	:= ScanNetworks Blink

PLATFORM_INI		:= $(wildcard platformio.ini)
BOARD_ID_FILE		:= $(wildcard BOARD_ID)

.PHONY:	all \
	help \
	create \
	compile \
	compiledb \
	upload \
	list-targets \
	list-boards \
	$(PROJECT_NAME) \
	$(PROJECTS) \
	clean

help:
	@echo "Usage:"
    ifeq ($(PLATFORM_INI),)
	@echo "    make PROJECT_NAME=projectname create"
	@echo "    make list-boards"
    else
	@echo "    make all"
	@echo "    make compile"
	@echo "    make compiledb"
	@echo "    make upload"
	@echo "    make list-targets"
	@echo "    make clean"
    endif

all:
    ifneq ($(PLATFORM_INI),)
	make clean compile upload
    endif

list-boards:
    ifeq ($(PLATFORM_INI),)
	pio boards
    endif

create:
    ifneq ($(PLATFORM_INI),)
	@echo Project already exists
    else
	@mkdir $(PROJECT_NAME)
	cd $(PROJECT_NAME) && \
		ln -sf ../Makefile && \
		pio project init --board `grep -v '^#' ../BOARD_ID` 
	@echo
	@echo Project '$(PROJECT_NAME)' created
	@echo "    cd to $(PROJECT_NAME)/ and run make"
    endif

compile:
    ifneq ($(PLATFORM_INI),)
	pio run
    endif

compiledb:
    ifneq ($(PLATFORM_INI),)
	pio run --target $@
    endif

upload:
    ifneq ($(PLATFORM_INI),)
	pio run --target $@
    endif

list-targets:
    ifneq ($(PLATFORM_INI),)
	pio run --list-targets
    endif

clean:
    ifneq ($(PLATFORM_INI),)
	pio run --target clean
    else
	@for app in $(PROJECTS); do \
	    make -C $$app $@; \
	done
    endif
