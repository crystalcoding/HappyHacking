import QtQuick 2.4

Item {

    id: button
    property string backColor
    property string borderColor
    property int borderWidth
    property int radius

    property string text
    property int fontSize
    property string textColor

    property bool hoverEnabled: false

    property string enteredColor
    property double enteredScale
    property string enteredBorderColor

    property string exitedColor
    property double exitedScale
    property string exitedBorderColor

    signal buttonClicked


    Rectangle {
        id: blueRec
        color: button.backColor
        width: rootRct.width/2
        height: rootRct.height/3
        border.color: button.borderColor
        border.width: button.borderWidth
        //x: 64
        //y: 64
        anchors.centerIn: rootRct
        radius: button.radius
        gradient: Gradient{
 //           GradientStop { position: 0.0; color: "lightsteelblue" }
 //                   GradientStop { position: 0.33; color: "yellow" }
//                    GradientStop { position: 1.0; color: "blue" }
        }
    }

    Text {
        id: fooText
        //width: 87
        //height: 24
        anchors.centerIn: blueRec
        text: button.text
        font.pixelSize: button.fontSize
        color: botton.textColor
        //anchors.verticalCenterOffset: -69
        //anchors.horizontalCenterOffset: 8
    }

    MouseArea {
        id: mouseArea
        anchors.fill: blueRec
        hoverEnabled: button.hoverEnabled

        onEntered: {
            blueRec.color = "red"
            blueRec.rotation = 45
            fooText.rotation = 45
            //fooText.color = "green"
            console.log(blueRec.color)
        }

        onExited: {
            blueRec.color = "green"
            blueRec.rotation = 0
            fooText.rotation = 0
            console.log(blueRec.color)
        }



        onClicked: {
            buttonClicked() //a function
        }
    }
}
