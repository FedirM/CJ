import QtQuick 2.0
import QtQuick.Window 2.2
import QtQuick.Controls 2.2

import CJ 1.0

Window {
    id: splashWindow
    signal timeout()
    width: 300
    height: 200
    modality: Qt.ApplicationModal
    flags: Qt.SplashScreen
    color: "#00000000"

    CJ{
        id: cjController
    }

    Image {
        id: logo
        source: "qrc:/img/mova_logo.png"
        anchors.centerIn: parent
    }

    ProgressBar {
        id: progress
        anchors {
            left: parent.left
            right: parent.right
            bottom: parent.bottom
        }
        value: 0.0
        to : 100.0
        from : 0.0

        Connections{
            target: cjController
            onRepeatPercent: {
                progress.value = percent;
                console.log("Get new percent: ", percent);
            }
            onRepeatFinished:{
                console.log("FINISH...."); console.log("Switch to main window.");
                splashWindow.visible = false;
                timeout();
            }
        }
    }

    Component.onCompleted: {
        splashWindow.visible = true;
        console.log("Splash screen completed....");
        cjController.runLoader();
        console.log("Loading....");
    }
}
