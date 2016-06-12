DIRS = junhuawang \
       zorro


all:build

.PHONY:$(DIRS)

build:$(DIRS)

$(DIRS):
	+make -C $@

report:$(DIRS)
	+make report -C $(DIRS)

	
clean:
	+make clean -C zorro
	+make clean -C junhuawang