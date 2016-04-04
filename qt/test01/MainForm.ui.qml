import QtQuick 2.3

Rectangle {
    width: 360
    height: 650



    Row {
        id: row1
        x: 71
        y: 92
        width: 200
        height: 400

        TextInput {
            id: textInput1

            width: 158
            height: 50
            text: qsTr("Text Input")
            font.pixelSize: 12
        }

        TextInput {
            id: textInput2

            width: 158
            height: 55
            text: qsTr("Text Input")
            font.pixelSize: 12
        }

        Text {
            id: text1

            width: 98
            height: 30
            text: qsTr("Name")
            font.pixelSize: 12
        }
    }
}
