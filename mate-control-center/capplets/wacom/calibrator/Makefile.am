# This is used in MATECC_CAPPLETS_CFLAGS
cappletname = wacom

AM_CPPFLAGS = 						\
	$(MATECC_CAPPLETS_CFLAGS)					\
	$(WACOM_MATECC_CAPPLETS_CFLAGS)				\
	-DMATELOCALEDIR="\"$(datadir)/locale\""	\
	$(NULL)


noinst_LTLIBRARIES = libwacom-calibrator.la libwacom-calibrator-test.la

libwacom_calibrator_la_SOURCES =	\
	calibrator.c			\
	calibrator.h			\
	calibrator-gui.c		\
	calibrator-gui.h		\
	cc-clock-actor.c		\
	cc-clock-actor.h		\
	cc-target-actor.c		\
	cc-target-actor.h

libwacom_calibrator_la_LIBADD = $(MATECC_CAPPLETS_LIBS) $(WACOM_MATECC_CAPPLETS_LIBS)
libwacom_calibrator_la_LDFLAGS = $(MATECC_CAPPLETS_LDFLAGS)

libwacom_calibrator_test_la_SOURCES = $(libwacom_calibrator_la_SOURCES)

libwacom_calibrator_test_la_CPPFLAGS = -DFAKE_AREA $(AM_CPPFLAGS)
libwacom_calibrator_test_la_LIBADD = $(libwacom_calibrator_la_LIBADD)
libwacom_calibrator_test_la_LDFLAGS = $(libwacom_calibrator_la_LDFLAGS)

noinst_PROGRAMS = test-calibrator

test_calibrator_SOURCES =		\
	main.c				\
	calibrator.c			\
	calibrator.h			\
	calibrator-gui.c		\
	calibrator-gui.h		\
	cc-clock-actor.c		\
	cc-clock-actor.h		\
	cc-target-actor.c		\
	cc-target-actor.h

test_calibrator_CPPFLAGS = $(AM_CPPFLAGS)
test_calibrator_LDADD = $(MATECC_CAPPLETS_LIBS) $(WACOM_MATECC_CAPPLETS_LIBS)

-include $(top_srcdir)/git.mk
