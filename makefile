DIRS = junhuawang


all:build

build:$(DIRS)
	+make -C $(DIRS)

report:$(DIRS)
	+make report -C $(DIRS)

	
clean:
	+make clean -C $(DIRS)