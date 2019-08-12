import QtQuick 2.10
import QtQuick.Controls 2.2
import QtQuick.Dialogs 1.3

import CJ 1.0

Item {
//    signal dialogClosed()

    property string dialogTitle: "Error"
    property int     dialogIcon: 3
    property string  dialogText: "Error message"
    property bool dialogVisible: false

    MessageDialog {
        id: messageDialog
        title   : dialogTitle
        icon    : dialogIcon
        text    : dialogText
        visible : dialogVisible
        modality: Qt.ApplicationModal
        onAccepted: Qt.quit(-1)
        onVisibleChanged: { if( !this.visible ) Qt.quit(-1); }
    }

    Connections{
        target: CJ
        onRepeatError:{
            dialogText = msg
            dialogVisible = true
        }
    }
}
