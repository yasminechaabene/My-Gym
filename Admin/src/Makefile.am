## Process this file with automake to produce Makefile.in

INCLUDES = \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	@PACKAGE_CFLAGS@

bin_PROGRAMS = admin

admin_SOURCES = \
	main.c \
	support.c support.h \
	interface.c interface.h \
	callbacks.c callbacks.h \
	verifier.c verifier.h \
	personne.c personne.h \
	fiche.c fiche.h \
	seances_cures.c seances_cures.h \
	coaching.c coaching.h \
	offre.c offre.h \
	rdv.c rdv.h \
	consultm.c consultm.h \
	consultc.c consultc.h \
	seancec.c seancec.h \
	seancee.c seancee.h \
	event.c event.h

admin_LDADD = @PACKAGE_LIBS@ $(INTLLIBS)

