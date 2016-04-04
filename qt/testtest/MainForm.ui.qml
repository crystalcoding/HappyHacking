import QtQuick 2.3
import QtQuick.Controls 1.2
import QtMultimedia 5.0

Rectangle {
    //property alias mouseArea: mouseArea

    width: 360
    height: 360

    Row {
        id: row1
        x: 41
        y: 42
        width: 276
        height: 293
    }

    Label {
        id: label1
        x: 89
        y: 115
        text: qsTr("Label")
    }

    Slider {
        id: sliderHorizontal1
        x: 89
        y: 163
        onValueChanged: label1.text = value
    }
}
