import QtQuick 2.4
import QtQuick.Window 2.2
import QtQuick.Controls 1.2

Flickable{
    ListView {
        width: 100 ; height: 100
        model: myModel

        delegate: Rectangle {
            height: 25
            width: 600
            Text {text: modelData}
        }
    }
}
