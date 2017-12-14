#!/bin/sh
LD_LIBRARY_PATH=/media/alex/DATA/QT/5.9.3/Src/qtbase/lib${LD_LIBRARY_PATH:+:$LD_LIBRARY_PATH}
export LD_LIBRARY_PATH
QT_PLUGIN_PATH=/media/alex/DATA/QT/5.9.3/Src/qtbase/plugins${QT_PLUGIN_PATH:+:$QT_PLUGIN_PATH}
export QT_PLUGIN_PATH
exec /media/alex/DATA/QT/5.9.3/Src/qtbase/bin/uic "$@"
