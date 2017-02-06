plugin_name = wacom

plugin_LTLIBRARIES = libmsdwacom.la

libmsdwacom_la_SOURCES =	\
	msd-wacom-plugin.c	\
	msd-wacom-manager.h	\
	msd-wacom-manager.c	\
	msd-wacom-key-shortcut-button.h	\
	msd-wacom-key-shortcut-button.c	\
	msd-wacom-button-editor.h	\
	msd-wacom-button-editor.c	\
	msd-wacom-osd-window.h	\
	msd-wacom-osd-window.c	\
	msd-wacom-oled.h	\
	msd-wacom-oled.c	\
	msd-wacom-oled-constants.h \
	msd-wacom-device.c	\
	msd-wacom-device.h	\
	msd-wacom-resources.c

libmsdwacom_la_CPPFLAGS = \
	-I$(top_srcdir)/mate-settings-daemon		\
	-I$(top_builddir)/mate-settings-daemon		\
	-I$(top_srcdir)/plugins/common/			\
	-I$(top_srcdir)/data/				\
	-DMATE_SETTINGS_LOCALEDIR=\""$(datadir)/locale"\" \
	-DLIBEXECDIR=\""$(libexecdir)"\" 		\
	$(AM_CPPFLAGS)

libmsdwacom_la_CFLAGS = \
	$(PLUGIN_CFLAGS)		\
	$(SETTINGS_PLUGIN_CFLAGS)	\
	$(WACOM_CFLAGS)			\
	$(AM_CFLAGS)

libmsdwacom_la_LDFLAGS =		\
	$(MSD_PLUGIN_LDFLAGS)

libmsdwacom_la_LIBADD  =						\
	$(top_builddir)/plugins/common/libcommon.la			\
	$(SETTINGS_PLUGIN_LIBS)						\
	$(WACOM_LIBS)

org.mate.settings-daemon.plugins.wacom.policy.in: org.mate.settings-daemon.plugins.wacom.policy.in.in Makefile
	$(AM_V_GEN) sed -e "s|\@libexecdir\@|$(libexecdir)|" $< > $@

msd-wacom-resources.c: wacom.gresource.xml tablet-layout.css
	glib-compile-resources 				\
		--target=$@ 				\
		--sourcedir=$(srcdir) 			\
		--generate-source 			\
		--c-name msd_wacom 			\
		$(srcdir)/wacom.gresource.xml

@INTLTOOL_POLICY_RULE@
polkit_policydir = $(datadir)/polkit-1/actions
polkit_policy_in_files = org.mate.settings-daemon.plugins.wacom.policy.in
polkit_policy_DATA = $(polkit_policy_in_files:.policy.in=.policy)

# so it always gets included in the tarball
msd_wacom_led_helper_SOURCES =	msd-wacom-led-helper.c
msd_wacom_oled_helper_SOURCES =	msd-wacom-oled-helper.c msd-wacom-oled-constants.h

EXTRA_DIST = $(msd_wacom_led_helper_SOURCES) wacom.gresource.xml tablet-layout.css \
	     $(msd_wacom_oled_helper_SOURCES)

# if HAVE_GUDEV
# libexec_PROGRAMS = msd-wacom-led-helper msd-wacom-oled-helper
# 
# msd_wacom_led_helper_LDFLAGS =				\
# 	$(BACKLIGHT_HELPER_LIBS)			\
# 	-lm
# 
# msd_wacom_oled_helper_LDFLAGS =				\
# 	$(WACOM_OLED_LIBS)				\
# 	-lm
# 
# msd_wacom_led_helper_CFLAGS =				\
# 	$(BACKLIGHT_HELPER_CFLAGS)
# 
# msd_wacom_oled_helper_CFLAGS =				\
# 	$(WACOM_OLED_CFLAGS)
# else
libexec_PROGRAMS =
# endif

EXTRA_DIST += org.mate.settings-daemon.plugins.wacom.policy.in.in

libexec_PROGRAMS += msd-test-wacom msd-list-wacom msd-test-wacom-osd

msd_test_wacom_SOURCES =	\
	test-wacom.c		\
	msd-wacom-manager.c	\
	msd-wacom-manager.h	\
	msd-wacom-key-shortcut-button.h	\
	msd-wacom-key-shortcut-button.c	\
	msd-wacom-button-editor.h	\
	msd-wacom-button-editor.c	\
	msd-wacom-osd-window.h	\
	msd-wacom-osd-window.c	\
	msd-wacom-oled.h	\
	msd-wacom-oled.c	\
	msd-wacom-device.c	\
	msd-wacom-device.h	\
	msd-wacom-resources.c

