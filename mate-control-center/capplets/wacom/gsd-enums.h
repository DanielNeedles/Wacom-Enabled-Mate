/* We copy gsd-wacom-device from mate-settings-daemon.
 * It include "gsd-enums.h" because the include directory
 * is known. As mate-settings-daemon's pkg-config file
 * prefixes this, we need a little help to avoid this
 * one line difference */

#include <mate-settings-daemon/gsd-enums.h>
