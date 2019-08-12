import QtQuick 2.11
import QtQuick.Window 2.2
import QtQuick.Controls 2.2

import CJ 1.0

QtObject{

    property var mainWindow: MainWindow{

    }

    property var splashScreen: SplashScreen{
        onTimeout: mainWindow.visible = true;
    }


    property var errorWindow: ErrorWindow{

    }
}