msd_test_wacom_CPPFLAGS = \
	-I$(top_srcdir)/data/					\
	-I$(top_srcdir)/mate-settings-daemon			\
	-I$(top_builddir)/mate-settings-daemon		\
	-I$(top_srcdir)/plugins/common				\
	-DBINDIR=\"$(bindir)\"					\
	-DPIXMAPDIR=\""$(pkgdatadir)"\"				\
	-DGTKBUILDERDIR=\""$(pkgdatadir)"\"			\
	-DMATE_SETTINGS_LOCALEDIR=\""$(datadir)/locale"\"	\
	-DLIBEXECDIR=\""$(libexecdir)"\"			\
	-DSCHEMA_NAME=\""msdwacom"\"				\
	$(AM_CPPFLAGS)

msd_test_wacom_CFLAGS =			\
	$(PLUGIN_CFLAGS)		\
	$(SETTINGS_PLUGIN_CFLAGS)	\
	$(WACOM_CFLAGS)			\
	$(AM_CFLAGS)

msd_test_wacom_LDADD =						\
	$(top_builddir)/mate-settings-daemon/libmsd.la		\
	$(top_builddir)/plugins/common/libcommon.la		\
	$(SETTINGS_DAEMON_LIBS)					\
	$(SETTINGS_PLUGIN_LIBS)					\
	$(WACOM_LIBS)						\
	-lm

msd_list_wacom_SOURCES =	\
	list-wacom.c		\
	msd-wacom-device.c	\
	msd-wacom-device.h

msd_list_wacom_CPPFLAGS =					\
	-I$(top_srcdir)/data/					\
	-I$(top_srcdir)/mate-settings-daemon			\
	-I$(top_builddir)/mate-settings-daemon			\
	-I$(top_srcdir)/plugins/common				\
	-DBINDIR=\"$(bindir)\"					\
	-DPIXMAPDIR=\""$(pkgdatadir)"\"				\
	-DGTKBUILDERDIR=\""$(pkgdatadir)"\"			\
	-DMATE_SETTINGS_LOCALEDIR=\""$(datadir)/locale"\"	\
	$(AM_CPPFLAGS)

msd_list_wacom_CFLAGS =			\
	$(SETTINGS_PLUGIN_CFLAGS)	\
	$(WACOM_CFLAGS)			\
	$(AM_CFLAGS)

msd_list_wacom_LDADD =						\
	$(top_builddir)/mate-settings-daemon/libmsd.la		\
	$(top_builddir)/plugins/common/libcommon.la		\
	$(SETTINGS_DAEMON_LIBS)					\
	$(SETTINGS_PLUGIN_LIBS)					\
	$(WACOM_LIBS)						\
	-lm

msd_test_wacom_osd_SOURCES =					\
	test-osd-window.c					\
	msd-wacom-key-shortcut-button.h				\
	msd-wacom-key-shortcut-button.c				\
	msd-wacom-button-editor.h				\
	msd-wacom-button-editor.c				\
	msd-wacom-osd-window.h					\
	msd-wacom-osd-window.c					\
	msd-wacom-device.c					\
	msd-wacom-device.h					\
	msd-wacom-resources.c

msd_test_wacom_osd_CPPFLAGS = \
	-I$(top_srcdir)/data/					\
	-I$(top_srcdir)/mate-settings-daemon			\
	-I$(top_builddir)/mate-settings-daemon			\
	-I$(top_srcdir)/plugins/common				\
	-DBINDIR=\"$(bindir)\"					\
	-DPIXMAPDIR=\""$(pkgdatadir)"\"				\
	-DGTKBUILDERDIR=\""$(pkgdatadir)"\"			\
	-DMATE_SETTINGS_LOCALEDIR=\""$(datadir)/locale"\"	\
	-DLIBEXECDIR=\""$(libexecdir)"\"			\
	$(AM_CPPFLAGS)

msd_test_wacom_osd_CFLAGS =					\
	$(SETTINGS_PLUGIN_CFLAGS)				\
	$(WACOM_CFLAGS)						\
	$(AM_CFLAGS)

msd_test_wacom_osd_LDADD = \
	$(top_builddir)/mate-settings-daemon/libmsd.la		\
	$(top_builddir)/plugins/common/libcommon.la		\
	$(SETTINGS_DAEMON_LIBS)					\
	$(SETTINGS_PLUGIN_LIBS)					\
	$(WACOM_LIBS)						\
	-lm

plugin_in_files = wacom.mate-settings-plugin.in

plugin_DATA = $(plugin_in_files:.mate-settings-plugin.in=.mate-settings-plugin)

EXTRA_DIST += $(plugin_in_files) README.config-storage
CLEANFILES =						\
	$(plugin_DATA)					\
	msd-wacom-resources.c				\
	org.mate.settings-daemon.plugins.wacom.policy	\
	org.mate.settings-daemon.plugins.wacom.policy.in

@MSD_INTLTOOL_PLUGIN_RULE@
