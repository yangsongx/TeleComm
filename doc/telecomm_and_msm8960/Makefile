# Makefile for telecom reference document
#
# [Usage]
# make tele  - create telecom reference pdf doc
# make pdf   - create MSM8960 pdf doc
#
#

HOST_CHECK = $(shell uname -n)
TARGET_BUILD_MACHINE = njred224 gaorong

OK_TO_BUILD = $(filter $(TARGET_BUILD_MACHINE),$(HOST_CHECK))

ifeq ($(OK_TO_BUILD),)
$(warning "The preferred doc build machine is $(TARGET_BUILD_MACHINE), the host is $(HOST_CHECK)")
endif

SRC=msm8960.xml
TELE_REF_SRC = tele_ref.xml

all:pdf html word

pdf:
	docbook2pdf $(SRC)
html:
	docbook2html --nochunks -o html_doc $(TELE_REF_SRC)
word:
	docbook2rtf $(SRC)
tele:
	@echo "Creating Index ..."
	docbook2html -o tmp/ -V html-index $(TELE_REF_SRC) >/dev/null 2>&1
	cp tmp/HTML.index ./
	./collateindex.pl -g -o the_index.xml HTML.index >/dev/null 2>&1
	docbook2pdf $(TELE_REF_SRC)
