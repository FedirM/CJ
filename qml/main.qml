import QtQuick 2.11
import QtQuick.Window 2.2

QtObject{

    property var mainWindow: MainWindow{

    }

    property var splashScreen: SplashScreen{
        onTimeout: mainWindow.visible = true;
    }
}
