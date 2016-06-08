# Points to the root of Google Mock, relative to where this file is.
# Remember to tweak this if you move this file.
ifndef VSPUT_DIR
VSPUT_DIR = ../../..
endif

GMOCK_DIR = $(VSPUT_DIR)/gmock
GTEST_DIR = $(GMOCK_DIR)/gtest
UT_MAKEFILE = $(VSPUT_DIR)/ci_gmock
#LIBGMOCK_DIR = ../../../ci_gmock
# Where to find user code.
SRC_DIR = ../../src
SRC_INCLUDE = ../../include
#SRC_CPD_FILES = $(SRC_DIR)/dgtcm0gx.cpd

TEST_DIR = ..
TEST_INCLUDE = $(TEST_DIR)/include

# All tests produced by this Makefile.  Remember to add new tests you
# created to the list.
TESTS = wjh_test

# Some sack files includes C++ keywords, such as class, operator, compl;
# Some struct types definded in sack, also declared in C\C++
# # Following command used to modify head files to rename names in sack
HEAD_SRC = $(TEST_INCLUDE)

#lcov configuration
ROOT_SRC = ../../src
LCOV_OPTION = -d $(ROOT_SRC)

include $(UT_MAKEFILE)/gmock.mk
head:$(HEAD_SRC)
	sed -i $(HEAD_SRC) -e 's/ class ;/ io_class ;/g' -e 's/ time_t ;/ dmx_ti    me_t;/g' -e 's/ operator ;/ dmx_operator ;/g'
	sed -i $(HEAD_SRC) -e 's/ compl ;/ dmx_compl ;/g'
	sed -i $(TEST_INCLUDE)/dxs/dxsprogx.cdt -e 's/ ACTION_P / DMX_ACTION_P /    g'

lib:$(UT_MAKEFILE)
	cd $(UT_MAKEFILE) && make

	
	
	
	
	
