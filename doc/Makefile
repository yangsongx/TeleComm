# Makefile for build the book

FOP = /data/fop/fop-1.0/fop
FOP_XSL = /data/fop/docbook-xsl-1.74.0/fo/docbook.xsl

SIM_SRC = zh/sim.xml

sim:
	@echo "===== building SIM article  ====="
	$(FOP) -c ch_fop.conf \
		-xml $(SIM_SRC) \
		-param section.autolabel 1 \
		-param body.font.family SimSun \
		-param title.font.family SimSun \
		-param monospace.font.family SimSun \
		-xsl $(FOP_XSL) \
		-pdf $(SIM_SRC).pdf

