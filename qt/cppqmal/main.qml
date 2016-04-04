import QtQuick 2.4
import QtQuick.Window 2.2

Window {
    visible: true
    MainForm {
        anchors.fill: parent
        mouseArea.onClicked: {
            Qt.quit();
        }

    }

    Text {
        text: "This is where the app lives\n" + moviesPath
        anchors.centerIn: parent
    }
}
